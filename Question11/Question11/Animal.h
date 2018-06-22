/*
 */

/* 
 * File:   Animal.h
 * Author: Jack L. Clements
 *
 * Created on 21 June 2018, 22:50
 */
#include <iostream>
#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
protected:
    int legs;
    int arms;
    std::string name;

public:
    Animal(){
        
    };
    Animal(int legs, int arms, std::string name) {
        this->legs = legs;
        this->arms = arms;
        this->name = "Animal";
    };
    virtual std::string speak()=0;

};

#endif /* ANIMAL_H */

