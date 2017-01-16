/* 
 * File:   main.cpp
 * Author: Michael
 *
 * Created on January 16, 2017, 2:41 PM
 */
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

/*
 * Main Starting point of the program
 */
int main(int argc, char** argv) {
    if (argc > 1) {
        std::ifstream inputFile(argv[1]);
        if (inputFile.is_open()) {
            std::string inputLine;
            while (getline(inputFile,inputLine)) {
                std::cout << inputLine << std::endl;
            }
            std::cout << "Finished Reading file" << std::endl;
        }
        else {
            std::cout << "Bad Input file" << std::endl;
        }
    }
    else {
        std::cout << "No Input file given" << std::endl;
    }
    return 0;
}

