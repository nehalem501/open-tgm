/* GPUImpl.cpp - 3DS */

#include "lib3ds.h"
#include <Global.h>
#include <Texture.h>
#include <GPUImpl.h>

// These headers are generated by the build process
#include <shaders/shader2d.shbin.h>
//#include <shader3d.shbin.h>

static DVLB_s *shader2d_dvlb;
//static DVLB_s *shader3d_dvlb;

static shaderProgram_s program_2d;
//static shaderProgram_s program_3d;
static int proj_uloc_2d;
//static int proj_uloc_3d;
static C3D_Mtx proj_mat;

void init_gpu() {
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

void free_gpu() {
    // Free the shader program

    // TODO: 3D
    //shaderProgramFree(&program_3d);
    //DVLB_Free(shader3d_dvlb);

    shaderProgramFree(&program_2d);
    DVLB_Free(shader2d_dvlb);
}
