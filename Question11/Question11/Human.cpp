/*
 */

#include "Human.h"

Human::Human(){
    arms = 2;
    legs = 2;
    name = "Human";
    opposableDigits = true;
}

Human::Human(int arms, int legs, std::string name, bool opposableDigits):Animal(arms, legs, name){
    this->opposableDigits = opposableDigits;
}

Human::Human(Human& human){
    arms = human.arms;
    legs = human.legs;
    name = human.name;
    opposableDigits = human.opposableDigits;
}

Human::~Human(){
    
}

std::string Human::speak(){
    return "Hello World!";
}

bool Human::isOpposable(){
    return opposableDigits;
}