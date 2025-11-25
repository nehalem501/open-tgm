/* TextureDataManager.h - GPU */

#ifndef GPU_TEXTURE_DATA_MANAGER_H
#define GPU_TEXTURE_DATA_MANAGER_H

#include "Texture.h"

enum struct TextureDataID: unsigned int {
    BACKGROUND,
    FRAME,
    NB_TEXTURE_DATA
};

class TextureDataManager {
    public:
        static const TextureDataManager& get();
        static TextureDataManager& get_mutable();

        const TextureData& get_data(TextureDataID id) const;
        TextureData& get_data_mutable(TextureDataID id);

    private:
        TextureData m_data[(size_t) TextureDataID::NB_TEXTURE_DATA];
};

#endif // GPU_TEXTURE_DATA_MANAGER_H
