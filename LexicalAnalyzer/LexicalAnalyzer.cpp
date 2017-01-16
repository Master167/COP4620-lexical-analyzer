/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LexicalAnalyzer.cpp
 * Author: Michael
 * 
 * Created on January 16, 2017, 3:32 PM
 */

#include "LexicalAnalyzer.h"

LexicalAnalyzer::LexicalAnalyzer(std::fstream& inputFile) {
    std::string inputLine;
    while (getline(inputFile,inputLine)) {
        std::cout << inputLine << std::endl;
    }
    std::cout << "Finished Reading file" << std::endl;
}

LexicalAnalyzer::LexicalAnalyzer(const LexicalAnalyzer& orig) {
}

LexicalAnalyzer::~LexicalAnalyzer() {
}

