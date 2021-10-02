/* package.cpp - Tool for generating textures files and associated headers */

#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "common.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define BUFFER_SIZE 4096

class CmdArgs {
    private:
        std::string input;
        std::string output;

    public:
        CmdArgs(int argc, char *argv[]) {
            if (argc != 3) {
                exit_error("Wrong number of parameters");
            }

            input = std::string(argv[1]);
            output = std::string(argv[2]);
        }

        std::string input_path() { return input; }
        std::string output_path() { return output; }
};

class ImageRGBA8888 {
    private:
        uint8_t* data;
        int width, height, channels;

    public:
        ImageRGBA8888(std::string file) {
            data = stbi_load(file.c_str(), &width, &height, &channels, 0);
            if (data == NULL) {
                exit_error("Could not open: " + file);
            }
        }

        ~ImageRGBA8888() {
            stbi_image_free(data);
        }

        ImageRGBA4444 to_rgba4444() {
            
        }
};

class ImageRGBA4444 {
    private:
        uint8_t* data;
        int width, height;

    public:
        ImageRGBA4444(uint8_t* data) : data(data) { }

        ~ImageRGBA4444() {
            delete[] data;
        }
};

int main(int argc, char *argv[]) {
    CmdArgs cmd_args(argc, argv);

    ImageRGBA8888 texture(cmd_args.input_path());

    //return -1;
    return 0;
}
