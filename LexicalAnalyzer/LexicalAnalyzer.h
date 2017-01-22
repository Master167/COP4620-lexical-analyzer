/* 
 * File:   LexicalAnalyzer.h
 * Author: Michael Frederick (n00725913)
 *
 * Created on January 16, 2017, 3:32 PM
 */

#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include <fstream>
#include <string>
#include <iostream>
#include <new>
#include <cctype>

class LexicalAnalyzer {
public:
    LexicalAnalyzer(std::fstream& inputFile, std::string filename);
    bool isReady();
    bool scanFile();    
    std::string outputFilename;
private:
    // Class Variables
    char currentCharacter;
    int currentLineIndex;
    std::fstream& currentFile;
    std::string currentLine;

    char* specialCharacters;
    std::string* keywords;

    // Class functions
    bool analyzeDigit();
    bool analyzeLetter();
    bool analyzeSpecialCharacter();
    bool writeToFile(std::string outputLine);
    
    bool moveToNextCharacter();
    bool moveToNextline();
    char peekAtNextCharacter();
    bool searchKeyword(std::string search);
    bool searchSpecialCharacter(char search);

    bool errorLine();
};

#endif /* LEXICALANALYZER_H */

