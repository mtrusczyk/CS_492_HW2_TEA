#include <string>

std::string encrypt(std::string plaintext, std::string key);
std::string decrypt(std::string ciphertext, std::string key);
const int delta = 0x9e3779b9;
const uint ander = 0xffffffff;