/* TextureDataManager.cpp - GPU */

#include "TextureDataManager.h"

static TextureDataManager texture_data_manager;

const TextureDataManager& TextureDataManager::get() {
    return texture_data_manager;
}

TextureDataManager& TextureDataManager::get_mutable() {
    return texture_data_manager;
}

const TextureData& TextureDataManager::get_data(TextureDataID id) const {
    const TextureData& t = m_data[(size_t) id];
    return t;
}

TextureData& TextureDataManager::get_data_mutable(TextureDataID id) {
    TextureData& t = m_data[(size_t) id];
    return t;
}
