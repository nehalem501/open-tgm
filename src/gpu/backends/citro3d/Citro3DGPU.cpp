/* Citro3DGPU.cpp - citro3d */

#include "lib3ds.h"
#include <Global.h>
#include <Texture.h>
#include <Citro3DGPU.h>

#define DISPLAY_TRANSFER_FLAGS \
    (GX_TRANSFER_FLIP_VERT(0) | GX_TRANSFER_OUT_TILED(0) | GX_TRANSFER_RAW_COPY(0) | \
    GX_TRANSFER_IN_FORMAT(GX_TRANSFER_FMT_RGBA8) | GX_TRANSFER_OUT_FORMAT(GX_TRANSFER_FMT_RGB8) | \
    GX_TRANSFER_SCALING(GX_TRANSFER_SCALE_NO))

#define TEXTURE_TRANSFER_FLAGS \
    (GX_TRANSFER_FLIP_VERT(1) | GX_TRANSFER_OUT_TILED(1) | GX_TRANSFER_RAW_COPY(0) | \
    GX_TRANSFER_IN_FORMAT(GX_TRANSFER_FMT_RGBA8) | GX_TRANSFER_OUT_FORMAT(GX_TRANSFER_FMT_RGBA8) | \
    GX_TRANSFER_SCALING(GX_TRANSFER_SCALE_NO))

Citro3DGPU::Citro3DGPU(Size& screen) {
    gfxInitDefault();

    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);

    // Initialize the render target
    target = C3D_RenderTargetCreate(
        screen.height, // Swapped because framebuffer is rotated 90°
        screen.width,
        GPU_RB_RGBA8,
        GPU_RB_DEPTH24_STENCIL8);
    C3D_RenderTargetSetOutput(target, GFX_TOP, GFX_LEFT, DISPLAY_TRANSFER_FLAGS);

    // TODO: 3D
    // Load the vertex shader, create a shader program and bind it
    /*shader3d_dvlb = DVLB_ParseFile((u32*) shader3d_shbin, shader3d_shbin_size);
    shaderProgramInit(&program_3d);
    shaderProgramSetVsh(&program_3d, &shader3d_dvlb->DVLE[0]);
    C3D_BindProgram(&program_3d);

    // Get the location of the uniforms
    proj_uloc_3d = shaderInstanceGetUniformLocation(program_3d.vertexShader, "projection");

    // Configure attributes for use with the vertex shader
    // Attribute format and element count are ignored in immediate mode
    C3D_AttrInfo* attrInfo = C3D_GetAttrInfo();
    AttrInfo_Init(attrInfo);
    AttrInfo_AddLoader(attrInfo, 0, GPU_FLOAT, 3); // v0=position
    AttrInfo_AddLoader(attrInfo, 1, GPU_FLOAT, 2); // v1=texcoord
    AttrInfo_AddLoader(attrInfo, 2, GPU_FLOAT, 4); // v2=color*/

    // Load the vertex shader, create a shader program and bind it
    shader2d_dvlb = DVLB_ParseFile((u32*) shader2d_shbin, shader2d_shbin_size);
    shaderProgramInit(&program_2d);
    shaderProgramSetVsh(&program_2d, &shader2d_dvlb->DVLE[0]);
    C3D_BindProgram(&program_2d);

    // Get the location of the uniforms
    proj_uloc_2d = shaderInstanceGetUniformLocation(program_2d.vertexShader, "projection");

    // Configure attributes for use with the vertex shader
    // Attribute format and element count are ignored in immediate mode
    C3D_AttrInfo* attrInfo = C3D_GetAttrInfo();
    AttrInfo_Init(attrInfo);
    AttrInfo_AddLoader(attrInfo, 0, GPU_FLOAT, 2); // v0=position
    AttrInfo_AddLoader(attrInfo, 1, GPU_FLOAT, 2); // v1=texcoord
    AttrInfo_AddLoader(attrInfo, 2, GPU_FLOAT, 4); // v2=color

    // Compute the projection matrix
    // Note: we're setting top to 240 here so origin is at top left.
    Mtx_OrthoTilt(&proj_mat, 0.0, (float) screen.width, (float) screen.height, 0.0, 0.0, 1.0, true);

    // Configure the first fragment shading substage to just pass through the texture color
    // See https://www.opengl.org/sdk/docs/man2/xhtml/glTexEnv.xml for more insight
    C3D_TexEnv* env = C3D_GetTexEnv(0);
    C3D_TexEnvSrc(env, C3D_Both, GPU_TEXTURE0, GPU_PRIMARY_COLOR, (GPU_TEVSRC) 0);
    C3D_TexEnvFunc(env, C3D_Both, GPU_MODULATE);

    // Configure depth test to overwrite pixels with the same depth (needed to draw overlapping sprites)
    C3D_DepthTest(true, GPU_GEQUAL, GPU_WRITE_ALL);

    //C3D_FVUnifMtx4x4(GPU_VERTEX_SHADER, proj_uloc_3d, &proj_mat);
    C3D_FVUnifMtx4x4(GPU_VERTEX_SHADER, proj_uloc_2d, &proj_mat);
}

Citro3DGPU::~Citro3DGPU() {
    // Free the shader program

    // TODO: 3D
    //shaderProgramFree(&program_3d);
    //DVLB_Free(shader3d_dvlb);

    shaderProgramFree(&program_2d);
    DVLB_Free(shader2d_dvlb);

    C3D_Fini();

    gfxExit();
}

void Citro3DGPU::clear() {
    C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
    C3D_RenderTargetClear(target, C3D_CLEAR_ALL, 0x00FF00FF, 0);
    C3D_FrameDrawOn(target);
}

void Citro3DGPU::display() {
    C3D_FrameEnd(0);
}

static void convert_endianess(u8 *destination, const u8 *source, unsigned int length) {
    const u8 *src = source;
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

static inline GPU_TEXCOLOR to_3ds_texture_format(uint8_t format) {
    switch (format) {
        case TexturesFormat::RGBA8: return GPU_RGBA8;
        case TexturesFormat::RGB8: return GPU_RGB8;
        case TexturesFormat::RGBA5551: return GPU_RGBA5551;
        case TexturesFormat::RGB565: return GPU_RGB565;
        case TexturesFormat::LA8: return GPU_LA8;
        case TexturesFormat::L8: return GPU_L8;
        case TexturesFormat::A8: return GPU_A8;
        case TexturesFormat::LA4: return GPU_LA4;
        case TexturesFormat::L4: return GPU_L4;
        case TexturesFormat::A4: return GPU_A4;
        case TexturesFormat::ETC1: return GPU_ETC1;
    }

    // TODO: error
    return GPU_RGBA8;
}

void Citro3DGPU::alloc_texture(Texture& texture, const uint8_t* data, const size_t) {
    //C3D_TexInit(&texture.handle, texture.width, texture.height, to_3ds_texture_format(texture.format));
    //C3D_TexUpload(&texture.handle, img_data);

    //u8* image;

    //lodepng_decode32(&image, &texture.width, &texture.height, ui_font, ui_font_size);

    u8 *gpusrc = (u8 *) linearAlloc(texture.width() * texture.height() * 4);

    // lodepng outputs big endian rgba so we need to convert
    // TODO img2tx tool should do this
    convert_endianess(gpusrc, /*image*/data, texture.width() * texture.height());
    //memcpy(gpusrc, /*image*/img_data, texture.width * texture.height * 4);

    // ensure data is in physical ram
    GSPGPU_FlushDataCache(gpusrc, texture.width() * texture.height() * 4);

    // Load the texture and bind it to the first texture unit
    C3D_TexInit(texture.handle_ptr_mut(), texture.width(), texture.height(), to_3ds_texture_format(texture.format()));

    // Convert image to 3DS tiled texture format
    C3D_SyncDisplayTransfer(
        (u32*) gpusrc,
        GX_BUFFER_DIM(texture.width(), texture.height()),
        (u32*) texture.handle_ptr()->data,
        GX_BUFFER_DIM(texture.width(), texture.height()),
        TEXTURE_TRANSFER_FLAGS);

    C3D_TexSetFilter(texture.handle_ptr_mut(), GPU_LINEAR, GPU_NEAREST);

    linearFree(gpusrc);
}

void Citro3DGPU::free_texture(Texture& texture) {
    C3D_TexDelete(texture.handle_ptr_mut());
}

