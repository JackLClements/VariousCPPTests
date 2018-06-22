/*
 */

/* 
 * File:   Tiger.h
 * Author: Jack L. Clements
 *
 * Created on 21 June 2018, 22:51
 */
#include "Animal.h"
#ifndef TIGER_H
#define TIGER_H


class Tiger: public Animal {
private:
    bool tail;

public:
    Tiger();
    Tiger(int arms, int legs, std::string name, bool tail);
    Tiger(Tiger& tiger);
    ~Tiger();
    virtual std::string speak();
    bool hasTail();

};

#endif /* TIGER_H */

