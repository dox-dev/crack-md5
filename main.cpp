// Include all libraries
#include <iostream>
#include <fstream>
#include "md5/md5.h"

// Main function
int main(int argc, char *argv[]) {
    // Declare required variables
    std::ifstream read("wordlist.txt");
    std::string input, line;

    // Get MD5 hash as an user input
    std::cout << std::endl;
    std::cout << "Enter MD5 hash you want to crack: ";
    std::cin >> input;
    std::cout << std::endl;

    // Check through every line in "wordlist.txt" and compare its MD5 hash to input hash
    while (!read.eof()) {
        read >> line;

        // If found hash is equal to input hash, then print out the hash, plain text of it and end the program
        if (md5(line) == input) {
            std::cout << "\033[1m\033[32m" << "Hash cracked successfully!" << "\033[0m" << std::endl;
            std::cout << std::endl;
            std::cout << "\033[1m\033[33m" << "Hash: " << "\033[0m" << input << std::endl;
            std::cout << "\033[1m\033[33m" << "Plain text: " << "\033[0m" << line << std::endl;
            std::cout << std::endl;
            return 0;
        }
    }

    // If hash couldn't be found, print and end the program
    std::cout << "\033[1m\033[31m" << "Hash cannot be creacked" << "\033[0m" << std::endl;
    std::cout << std::endl;

    return 0;
}