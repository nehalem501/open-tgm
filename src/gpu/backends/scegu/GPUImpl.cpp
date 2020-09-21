/* GPUImpl.h - SCEGU */

#include <Texture.h>
#include <GPUImpl.h>
#include <pspsdk.h>

#define BUF_WIDTH 512
#define SCR_WIDTH 480
#define SCR_HEIGHT 272

static unsigned int static_vram_offset = 0;

static void* get_vram_offset_bytes(unsigned int mem_size) {
    void* result = (void*) static_vram_offset;
    static_vram_offset += mem_size;

    return result;
}

static void* get_vram_offset_image(int width, int height, int format) {
    unsigned int mem_size;
    switch (format) {
        case GU_PSM_4444:
            mem_size = 2 * width * height;
            break;

        case GU_PSM_8888:
            mem_size = 4 * width * height;
            break;
    }

    return get_vram_offset_bytes(mem_size);
}

static unsigned int __attribute__((aligned(16))) list[262144];

void init_gpu() {
    void* fbp0 = get_vram_offset_image(BUF_WIDTH, SCR_HEIGHT, GU_PSM_8888);
    void* fbp1 = get_vram_offset_image(BUF_WIDTH, SCR_HEIGHT, GU_PSM_8888);
    void* zbp = get_vram_offset_image(BUF_WIDTH, SCR_HEIGHT, GU_PSM_4444);

    sceGuInit();
	sceGuStart(GU_DIRECT, list);

    sceGuDrawBuffer(GU_PSM_8888, fbp0, BUF_WIDTH);
    sceGuDispBuffer(SCR_WIDTH, SCR_HEIGHT, fbp1, BUF_WIDTH);
    sceGuDepthBuffer(zbp, BUF_WIDTH);

    sceGuOffset(2048 - (SCR_WIDTH / 2), 2048 - (SCR_HEIGHT / 2));
    sceGuViewport(2048, 2048, SCR_WIDTH, SCR_HEIGHT);

    sceGuDepthRange(65535, 0);
    sceGuClearDepth(65535);
    sceGuDepthFunc(GU_LEQUAL);

    sceGuAlphaFunc(GU_GREATER, 0, 255);
    sceGuBlendFunc(GU_ADD, GU_SRC_ALPHA, GU_ONE_MINUS_SRC_ALPHA, 0, 0);
    sceGuTexFunc(GU_TFX_MODULATE, GU_TCC_RGBA);
    sceGuTexFilter(GU_LINEAR, GU_LINEAR);
    sceGuShadeModel(GU_SMOOTH);

    sceGuEnable(GU_DEPTH_TEST);
    sceGuEnable(GU_ALPHA_TEST);
    sceGuEnable(GU_SCISSOR_TEST);
    sceGuEnable(GU_BLEND);

    sceGuDisable(GU_CULL_FACE);
    sceGuDisable(GU_CLIP_PLANES);
    sceGuDisable(GU_DITHER);

    sceGuScissor(0, 0, SCR_WIDTH, SCR_HEIGHT);

    sceGuFinish();
    sceGuSync(0, 0);

    sceDisplayWaitVblankStart();
    sceGuDisplay(GU_TRUE);
}

void free_gpu() {
    sceGuDisplay(GU_FALSE);
    sceGuTerm();
}

void graphics_clear() {
    // Start recording graphic commands for this frame
    sceGuStart(GU_DIRECT, list);

    // Clear screen
    sceGuClearColor(0xff0000ff);
    sceGuClearDepth(0);
    sceGuClear(GU_COLOR_BUFFER_BIT | GU_DEPTH_BUFFER_BIT);
}

void graphics_display() {
    // Flush command buffer
    sceGuFinish();
    sceGuSync(0,0);

    // Swap buffers and wait for VSYNC
    sceDisplayWaitVblankStart();
    sceGuSwapBuffers();
}
