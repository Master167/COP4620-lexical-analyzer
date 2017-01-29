/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Symbol.cpp
 * Author: Michael
 * 
 * Created on January 23, 2017, 4:05 PM
 */

#include "Symbol.h"

Symbol::Symbol() {
    this->identifier = "$DEAD$";
    this->depth = 0;
}

Symbol::Symbol(std::string identifier, int depth) {
    this->identifier = identifier;
    this->depth = depth;
}

std::string Symbol::getIdentifier() {
    return this->identifier;
}
int Symbol::getDepth() {
    return this->depth;
}

bool Symbol::isEqual(Symbol* sym) {
    bool equal = false;
    
    // Check size
    if (sym->getIdentifier().length() == this->getIdentifier().length() && sym->depth == this->depth) {
        equal = true;
        for (int i = 0; i < this->getIdentifier().length(); i++) {
            if (this->getIdentifier()[i] != sym->getIdentifier()[i]) {
                equal = false;
                break;
            }
        }
    }
    return equal;
}
