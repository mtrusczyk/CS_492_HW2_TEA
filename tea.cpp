#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "tea.hpp"

int shift_right(int cipher, int shift)
{
    // if you have a 32 bits of 1s then when you bitwise and
    // something with it it will always produce a 32 bit number
    return (cipher >> shift) & (ander >> shift);
}

int shift_left(int cipher, int shift)
{
    // if you have a 32 bits of 1s then when you bitwise and
    // something with it it will always produce a 32 bit number
    return (cipher << shift) & ander;
}

std::string stringify_hex(int &hex)
{
    std::stringstream stream;
    stream << std::setfill('0') << std::setw(8)
           << std::hex << hex;
    return stream.str();
}

std::string combine_halfs(int left, int right)
{
    std::stringstream stream;
    stream << "0x"
           << std::hex
           << stringify_hex(left)
           << stringify_hex(right) << "\n";
    return stream.str();
}

void break_up_key(std::string key, int &key0, int &key1, int &key2, int &key3)
{
    std::string k0 = key.substr(0, 8);
    std::string k1 = key.substr(8, 8);
    std::string k2 = key.substr(16, 8);
    std::string k3 = key.substr(24, 8);

    key0 = stoul(k0, nullptr, 16);
    key1 = stoul(k1, nullptr, 16);
    key2 = stoul(k2, nullptr, 16);
    key3 = stoul(k3, nullptr, 16);
}

// This function should be edited so that it assumes the input will always be 64 bits.
void split_plaintext(std::string text, int &L, int &R)
{
    std::string l = text.substr(0, text.size() - 8);
    std::string r = text.substr(text.size() - 8, 8);
    L = stoul(l, nullptr, 16);
    R = stoul(r, nullptr, 16);
}
// this method needs a new parameter equating to the initial value
std::string encrypt(std::string plaintext, std::string key)
{
    int L, R, key0, key1, key2, key3;

    break_up_key(key.substr(2), key0, key1, key2, key3);

    /*  
    * the following region should be refactored into a new function. It also needs a new parameter that
    * equates to the IV or the result from the last round
    * 
    * The new function can perform the round function in one of two ways
    * 1. Recursion
    * The function takes in the entire plaintext object encrypts the first 64 bits,
    * then recursively calls encrypt on a substring of of the plaintext missing the first 64 bits
    * this would probably use lots of memory
    * 
    * 2. for loop
    * The function has a for loop that runs until a pointer (not a c pointer) is larger than the size of the string
    * after each iteration the pointer would increment by 64;
    */
#pragma region

    split_plaintext(plaintext.substr(2), L, R);

    int sum = 0;
    for (int i = 1; i <= 32; i++)
    {
        sum += delta;
        L += ((shift_left(R, 4) + key0) ^ (R + sum) ^ (shift_right(R, 5) + key1));
        R += ((shift_left(L, 4) + key2) ^ (L + sum) ^ (shift_right(L, 5) + key3));
    }

    return combine_halfs(L, R);

#pragma endregion
}

// this method needs a new parameter equating to the initial value
std::string decrypt(std::string ciphertext, std::string key)
{
    int L, R, key0, key1, key2, key3;

    break_up_key(key.substr(2), key0, key1, key2, key3);

    /*  
    * the following region should be refactored into a new function it also needs a new parameter that
    * equates to the IV or the result from the last round
    * 
    * The new function can perform the round function in one of two ways
    * 1. Recursion
    * The function takes in the entire plaintext object decrypts the first 64 bits,
    * then recursively calls decrypt on a substring of of the plaintext missing the first 64 bits
    * this would probably use lots of memory
    * 
    * 2. for loop
    * The function has a for loop that runs until a pointer (not a c pointer) is larger than the size of the string
    * after each iteration the pointer would increment by 64;
    */
#pragma region

    split_plaintext(ciphertext.substr(2), L, R);

    int sum = shift_left(delta, 5);

    for (int i = 1; i <= 32; i++)
    {
        R -= ((shift_left(L, 4) + key2) ^ (L + sum) ^ (shift_right(L, 5) + key3));
        L -= ((shift_left(R, 4) + key0) ^ (R + sum) ^ (shift_right(R, 5) + key1));
        sum -= delta;
    }

    return combine_halfs(L, R);

#pragma endregion
}