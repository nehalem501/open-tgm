/* N3DSGPU.h - 3DS */

#ifndef N3DS_GPU_3DS_H
#define N3DS_GPU_3DS_H

#include <Size.h>
#include <GPU.h>

// These headers are generated by the build process
#include <shaders/shader2d.shbin.h>
//#include <shader3d.shbin.h>

class N3DSGPU : public GPU {
    public:
        N3DSGPU(Size& screen);
        ~N3DSGPU();

        void clear();
        void display();

    private:
        C3D_RenderTarget *target;

        DVLB_s *shader2d_dvlb;
        // DVLB_s *shader3d_dvlb;

        shaderProgram_s program_2d;
        // shaderProgram_s program_3d;

        int proj_uloc_2d;
        // int proj_uloc_3d;

        C3D_Mtx proj_mat;
};

#endif // N3DS_GPU_3DS_H