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

class LexicalAnalyzer {
public:
    LexicalAnalyzer(std::fstream& inputFile);
    bool scanFile();
    bool scanFile(std::fstream& inputFile);
private:
    // Class Variables
    char currentCharacter;
    int currentLineIndex;
    std::fstream& currentFile;
    std::string currentLine;
    std::string outputFilename;

    char specialCharacters[];
    std::string keywords[];

    // Class functions
    bool analyzeDigit();
    bool analyzeLetter();
    bool analyzeSpecialCharacter();
    bool writeToFile(std::string outputLine);
    
    void moveToNextCharacter();
    void moveToNextline();
};

#endif /* LEXICALANALYZER_H */

