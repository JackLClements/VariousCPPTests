/*
 */

#include "Tiger.h"

Tiger::Tiger(){
    name = "Tiger";
    arms = 0;
    legs = 0;
    tail = true;
}

Tiger::Tiger(int arms, int legs, std::string name, bool tail):Animal(arms, legs, name){
    this->tail = tail;
}

Tiger::Tiger(Tiger& tiger){
    name = tiger.name;
    arms = tiger.arms;
    legs = tiger.legs;
    tail = tiger.tail;
}

Tiger::~Tiger(){
    
}

bool Tiger::hasTail(){
    return tail;
}

std::string Tiger::speak(){
    return "Roar!";
}