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
#include "SymbolTable.h"
#include "Symbol.h"

class LexicalAnalyzer {
public:
    LexicalAnalyzer(std::fstream& inputFile, std::string filename);
    bool isReady();
    bool scanFile(SymbolTable* symtab);    
    std::string outputFilename;
private:
    // Class Variables
    char currentCharacter;
    int currentLineIndex;
    int scope;
    std::fstream& currentFile;
    std::string currentLine;
    SymbolTable* symTab;
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

    bool errorLine(std::string str);
};

#endif /* LEXICALANALYZER_H */

