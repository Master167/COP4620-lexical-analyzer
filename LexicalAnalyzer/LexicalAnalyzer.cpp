/* 
 * File:   LexicalAnalyzer.cpp
* Author: Michael Frederick (n00725913)
 * 
 * Created on January 16, 2017, 3:32 PM
 */

#include "LexicalAnalyzer.h"

LexicalAnalyzer::LexicalAnalyzer(std::fstream& inputFile) :
    currentFile(inputFile) {
    this->scanFile();
}

bool LexicalAnalyzer::scanFile() {
    bool results = true;
    while (getline(this->currentFile,this->currentLine)) {
        std::cout << this->currentLine << std::endl;
    }
    std::cout << "Finished Reading file" << std::endl;
    return results;
}

bool LexicalAnalyzer::scanFile(std::fstream& inputFile) {
    this->currentFile = inputFile;
    return this->scanFile();
}

bool LexicalAnalyzer::analyzeDigit() {
    return false;
}

bool LexicalAnalyzer::analyzeLetter() {
    return false;
}

bool LexicalAnalyzer::analyzeSpecialCharacter() {
    return false;
}

bool writeToFile(std::string outputLine) {
    return false;
}

void LexicalAnalyzer::moveToNextCharacter() {
    
}

void LexicalAnalyzer::moveToNextline() {
    
}

