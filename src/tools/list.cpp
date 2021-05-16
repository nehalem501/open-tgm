/* list.cpp - Tool for generating C headers of textures list info */

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

void exit_error(std::string error_msg) {
    std::cout << error_msg << std::endl;
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        exit_error("Wrong number of parameters");
    }

    std::string output(argv[1]);

    std::vector<std::string> list;

    for (unsigned int i = 2; i < argc; i++) {
        list.push_back(std::string(argv[i]));
    }

    std::cout << "output: " << output << std::endl;

    for (unsigned int i = 0; i < list.size(); i++) {
        std::cout << "item: " << list[i] << std::endl;
    }

    std::stringstream out;
    out << "/* " << output << " */" << std::endl;
    out << std::endl;
    //out << "#include <Glyph.h>" << std::endl;
    out << std::endl;

    std::ofstream output_file(output);
    if (output_file) {
        output_file << out.str();
        output_file.close();
        return 0;
    } else {
        exit_error(output + ": could not create file");
    }

    return 0;
}
