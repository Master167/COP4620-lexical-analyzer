/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SymbolTable.h
 * Author: Michael
 *
 * Created on January 23, 2017, 3:59 PM
 */

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "Symbol.h"

class SymbolTable {
public:
    SymbolTable(int size);
    // Variables
    Symbol* deadSymbol;
    
    // Functions
    bool addSymbol(Symbol* sym);
    Symbol getSymbol(std::string);
    Symbol getDeadSymbol();
//    removeSymbol(); // To add later
//    updateSymbol();
private:
    // Variables
    Symbol* table;
    int size;
    int assignedValues;

    //Functions
    int HashFunction(std::string str);
    int getNextPrime(int num);
    bool isPrime(int p);
};

#endif /* SYMBOLTABLE_H */

