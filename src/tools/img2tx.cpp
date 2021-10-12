/* package.cpp - Tool for generating textures files and associated headers */

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include "../gpu/src/TextureEnums.h"

#include <zstd.h>

#define STB_DXT_IMPLEMENTATION
#include "stb_dxt.h"

#define STB_IMAGE_IMPLEMENTATION
#define STBI_FAILURE_USERMSG
#include "stb_image.h"

#define COMPRESSION_LEVEL 20

#define MATH_MIN(x, y) ((x) < (y) ? (x) : (y))

const std::unordered_map<std::string, unsigned int> FORMATS = {
    { "a4", TexturesFormat::A4 },
    { "l4", TexturesFormat::L4 },
    { "a8", TexturesFormat::A8 },
    { "l8", TexturesFormat::L8 },
    { "la4", TexturesFormat::LA4 },
    { "la8", TexturesFormat::LA8 },
    { "rgb332", TexturesFormat::RGB332 },
    { "rgb565", TexturesFormat::RGB565 },
    { "rgb8", TexturesFormat::RGB8 },
    { "rgba2", TexturesFormat::RGBA2 },
    { "rgba4", TexturesFormat::RGBA4 },
    { "rgba5551", TexturesFormat::RGBA5551 },
    { "rgba8", TexturesFormat::RGBA8 },
    { "dxt1", TexturesFormat::DXT1 },
    { "dxt3", TexturesFormat::DXT23 },
    { "dxt5", TexturesFormat::DXT45 },
    { "etc1", TexturesFormat::ETC1 },
    { "etc2rgb", TexturesFormat::ETC2_RGB },
    { "etc2rgba", TexturesFormat::ETC2_RGBA },
};

enum class DXTFormat { DXT1, DXT2, DXT3, DXT4, DXT5 };

void exit_error(std::string error_msg) {
    std::cout << error_msg << std::endl;
    exit(EXIT_FAILURE);
}

void display_usage(std::string prog) {
    std::cout << "usage: " << prog << " [-h] [-f FORMAT] input output" << std::endl;
}

void display_help(std::string prog) {
    display_usage(prog);
    std::cout << std::endl;
    std::cout << "positional arguments:" << std::endl;
    std::cout << "  input                        input image file" << std::endl;
    std::cout << "  output                       output texture file" << std::endl;
    std::cout << std::endl;
    std::cout << "options:" << std::endl;
    std::cout << "  -h, --help                   show this help message and exit" << std::endl;
    std::cout << "  -f FORMAT, --format FORMAT   output format" << std::endl;
    // TODO list formats
}

bool pow_of_2(unsigned int v) {
    return v && !(v & (v - 1));
}

class CmdArgs {
    private:
        std::string input;
        std::string output;
        unsigned int format;

    public:
        CmdArgs(int argc, char *argv[]) {
            std::vector<std::string> positional_args;
            bool no_format = true;

            for (int i = 1; i < argc; i++) {
                if (std::string(argv[i]) == "-h" || std::string(argv[i]) == "--help") {
                    display_help(std::string(argv[0]));
                    exit(EXIT_SUCCESS);
                } else if (std::string(argv[i]) == "-f" || std::string(argv[i]) == "--format") {
                    if (i + 1 < argc) {
                        std::string fmt = std::string(argv[i + 1]);
                        if (!FORMATS.count(fmt)) {
                            // TODO list formats
                            exit_error("Unknown texture format requested: " + fmt);
                        }
                        format = FORMATS.at(fmt);
                        i++;
                        no_format = false;
                    }
                } else {
                    positional_args.push_back(std::string(argv[i]));
                }
            }

            if (positional_args.size() != 2) {
                display_usage(std::string(argv[0]));
                exit_error("Wrong number of parameters");
            }

            if (no_format) {
                format = TexturesFormat::RGBA8;
            }

            input = positional_args[0];
            output = positional_args[1];
        }

        std::string input_path() { return input; }
        std::string output_path() { return output; }
        unsigned int output_format() { return format; }
};

struct Pixel8888 {
    Pixel8888(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) { }

    uint8_t r, g, b, a;
};

class ImageRGBA8888 {
    private:
        uint8_t* m_data;
        int m_width, m_height, m_channels;

    public:
        ImageRGBA8888(std::string file) {
            m_data = stbi_load(file.c_str(), &m_width, &m_height, &m_channels, 4);
            if (m_data == NULL) {
                exit_error("Could not open: " + file);
            }

            if (!pow_of_2(width())) {
                exit_error(file + ": width is not power of 2");
            }

            if (!pow_of_2(height())) {
                exit_error(file + ": height is not power of 2");
            }
        }

        ~ImageRGBA8888() {
            stbi_image_free(m_data);
        }

        inline const Pixel8888 operator [](unsigned int i) const {
            return Pixel8888(m_data[i], m_data[i + 1], m_data[i + 2], m_data[i + 3]);
        }

        inline unsigned int width() const { return (unsigned int) m_width; }
        inline unsigned int height() const { return (unsigned int) m_height; }
        inline unsigned int length() const { return width() * height(); }
        inline const uint8_t* data() const { return m_data; }
};

void encode_a4(std::vector<uint8_t>& bytes, ImageRGBA8888 &image) {
    for (unsigned int i = 0; i < image.length(); i += 2) {
        uint8_t byte = image[i].a & 0xF0u;
        byte |= image[i + 1].a >> 4;
        bytes.push_back(byte);
    }
}

void encode_l4(std::vector<uint8_t>& bytes, ImageRGBA8888 &image) {
    for (unsigned int i = 0; i < image.length(); i += 2) {
        uint8_t byte = image[i].r & 0xF0u;
        byte |= image[i + 1].r >> 4;
        bytes.push_back(byte);
    }
}

void encode_a8(std::vector<uint8_t>& bytes, ImageRGBA8888 &image) {
    for (unsigned int i = 0; i < image.length(); i += 2) {
        bytes.push_back(image[i].a);
    }
}

void encode_l8(std::vector<uint8_t>& bytes, ImageRGBA8888 &image) {
    for (unsigned int i = 0; i < image.length(); i += 2) {
        bytes.push_back(image[i].r);
    }
}

void encode_la4(std::vector<uint8_t>& bytes, ImageRGBA8888 &image) {
    for (unsigned int i = 0; i < image.length(); i++) {
        uint8_t byte = image[i].r & 0xF0u;
        byte |= image[i].a >> 4;
        bytes.push_back(byte);
    }
}

void encode_la8(std::vector<uint8_t>& bytes, ImageRGBA8888 &image) {
    for (unsigned int i = 0; i < image.length(); i++) {
        bytes.push_back(image[i].r);
        bytes.push_back(image[i].a);
    }
}

void encode_rgb332(std::vector<uint8_t>& bytes, ImageRGBA8888 &image) {
    for (unsigned int i = 0; i < image.length(); i++) {
        uint8_t byte = image[i].r & 0xE0u;
        byte |= (image[i].g >> 3) & 0x1Cu;
        byte |= image[i].b >> 6;
        bytes.push_back(byte);
    }
}

void encode_rgb565(std::vector<uint8_t>& bytes, ImageRGBA8888 &image) {
    for (unsigned int i = 0; i < image.length(); i++) {
        uint8_t byte1 = image[i].r & 0xF8u;
        byte1 |= image[i].g >> 5;
        uint8_t byte2 = (image[i].g << 5) & 0xE0u;
        byte2 |= image[i].b >> 3;
        bytes.push_back(byte1);
        bytes.push_back(byte2);
    }
}

void encode_rgb8(std::vector<uint8_t>& bytes, ImageRGBA8888 &image) {
    for (unsigned int i = 0; i < image.length(); i++) {
        bytes.push_back(image[i].r);
        bytes.push_back(image[i].g);
        bytes.push_back(image[i].b);
    }
}

void encode_rgba2(std::vector<uint8_t>& bytes, ImageRGBA8888 &image) {
    for (unsigned int i = 0; i < image.length(); i++) {
        uint8_t byte = image[i].r & 0xC0u;
        byte |= (image[i].g >> 2) & 0x30u;
        byte |= (image[i].b >> 4) & 0x0Cu;
        byte |= image[i].a >> 6;
        bytes.push_back(byte);
    }
}

void encode_rgba4(std::vector<uint8_t>& bytes, ImageRGBA8888 &image) {
    for (unsigned int i = 0; i < image.length(); i++) {
        uint8_t byte1 = image[i].r & 0xF0u;
        byte1 |= image[i].g >> 4;
        uint8_t byte2 = image[i].b & 0xF0;
        byte2 |= image[i].a >> 4;
        bytes.push_back(byte1);
        bytes.push_back(byte2);
    }
}

void encode_rgba5551(std::vector<uint8_t>& bytes, ImageRGBA8888 &image) {
    for (unsigned int i = 0; i < image.length(); i++) {
        uint8_t byte1 = image[i].r & 0xF8u;
        byte1 |= image[i].g >> 5;
        uint8_t byte2 = (image[i].g << 5) & 0xC0u;
        byte2 |= (image[i].b >> 2) & 0x3Eu;
        byte2 |= image[i].a >> 7;
        bytes.push_back(byte1);
        bytes.push_back(byte2);
    }
}

void encode_rgba8(std::vector<uint8_t>& bytes, ImageRGBA8888 &image) {
    bytes.insert(bytes.end(), image.data(), image.data() + (image.length() * 4));
}

void encode_dxt(std::vector<uint8_t>& bytes, ImageRGBA8888 &image, DXTFormat format) {
    const unsigned int width = image.width();
    const unsigned int height = image.height();
    const uint8_t* input = image.data();
    for (unsigned int y = 0; y < height; y += 4) {
        for (unsigned int x = 0; x < width; x += 4) {
            uint8_t block[64];
            uint8_t alpha[16];
            for (int by = 0; by < 4; ++by) {
                for (int bx = 0; bx < 4; ++bx) {
                    int ai = (by * 4) + bx;
                    int bi = ai * 4;
                    int xx = MATH_MIN(x + bx, width - 1);
                    int yy = MATH_MIN(y + by, height - 1);
                    int i = ((yy * width) + xx) * 4;
                    block[bi + 0] = input[i + 0];
                    block[bi + 1] = input[i + 1];
                    block[bi + 2] = input[i + 2];
                    block[bi + 3] = 0xFF;
                    alpha[ai] = input[i + 3];
                    if (format == DXTFormat::DXT2 || format == DXTFormat::DXT4) {
                        float am = (float)alpha[ai] / 0xFF;
                        block[bi + 0] *= am;
                        block[bi + 1] *= am;
                        block[bi + 2] *= am;
                    }
                }
            }

            uint8_t chunk[16];
            int chunk_size = 16;
            switch (format) {
                case DXTFormat::DXT1:
                    stb_compress_dxt_block(chunk, block, false, STB_DXT_HIGHQUAL);
                    chunk_size = 8;
                    break;
                case DXTFormat::DXT2:
                case DXTFormat::DXT3:
                    for (int i = 0; i < 8; ++i) {
                        uint8_t a0 = alpha[i * 2 + 0] / 17;
                        uint8_t a1 = alpha[i * 2 + 1] / 17;
                        chunk[i] = (a1 << 4) | a0;
                    }
                    stb_compress_dxt_block(chunk + 8, block, false, STB_DXT_HIGHQUAL);
                    break;
                case DXTFormat::DXT4:
                case DXTFormat::DXT5:
                    stb_compress_bc4_block(chunk, alpha);
                    stb_compress_dxt_block(chunk + 8, block, false, STB_DXT_HIGHQUAL);
                    break;
            }
            bytes.insert(bytes.end(), chunk, chunk + chunk_size);
        }
    }
}

void encode_dxt1(std::vector<uint8_t>& bytes, ImageRGBA8888 &image) {
    encode_dxt(bytes, image, DXTFormat::DXT1);
}

void encode_dxt3(std::vector<uint8_t>& bytes, ImageRGBA8888 &image) {
    encode_dxt(bytes, image, DXTFormat::DXT3);
}

void encode_dxt5(std::vector<uint8_t>& bytes, ImageRGBA8888 &image) {
    encode_dxt(bytes, image, DXTFormat::DXT5);
}

// TODO DXT2 & DXT4
// TODO ETC1, ETC2, ASTC, ...

uint8_t texture_size(unsigned int size) {
    return (uint8_t) log2(size);
}

void write_uint32(uint8_t* data, uint32_t value) {
    data[0] = (value >> 24) & 0xFF;
    data[1] = (value >> 16) & 0xFF;
    data[2] = (value >>  8) & 0xFF;
    data[3] =  value        & 0xFF;
}

uint32_t read_uint32(uint8_t* data) {
    uint32_t value =
        ((uint32_t) data[3] << 0)  |
        ((uint32_t) data[2] << 8)  |
        ((uint32_t) data[1] << 16) |
        ((uint32_t) data[0] << 24);
    return value;
}

void write_header(std::vector<uint8_t>& bytes, uint8_t format, uint8_t width, uint8_t height) {
    bytes.push_back(TextureFileHeader::BYTE_0);
    bytes.push_back(TextureFileHeader::BYTE_1);
    bytes.push_back(TextureFileHeader::BYTE_2);
    bytes.push_back(TextureFileHeader::BYTE_3);
    bytes.push_back(TextureFileHeader::BYTE_4);
    bytes.push_back(TextureFileHeader::BYTE_5);
    bytes.push_back(TextureFileHeader::BYTE_6);
    bytes.push_back(TextureFileHeader::BYTE_7);

    bytes.push_back(format);
    bytes.push_back(width);
    bytes.push_back(height);
    bytes.push_back(0x00u); // Reserved

    // Data size value will be updated later
    bytes.push_back(0x00u);
    bytes.push_back(0x00u);
    bytes.push_back(0x00u);
    bytes.push_back(0x00u);
}

int main(int argc, char *argv[]) {
    CmdArgs cmd_args(argc, argv);

    ImageRGBA8888 texture(cmd_args.input_path());

    std::vector<uint8_t> bytes;

    write_header(
        bytes,
        (uint8_t) cmd_args.output_format(),
        texture_size(texture.width()),
        texture_size(texture.height()));

    size_t current_size = bytes.size();

    switch (cmd_args.output_format()) {
        case TexturesFormat::A4:
            encode_a4(bytes, texture);
            break;

        case TexturesFormat::L4:
            encode_l4(bytes, texture);
            break;

        case TexturesFormat::A8:
            encode_a8(bytes, texture);
            break;

        case TexturesFormat::L8:
            encode_l8(bytes, texture);
            break;

        case TexturesFormat::LA4:
            encode_la4(bytes, texture);
            break;

        case TexturesFormat::LA8:
            encode_la8(bytes, texture);
            break;

        case TexturesFormat::RGB332:
            encode_rgb332(bytes, texture);
            break;

        case TexturesFormat::RGB565:
            encode_rgb565(bytes, texture);
            break;

        case TexturesFormat::RGB8:
            encode_rgb8(bytes, texture);
            break;

        case TexturesFormat::RGBA2:
            encode_rgba2(bytes, texture);
            break;

        case TexturesFormat::RGBA4:
            encode_rgba4(bytes, texture);
            break;

        case TexturesFormat::RGBA5551:
            encode_rgba5551(bytes, texture);
            break;

        case TexturesFormat::RGBA8:
            encode_rgba8(bytes, texture);
            break;

        case TexturesFormat::DXT1:
            encode_dxt1(bytes, texture);
            break;

        case TexturesFormat::DXT23:
            encode_dxt3(bytes, texture);
            break;

        case TexturesFormat::DXT45:
            encode_dxt5(bytes, texture);
            break;

        default:
            exit_error("Unknown texture format requested");
    }

    current_size = bytes.size() - current_size;

    // Update data length in header
    write_uint32(&bytes[12], (uint32_t) current_size);

    std::vector<uint8_t> compressed;
    compressed.resize(ZSTD_compressBound(bytes.size()));
    size_t const size = ZSTD_compress(compressed.data(), compressed.capacity(), bytes.data(), bytes.size(), COMPRESSION_LEVEL);
    if (ZSTD_isError(size)) {
        exit_error("could not compress data: " + std::string(ZSTD_getErrorName(size)));
    }
    compressed.resize(size);

    std::ofstream output_file(cmd_args.output_path(), std::ofstream::out | std::ofstream::binary | std::ofstream::trunc);
    if (!output_file) {
        exit_error(cmd_args.output_path() + ": could not create file");
    }

    output_file.write((char*) compressed.data(), compressed.size());

    output_file.close();

    return 0;
}
