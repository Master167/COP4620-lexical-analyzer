/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Symbol.h
 * Author: Michael
 *
 * Created on January 23, 2017, 4:05 PM
 */

#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>

class Symbol {
public:
    //Constructor
    Symbol();
    Symbol(std::string identifier, int depth);
    //Variables
    
    //Functions
    std::string getIdentifier();
    int getDepth();
    bool isEqual(Symbol* sym);
private:
    //Variables
    std::string identifier;
    int depth;
    //std::string type; // I'll build unto this later
    //std::string value;
    
    //Functions
};

#endif /* SYMBOL_H */

