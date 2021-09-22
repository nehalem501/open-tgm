/* common.h */

#ifndef TOOLS_COMMON_H
#define TOOLS_COMMON_H

#include <string>
#include <vector>
#include <iostream>
#include "../gpu/src/TextureID.h"

namespace AssetType {
    enum {
        Texture = 0,
        Tilemap,
        Glyphs
    };
}

void exit_error(std::string error_msg) {
    std::cout << error_msg << std::endl;
    exit(1);
}

std::string get_filename(std::string path) {
    #ifdef _WIN32
    std::string delimiter = "\\";
    #else
    std::string delimiter = "/";
    #endif

    size_t start = 0;
    size_t end;
    size_t delim_len = delimiter.length();

    while ((end = path.find(delimiter, start)) != std::string::npos) {
        start = end + delim_len;
    }

    std::string filename = path.substr(start);
    size_t position = filename.rfind(".");
    if (position == std::string::npos) {
        return filename;
    } else {
        filename.erase(position, std::string::npos);
        return filename;
    }
}

int string_to_int(std::string str) {
    int value = -1;
    std::istringstream input(str);
    input >> value;
    if (input.fail()) {
        return -1;
    }
    return value;
}

std::vector<int> split(std::string str) {
    std::string delimiter = ",";

    size_t start = 0;
    size_t end;
    size_t delim_len = delimiter.length();
    std::string token;

    std::vector<int> numbers;

    while ((end = str.find(delimiter, start)) != std::string::npos) {
        token = str.substr(start, end - start);
        start = end + delim_len;
        numbers.push_back(string_to_int(token));
    }

    numbers.push_back(string_to_int(str.substr(start)));

    return numbers;
}

TextureID string_to_texture_id(std::string input) {
    if (input == "background") {
        return TexturesID::BACKGROUND;
    } else if (input == "blocks") {
        return TexturesID::BLOCKS;
    } else if (input == "outline") {
        return TexturesID::OUTLINE;
    } else if (input == "text") {
        return TexturesID::TEXT;
    } else if (input == "frame") {
        return TexturesID::FRAME;
    } else if (input == "labels") {
        return TexturesID::LABELS;
    } else if (input == "digits") {
        return TexturesID::DIGITS;
    }

    return TexturesID::NONE;
}

std::string texture_id_to_string(TextureID id) {
    switch (id) {
        case TexturesID::BACKGROUND:
            return "background";
        case TexturesID::BLOCKS:
            return "blocks";
        case TexturesID::OUTLINE:
            return "outline";
        case TexturesID::TEXT:
            return "text";
        case TexturesID::FRAME:
            return "frame";
        case TexturesID::LABELS:
            return "labels";
        case TexturesID::DIGITS:
            return "digits";
    }

    return "none";
}

#endif // TOOLS_COMMON_H
