/* 
 * File:   main.cpp
 * Author: Jack L. Clements
 *
 * Created on 16 June 2018, 17:23
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int function(int n);
int recursion(int n);
/*
 * There are two potential ways to solve this. I've included both.
 */
int main(int argc, char** argv) {
    cout << function(5) << endl;
    cout << recursion(5) << endl;
    return 0;
}

int function(int n){
    //base case is zero, this could also use for loop, but we're replicating recursion
    int total = 0;
    int loops = n;
    while(loops > 0){
        total += loops;
        loops--;
    }
    return total;
}

int recursion(int n){
    if(n == 0){
        return 0;
    }
    else{
        return n + recursion(n-1);
    }
}

