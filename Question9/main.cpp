/* 
 * File:   main.cpp
 * Author: Jack L. Clements
 *
 * Created on 20 June 2018, 13:40
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * Utilises lagrange polynomials to draw a smooth curve
 */

struct Point{
    float x;
    float y;
};

//Lagrange Polynomial function
float getTimeOnCurve(Point values[], int size, float time){
    float total = 0.0;
    for(int i = 0; i < size; i++){
        //iterate through points
        float fN = values[i].y;
        //calculate polynomial
        for(int j = 0; j < size; j++){
            if(i != j){ //to stop polynomial result using the current value
                fN = ((time-values[j].x)*fN/(float)(values[i].x - values[j].x));
            }
        }
        total += fN;
    }
    return total;
}

//Prototyped draw function, can't get Visual Studio Code to play nice with OpenGL, so no drawing API called.
void draw(Point values[], int size){
    float increment = 0.0;
    while(increment > values[size-1].x){
        getTimeOnCurve(values, size, increment); //note - need to normalise time values better
        increment+= 0.1;
    }
}

int main(int argc, char** argv) {
    Point val[5] = {{1, 0.1411}, {1.3, -0.6878}, {1.6, -0.9962}, {1.9 , -0.5507}, {2.2, 0.3115}};
    cout << getTimeOnCurve(val, 5, 0.5);
    return 0;
}

