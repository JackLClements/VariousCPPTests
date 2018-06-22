/*
 */

/* 
 * File:   main.cpp
 * Author: Jack L. Clements
 *
 * Created on 17 June 2018, 15:55
 */

#include <cstdlib>
#include "slow_string.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char x[] = "test";
    char y[] = "best";
    slow_string str1(x);
    slow_string str2(y);
    str1 += str2;
    slow_string str3 = str1 + str2;
    cout << "thing - " << str3;
    return 0;
}

