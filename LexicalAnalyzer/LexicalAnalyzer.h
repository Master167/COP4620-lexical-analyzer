/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LexicalAnalyzer.h
 * Author: Michael
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
    LexicalAnalyzer(const LexicalAnalyzer& orig);
    virtual ~LexicalAnalyzer();
private:

};

#endif /* LEXICALANALYZER_H */

