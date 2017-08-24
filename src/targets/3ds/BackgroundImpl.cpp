/* BackgroundImpl.cpp - 3DS */

#include <3ds.h>
#include <citro3d.h>
#include "Global3DS.h"
#include "BackgroundImpl.h"

void BackgroundImpl::initGraphics() {
}

void BackgroundImpl::draw() const {
    if (options) {
        // Draw settings background
    } else {
        // Draw game background
        C3D_TexBind(0, &background_tex);

        C3D_ImmDrawBegin(GPU_TRIANGLE_STRIP);

        C3D_ImmSendAttrib(0.0f, 0.0f, 0.5f, 0.0f);
        C3D_ImmSendAttrib(0.0f, 0.0f, 0.0f, 0.0f);
        C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 1.0f);

        C3D_ImmSendAttrib(0.0f, 240.0f, 0.5f, 0.0f);
        C3D_ImmSendAttrib(0.0f, 240.0f / 256.0f, 0.0f, 0.0f);
        C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 1.0f);

        C3D_ImmSendAttrib(400.0f, 0.0f, 0.5f, 0.0f);
        C3D_ImmSendAttrib(400.0f / 512.0f, 0.0f, 0.0f, 0.0f);
        C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 1.0f);

        C3D_ImmSendAttrib(400.0f, 240.0f, 0.5f, 0.0f);
        C3D_ImmSendAttrib(400.0f / 512.0f, 240.0f / 256.0f, 0.0f, 0.0f);
        C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 1.0f);

        C3D_ImmDrawEnd();
    }
}
