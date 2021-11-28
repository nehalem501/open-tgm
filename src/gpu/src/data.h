/* data.h - GPU */

#ifndef DATA_GPU_H
#define DATA_GPU_H

#include <stddef.h>
#include <stdint.h>

struct AssetEntry {
    const uint8_t* data;
    size_t size;

    constexpr AssetEntry(const uint8_t* data, size_t size) : data(data), size(size) { }
};


struct Assets {
    const AssetEntry* entries;
    const unsigned int length;

    constexpr Assets(const AssetEntry* entries, const unsigned int length) : entries(entries), length(length) { }
};

uint32_t read_uint32(const uint8_t* data);

#endif // DATA_GPU_H
