#include <string_view>

#define JARGS_IMPLEMENTATION
#include "jargs.hpp"

int main(int argc, char **argv) {
    bool flag = false;
    std::string_view filename;

    jargs::Parser parser;
    // -f, --flag
    parser.add({'f', "flag", "Set flag", [&flag]() {
        flag = true;
    }});
    // --filename a.out, --filename=a.out
    parser.add({"filename", "Specify filename", [&filename](auto optarg) {
        filename = optarg;
    }});
    // -psomething, -p something
    parser.add({'p', "Print something", [](auto optarg) {
        std::cout << optarg << '\n';
    }});
    parser.add_help("example [args]");

    parser.parse(argc, argv);

    std::cout << "flag: " << flag << '\n';
    std::cout << "filename: " << filename << '\n';
}
