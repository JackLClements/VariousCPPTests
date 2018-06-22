/*
 */

/* 
 * File:   main.cpp
 * Author: Jack L. Clements
 *
 * Created on 16 June 2018, 17:38
 */

#include <cstdlib>
#include <iostream>
using namespace std;

void printTimesTables(); //function prototype

/*
 * 
 */
int main(int argc, char** argv) {
    printTimesTables();
    return 0;
}

void printTimesTables(){
    for(int i = 1; i < 13; i++){
        cout << "The " << i << " Times Table" << endl;
        for(int j = 1; j < 13; j++){
            cout << i << " times " << j << " is " << i*j << endl;
        }
        cout << "\n";
    }
    
}

