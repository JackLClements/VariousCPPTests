/*
 */

/* 
 * File:   main.cpp
 * Author: Jack L. Clements
 *
 * Created on 19 June 2018, 19:56
 */

#include <cstdlib>
#include "TriangleList.h"
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Triangle tri1(1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 3.0, 1.0, 1.0);
    Triangle tri2(2.0, 2.0, 2.0, 2.0, 3.0, 2.0, 4.0, 2.0, 2.0);
    TriangleList triList;
    triList.add(tri1);
    triList.add(tri2);
    cout << "Normal at [2]: " << triList.at(0).getNormalAt(2) << endl;
    return 0;
}

