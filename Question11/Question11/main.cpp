/*
 */

/* 
 * File:   main.cpp
 * Author: Jack L. Clements
 *
 * Created on 21 June 2018, 22:49
 */

#include <cstdlib>
#include "Human.h"
#include "Tiger.h"
#include "Animal.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Tiger tiger(0, 4, "Tiger", true);
    Human human(2, 2, "Human", true);
    
    Animal* animal1 = &tiger;
    Animal* animal2 = &human;
    
    cout << animal1->speak() << endl;
    cout << animal2->speak() << endl;
    
    return 0;
}

