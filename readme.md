## CS 492 Security HW2 Tiny Encyption Angorithm (TEA) implementation

### Goal

*YOU* implement the Tiny Encryption Algorithm (TEA) in either Java or C++.  There are many implementations out there, but make sure this implementation is completely your own.  Your understanding of the details of how the bit operations matter is critical to your understanding of the intricacies of implementing computer security. 
In addition to submitting this word document you need to submit your source code.
1:  Use your TEA algorithm to encrypt the 64-bit plaintext block:
0x01CA45670CABCDEF
Using 128 bit key:
0xAF6BABCDEF00F000FEAFFFAFABCDEF01
Enter your cipher text here:

2:  Implement decryption and verify that you obtain the original plain text
3:  In comments in your code explain how you would make your code encode/decode a longer set of plaintext (i.e. multiple blocks) using CBC.  You do not need to code this, but your explanation should be detailed related to your implementation.

### Usage
*Compile:* `g++ main.cpp tea.cpp`
*encrypting:* `./a.out 0 0x123456789abcdef 0xa56babcdf000ffffffffffffabcdef01`
*decrypting:* `./a.out 1 0x7556391b2315d9f8 0xa56babcdf000ffffffffffffabcdef01`
