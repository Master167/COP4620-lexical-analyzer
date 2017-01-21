/* 
 * File:   LexicalAnalyzer.cpp
* Author: Michael Frederick (n00725913)
 * 
 * Created on January 16, 2017, 3:32 PM
 */

#include "LexicalAnalyzer.h"

LexicalAnalyzer::LexicalAnalyzer(std::fstream& inputFile) :
    currentFile(inputFile) {
    // Initialize special characters and keywords
    this->specialCharacters = new (std::nothrow) char[16];
    //{'+','-','*','/','<','>','=','!',';',',','(',')','{','}','[',']'}
    this->keywords = new (std::nothrow) std::string[7];
    //{"else","if","int","float","return","void","while"}
    this->currentLineIndex = -1;
}

bool LexicalAnalyzer::is_ready() {
    return (this->keywords != nullptr) && (this->specialCharacters != nullptr);
}

bool LexicalAnalyzer::scanFile() {
    bool results = true;
    while (this->moveToNextCharacter()) {
        //Check what the character is
    }
    std::cout << "Finished Reading file" << std::endl;
    return results;
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

bool LexicalAnalyzer::moveToNextCharacter() {
    bool result = false;
    this->currentLineIndex++;
    if (this->currentLineIndex == this->currentLine.length()) {
        // Move to next line
        if (this->moveToNextline()) {
            result = true;
        }
    }
    else if (this->currentLineIndex < this->currentLine.length()) {
        result = true;
    }
    if (result) {
        this->currentCharacter = this->currentLine[this->currentLineIndex];
    }
    return result;
}

bool LexicalAnalyzer::moveToNextline() {
    bool result = false;
    std::string temp;
    while (temp.length() <= 0) {
        if (!std::getline(this->currentFile,temp)) {
            // getLine failed, we have reached the end of the file
            break;
        }
    }
    if (temp.length() > 0) {
        result = true;
        this->currentLine = temp;
        this->currentLineIndex = 0;
        std::cout << "INPUT: " << temp << std::endl;
    }
    return result;
}

