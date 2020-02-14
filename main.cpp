#include <iostream>
#include <string>
#include "tea.hpp"

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        std::string first_arg(argv[1]);
        if (first_arg.compare("-h") == 0 || first_arg.compare("--help") == 0) //this needs to be fixed
            std::cout << "executable <function> <text> <key>\n"
                      << "function\n\t0: encrypt\n\t1: decrypt\n"
                      << "text: text you wish to encrypt/decrypt\n"
                      << "key: key to perform encryption/decryption on \n";
        else
            std::cout << "Wrong number of command line arguments. Expected 4 got " << argc << "\n";
    }
    else if (argc != 4)
        std::cout
            << "Wrong number of command line arguments. Expected 4 got " << argc << "\n";
    else if (std::string(argv[1]).compare("0") != 0 && std::string(argv[1]).compare("1") != 0)
        std::cout << "Invalid function type";

    else if (argv[2][0] != '0' || argv[3][0] != '0')
        std::cout
            << "one or both strings do not look like hexidecimal integers"
            << "\n";
    else
    {
        if (std::string(argv[1]).compare("0") == 0)
        {
            std::string cipher = encrypt(std::string(argv[2]), std::string(argv[3]));
            std::cout << cipher;
        }
        else
        {
            std::string cipher = decrypt(argv[2], argv[3]);
            std::cout << cipher;
        }
    }
    //actual key

    // const int key0 = 0xAF6BABCD;
    // const int key1 = 0xEF00F000;
    // const int key2 = 0xFEAFFFAF;
    // const int key3 = 0xABCDEF01;

    // test key

    // std::cout << encrypt();
    // std::cout << decrypt();
}