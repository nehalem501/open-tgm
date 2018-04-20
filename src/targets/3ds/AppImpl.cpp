/* AppImpl.cpp - 3DS */

#include <3ds.h>
#include <citro3d.h>
#include <Global.h>
#include <MainMenu.h>
#include <Background.h>
#include "lodepng.h"
#include <App.h>

// These headers are generated by the build process
#include <vshader.shbin.h>
#include <empty.png.h>
#include <background.png.h>
#include <frame.png.h>
#include <ui_font.png.h>
#include <tileset.png.h>
#include <outline.png.h>

#include <stdio.h>

#define DISPLAY_TRANSFER_FLAGS \
	(GX_TRANSFER_FLIP_VERT(0) | GX_TRANSFER_OUT_TILED(0) | GX_TRANSFER_RAW_COPY(0) | \
	GX_TRANSFER_IN_FORMAT(GX_TRANSFER_FMT_RGBA8) | GX_TRANSFER_OUT_FORMAT(GX_TRANSFER_FMT_RGB8) | \
    GX_TRANSFER_SCALING(GX_TRANSFER_SCALE_NO))

#define TEXTURE_TRANSFER_FLAGS \
	(GX_TRANSFER_FLIP_VERT(1) | GX_TRANSFER_OUT_TILED(1) | GX_TRANSFER_RAW_COPY(0) | \
	GX_TRANSFER_IN_FORMAT(GX_TRANSFER_FMT_RGBA8) | GX_TRANSFER_OUT_FORMAT(GX_TRANSFER_FMT_RGBA8) | \
	GX_TRANSFER_SCALING(GX_TRANSFER_SCALE_NO))

static DVLB_s *vshader_dvlb;
static shaderProgram_s program;
static int proj_uloc;
static C3D_Mtx proj_mat;

C3D_Tex empty_tex;
C3D_Tex background_tex;
C3D_Tex tileset_tex;
C3D_Tex outline_tex;
C3D_Tex frame_tex;
//C3D_Tex digits_tex;
//C3D_Tex labels_tex;
C3D_Tex text_tex;
//C3D_Tex grades_tex;
//C3D_Tex timer_tex;

void convert_endianess(u8 *destination, u8 *source, unsigned int length) {
	u8 *src = source;
	u8 *dst = destination;

	for(unsigned int i = 0; i < length; i++) {
		int r = *src++;
		int g = *src++;
		int b = *src++;
		int a = *src++;

		*dst++ = a;
		*dst++ = b;
		*dst++ = g;
		*dst++ = r;
	}
}

void load_texture(C3D_Tex *tex, const u8 *img, const u32 img_size) {
	unsigned int width, height;
	u8* image;

	lodepng_decode32(&image, &width, &height, img, img_size);

	u8 *gpusrc = (u8 *) linearAlloc(width * height * 4);

	// lodepng outputs big endian rgba so we need to convert
	convert_endianess(gpusrc, image, width * height);

	// ensure data is in physical ram
	GSPGPU_FlushDataCache(gpusrc, width * height * 4);

	// Load the texture and bind it to the first texture unit
	C3D_TexInit(tex, width, height, GPU_RGBA8);

	// Convert image to 3DS tiled texture format
	C3D_SafeDisplayTransfer ((u32*)gpusrc, GX_BUFFER_DIM(width, height), (u32*) tex->data, GX_BUFFER_DIM(width, height), TEXTURE_TRANSFER_FLAGS);
	gspWaitForPPF();

	C3D_TexSetFilter(tex, GPU_LINEAR, GPU_NEAREST);

	free(image);
	linearFree(gpusrc);
}

void init_gpu_stuff() {
	// Load the vertex shader, create a shader program and bind it
	vshader_dvlb = DVLB_ParseFile((u32*) vshader_shbin, vshader_shbin_size);
	shaderProgramInit(&program);
	shaderProgramSetVsh(&program, &vshader_dvlb->DVLE[0]);
	C3D_BindProgram(&program);

	// Get the location of the uniforms
	proj_uloc = shaderInstanceGetUniformLocation(program.vertexShader, "projection");

	// Configure attributes for use with the vertex shader
	// Attribute format and element count are ignored in immediate mode
	C3D_AttrInfo* attrInfo = C3D_GetAttrInfo();
	AttrInfo_Init(attrInfo);
	AttrInfo_AddLoader(attrInfo, 0, GPU_FLOAT, 3); // v0=position
	AttrInfo_AddLoader(attrInfo, 1, GPU_FLOAT, 2); // v1=texcoord
	AttrInfo_AddLoader(attrInfo, 2, GPU_FLOAT, 4); // v2=color

	// Compute the projection matrix
	// Note: we're setting top to 240 here so origin is at top left.
	Mtx_OrthoTilt(&proj_mat, 0.0, 400.0, 240.0, 0.0, 0.0, 1.0, true);

	// Configure buffers
	C3D_BufInfo* bufInfo = C3D_GetBufInfo();
	BufInfo_Init(bufInfo);

	// Load textures
	load_texture(&background_tex, background_png, background_png_size);
	load_texture(&empty_tex, empty_png, empty_png_size);
	load_texture(&frame_tex, frame_png, frame_png_size);
	load_texture(&text_tex, ui_font_png, ui_font_png_size);
	load_texture(&tileset_tex, tileset_png, tileset_png_size);
	load_texture(&outline_tex, outline_png, outline_png_size);

	// Configure the first fragment shading substage to just pass through the texture color
	// See https://www.opengl.org/sdk/docs/man2/xhtml/glTexEnv.xml for more insight
	C3D_TexEnv* env = C3D_GetTexEnv(0);
	C3D_TexEnvSrc(env, C3D_Both, GPU_TEXTURE0, GPU_PRIMARY_COLOR, 0);
	//C3D_TexEnvSrc(env, C3D_Both, GPU_TEXTURE0, 0, 0);

	C3D_TexEnvOp(env, C3D_Both, 0, 0, 0);
	C3D_TexEnvFunc(env, C3D_Both, GPU_MODULATE);
	//C3D_TexEnvFunc(env, C3D_Both, GPU_REPLACE);

	// Configure depth test to overwrite pixels with the same depth (needed to draw overlapping sprites)
	C3D_DepthTest(true, GPU_GEQUAL, GPU_WRITE_ALL);

	C3D_FVUnifMtx4x4(GPU_VERTEX_SHADER, proj_uloc, &proj_mat);
}

void end_gpu_stuff() {
	// Free the shader program
	shaderProgramFree(&program);
	DVLB_Free(vshader_dvlb);
}

void app() {
    gfxInitDefault();
    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);

    // Initialize the render target
    C3D_RenderTarget *target = C3D_RenderTargetCreate(240, 400, GPU_RB_RGBA8, GPU_RB_DEPTH24_STENCIL8);
    C3D_RenderTargetSetClear(target, C3D_CLEAR_ALL, 0x000000FF, 0);
    C3D_RenderTargetSetOutput(target, GFX_TOP, GFX_LEFT, DISPLAY_TRANSFER_FLAGS);

    init_gpu_stuff();

	//consoleInit(GFX_BOTTOM, NULL);

    // Main loop
    while (aptMainLoop()) {
        hidScanInput(); // Refresh Inputs

        // Process one frame
        menu.update();

        // Draw
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C3D_FrameDrawOn(target);

        background.draw();
        menu.draw();

		C3D_FrameEnd(0);
    }

	end_gpu_stuff();

	// Deinitialize graphics
    C3D_Fini();
    gfxExit();
}
