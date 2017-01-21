/* 
 * File:   LexicalAnalyzer.cpp
* Author: Michael Frederick (n00725913)
 * 
 * Created on January 16, 2017, 3:32 PM
 */

#include "LexicalAnalyzer.h"

LexicalAnalyzer::LexicalAnalyzer(std::fstream& inputFile, std::string filename) :
    currentFile(inputFile) {
    // Initialize special characters and keywords
    this->specialCharacters = new (std::nothrow) char[16];
    this->keywords = new (std::nothrow) std::string[7];
    this->currentLineIndex = -1;
    if (this->isReady()) {
        this->outputFilename = filename.append(".temp");
        // Manually loading the keywords and specialCharacters
        this->keywords[0] = "else";
        this->keywords[1] = "if";
        this->keywords[2] = "int";
        this->keywords[3] = "float";
        this->keywords[4] = "return";
        this->keywords[5] = "void";
        this->keywords[6] = "while";
        this->specialCharacters[0] = '+';
        this->specialCharacters[1] = '*';
        this->specialCharacters[2] = '-';
        this->specialCharacters[3] = '/';
        this->specialCharacters[4] = '<';
        this->specialCharacters[5] = '>';
        this->specialCharacters[6] = '=';
        this->specialCharacters[7] = '!';
        this->specialCharacters[8] = ';';
        this->specialCharacters[9] = ',';
        this->specialCharacters[10] = '(';
        this->specialCharacters[11] = ')';
        this->specialCharacters[12] = '{';
        this->specialCharacters[13] = '}';
        this->specialCharacters[14] = '[';
        this->specialCharacters[15] = ']';
    }
}

bool LexicalAnalyzer::isReady() {
    return (this->keywords != nullptr) && (this->specialCharacters != nullptr);
}

bool LexicalAnalyzer::scanFile() {
    bool results = true;
    if (this->isReady()) {
        while (this->moveToNextCharacter()) {
            //Check what the character is and decide
        }
        std::cout << "Finished Reading file" << std::endl;
    }
    else {
        results = false;
    }
    return results;
}

// Private functions
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

