/* GPU.h - GPU */

#ifndef GPU_HEADER_H
#define GPU_HEADER_H

#include "FontManager.h"

class GPU {
    public:
        virtual ~GPU() = 0;

        virtual void clear() = 0;
        virtual void display() = 0;

        #ifdef RESIZABLE
        bool resize(unsigned int width, unsigned int height);
        #endif

        void load_textures();

        const Texture& get_texture(TextureID id) const;
        Texture& get_texture_mut(TextureID id);

        static const GPU& get_current() { return get_current_mut(); }
        static GPU& get_current_mut();
        static void set_current(GPU* gpu);

    private:
        void load_texture(Texture& texture, const uint8_t* data, const size_t data_size);
        void load_generated_texture(
            const TextureID id,
            const uint8_t format,
            unsigned int texture_tile_size,
            unsigned int width,
            unsigned int height,
            const uint8_t* data,
            const size_t data_size);

        virtual void alloc_texture(Texture& texture, const uint8_t* data, const size_t data_size) = 0;
        virtual void free_texture(Texture& texture) = 0;

        void load_simple_textures();
        void load_generated_textures();

        void load_empty_default_data();

        #ifdef RESIZABLE
        void resize_textures();
        virtual void resize(unsigned int width, unsigned int height, unsigned int new_tile_size) = 0;
        #endif

        Texture m_textures[(size_t) TextureID::NB_TEXTURES];
};

#endif // GPU_HEADER_H
