/*
 */

/* 
 * File:   main.cpp
 * Author: Jack L. Clements
 *
 * Created on 21 June 2018, 15:29
 */

#include <cstdlib>
#include <iostream>
#include "Triangle.h"
#include "TriangleList.h"

using namespace std;



float dot(float* A, float* B){
    float variable =  (A[0]*B[0]) + (A[1]*B[1]) + (A[2]*B[2]); //can also use this value to calculate the angle between two vectors using cos^-1
    //cout << "dot - " << variable << endl;
    return variable;
}

//barycentric co-ordinate space
void pointInPlane(float* p, Triangle* t){
    //Take A in ABC as origin, any point within plane Triangle can be reached via a combination of A-B and A-C
    //Point P = A + u*(B - A) + v*(C - A) where u and v are arbitrary lengths such that 0 < v < 1 and 0 < u < 1
    float A[3], B[3], C[3];
    t->getA(A);
    t->getB(B);
    t->getC(C);
    
    float AB[3], AC[3], AP[3]; //distance from "origin" point A to B, C and P
    
    for(int i = 0; i < 3; i++){
        AB[i] = B[i] - A[i];
        AC[i] = C[i] - A[i];
        AP[i] = p[i] - A[i];
    }
    
    
    float denominator = dot(AB, AB) * dot(AC, AC) - dot(AB, AC) * dot(AB, AC);
    
    
    float u = ((dot(AC, AC)*dot(AP, AB))-(dot(AC, AB)*dot(AP, AC)))/denominator;
    float v = ((dot(AB, AB)*dot(AP, AC))-(dot(AB, AC)*dot(AP, AB)))/denominator;
    
    if(u >=0 && v >=0 && u+v < 1){
        cout << "Exact co-ordinates in mesh - " << A[0] + u << ", " << A[1] + v << endl;
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    Triangle t(0.0, 0.0, 0.0, 4.0, 0.0, 0.0, 4.0, 4.0, 0.0);
    float p[3] = {3.2, 0.1, 0};
    
    TriangleList mesh;
    
    for(int i = 0; i < 10; i+=2){
        for(int j = 0; j < 10; j+=2){
            Triangle t1(i, j, 0, i+2, j, 0, i+2, j+2, 0);
            Triangle t2(i, j, 0, i, j+2, 0, i+2, j+2, 0);
            mesh.add(t1);
            mesh.add(t2);
        }
    }
    
    for(int i = 0; i < mesh.size(); i++){
        Triangle t1 = mesh.at(i);
        pointInPlane(p, &t1);
    }
    
    return 0;
}

