/*
 */

#include "DirVector.h"
#include <math.h>

DirVector::DirVector(const DirVector& vec){
    vector[0] = vec.getX();
    vector[1] = vec.getY();
    vector[2] = vec.getZ();
}

DirVector::DirVector(float x, float y, float z){
    vector[0] = x;
    vector[1] = y;
    vector[2] = z;
}

float DirVector::getX() const{
    return vector[0];
}

float DirVector::getY() const{
    return vector[1];
}

float DirVector::getZ() const{
    return vector[2];
}




DirVector DirVector::cross(const DirVector& vec){
    float x = (vector[1]*vec.getZ()) - (vec.getY()*vector[2]);
    float y = (vector[2]*vec.getX()) - (vector[0]*vec.getZ());
    float z = (vector[0]*vec.getY()) - (vector[1]*vec.getX());
    return DirVector(x, y, z);
}


float DirVector::dot(const DirVector& vec){
    return (vector[0]*vec.getX()) + (vector[1]*vec.getY()) + (vector[2]*vec.getZ()); //can also use this value to calculate the angle between two vectors using cos^-1
}

void DirVector::add(const DirVector& vec){
    vector[0] += vec.getX();
    vector[1] += vec.getY();
    vector[2] += vec.getZ();
}

void DirVector::scalarMultiplication(float multiplier){
    for(int i = 0; i < 3; i++){
        vector[i] *= multiplier;
    }
}

void DirVector::scalarDivision(float divisor){
    for(int i = 0; i < 3; i++){
        vector[i] /= divisor;
    }
}

float DirVector::magnitude(){
    //sqrt is a performance hog, caching can be used
    return sqrt((vector[0]*vector[0])+(vector[1]*vector[1])+(vector[2]*vector[2]));
}

DirVector DirVector::operator +=(const DirVector& rhs){
    vector[0] += rhs.getX();
    vector[1] += rhs.getY();
    vector[2] += rhs.getZ();
}

DirVector DirVector::operator -=(const DirVector& rhs){
    vector[0] -= rhs.getX();
    vector[1] -= rhs.getY();
    vector[2] -= rhs.getZ();
}

DirVector operator +(const DirVector& lhs, const DirVector& rhs){
    DirVector thing(lhs);
    thing += rhs;
    return thing;
}

DirVector operator -(const DirVector& lhs, const DirVector& rhs){
    DirVector thing(lhs);
    thing -= rhs;
    return thing;
}