/*
 */

/* 
 * File:   Human.h
 * Author: Jack L. Clements
 *
 * Created on 21 June 2018, 22:49
 */
#include <iostream>
#include "Animal.h"
#ifndef HUMAN_H
#define HUMAN_H

class Human: public Animal {
private:
    bool opposableDigits;

public:
    Human();
    Human(int arms, int legs, std::string name, bool opposableDigits);
    Human(Human& human);
    ~Human();
    virtual std::string speak();
    bool isOpposable();

};

#endif /* HUMAN_H */

