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
            if (std::isalpha(this->currentCharacter)) {
                this->analyzeLetter();
            }
            else if (std::isdigit(this->currentCharacter)) {
                //this->analyzeDigit();
            }
            else if (!std::isspace(this->currentCharacter)){
                //this->analyzeSpecialCharacter();
            }
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
    std::cout << "Analyze Digit" << std::endl;
    return false;
}

bool LexicalAnalyzer::analyzeLetter() {
    bool result = false;
    bool foundTerm = false;
    std::string identifier = "";
    identifier.append(1, this->currentCharacter);
    char peekCharacter;
    while (!foundTerm) {
        peekCharacter = this->peekAtNextCharacter();
        if (peekCharacter != '$') {
            if (std::isalpha(peekCharacter)) {
                this->moveToNextCharacter();
                identifier.append(1, this->currentCharacter);
            }
            else {
                foundTerm = true;
            }
        }
        else {
            // Reached end of line
            // I need to analyze what I have
            foundTerm = true;
        }
    }
    // peekCharacter could be a delimiter, digit, or special character
    if (this->searchKeyword(identifier)) {
        std::cout << "KEYWORD:" << identifier << std::endl;
        result = true;
    }
    //else if (identifier.compare("mod") == 0) {
    //    std::cout << identifier << std::endl;
    //}
    else {
        std::cout << "ID:" << identifier << std::endl;
        // ADD TO SYMBOL TABLE
    }
    return result;
}

bool LexicalAnalyzer::analyzeSpecialCharacter() {
    std::cout << "Analyze Special Character" << std::endl;
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
        std::cout << "INPUT:" << temp << std::endl;
    }
    return result;
}

char LexicalAnalyzer::peekAtNextCharacter() {
    char peekCharacter = '$';
    if (this->currentLineIndex + 1 < this->currentLine.length()) {
        peekCharacter = this->currentLine[this->currentLineIndex + 1];
    }
    return peekCharacter;
}

bool LexicalAnalyzer::searchKeyword(std::string search) {
    bool found = false;
    for (int i = 0; i < 7; i++) {
        if (search.compare(this->keywords[i]) == 0) {
            found = true;
        }
    }
    return found;
}

bool LexicalAnalyzer::searchSpecialCharacter(char search) {
    std::cout << "searchSpecialCharacter not implemented yet";
    return false;
}

