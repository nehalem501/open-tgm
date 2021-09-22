/* data.h - GPU */

#ifndef DATA_GPU_H
#define DATA_GPU_H

#include <Glyph.h>
#include <Glyphs.h>
#include <Texture.h>
#include <TilemapData.h>

class AssetDataEntryItem {
    public:
        constexpr AssetDataEntryItem(
            const Glyph* data,
            const int entry_tile_size) : m_data((void*) data), m_tile_size(entry_tile_size) { }

        constexpr AssetDataEntryItem(
            const TextureData& data,
            const int entry_tile_size) : m_data((void*) &data), m_tile_size(entry_tile_size) { }

        constexpr AssetDataEntryItem(
            const TilemapData& data,
            const int entry_tile_size) : m_data((void*) &data), m_tile_size(entry_tile_size) { }

        inline int get_tile_size() const { return m_tile_size; }

        inline const Glyph* get_glyphs() const { return (Glyph*) m_data; }
        inline const TextureData& get_texture() const { return *((TextureData*) m_data); }
        inline const TilemapData& get_tilemap() const { return *((TilemapData*) m_data); }

    private:
        const void* m_data;
        const int m_tile_size;
};

class AssetDataEntry {
    public:
        constexpr AssetDataEntry(
            const AssetDataEntryItem* items,
            const unsigned int items_nb) : m_items(items), m_items_nb(items_nb) { }

        inline const AssetDataEntryItem& get_item() const {
            // TODO optimize
            for (unsigned int i = 0; i < m_items_nb; i++) {
                if (tile_size <= m_items[i].get_tile_size()) {
                    return m_items[i];
                }
            }

            return m_items[m_items_nb - 1];
        }

    private:
        const AssetDataEntryItem* m_items;
        const unsigned int m_items_nb;
};

class AssetData {
    public:
        constexpr AssetData(const AssetDataEntry* entries) : m_entries(entries) { }

        const Glyph* get_glyphs_data(Font font) const;
        const TextureData& get_texture_data(const TextureID texture) const;
        const TilemapData& get_tilemap_data(const TextureID texture) const;

    private:
        const AssetDataEntry* m_entries;
};

#endif // DATA_GPU_H
