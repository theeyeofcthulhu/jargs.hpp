#define JARGS_IMPLEMENTATION
#include "jargs.hpp"

int main(int argc, char **argv)
{
    bool a_flag = false;

    jargs::Parser parser;
    parser.add({'a', "ay", "A option", [&a_flag]() {
            a_flag = true;
            std::cout << "a\n";
            }});
    parser.add({"bee", "B option", []() {
            std::cout << "b\n";
            }});
    parser.add({'c', "C option", []() {
            std::cout << "c\n";
            }});
    parser.add({'d', "dee", "D option", [](std::string_view optarg) {
            std::cout << "d: " << optarg << '\n';
            }});
    parser.add({"ee", "E option", [](std::string_view optarg) {
            std::cout << "e: " << optarg << '\n';
            }});
    parser.add({'f', "F option", [](std::string_view optarg) {
            std::cout << "f: " << optarg << '\n';
            }});
    parser.add_help("example [-abc] [-def ARG]");

    parser.parse(argc, argv);

    std::cout << "a_flag: " << a_flag << '\n';
}
