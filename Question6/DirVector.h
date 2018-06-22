/*
 */

/* 
 * File:   DirVector.h
 * Author: Jack L. Clements
 *
 * Created on 20 June 2018, 15:38
 */

#ifndef DIRVECTOR_H
#define DIRVECTOR_H

class DirVector{
private:
    float vector[3];
    
public:
    DirVector();
    DirVector(float x, float y, float z);
    DirVector(const DirVector& vec);
    
    
    //Accessor
    float getX() const;
    float getY() const;
    float getZ() const;
    
    //methods
    DirVector cross(const DirVector& vec);
    float dot(const DirVector& vec);
    void add(const DirVector& vec);
    void scalarMultiplication(float multiplier); //* every element
    void scalarDivision(float divisor);
    float magnitude();
    
    //operator overrides   
    DirVector operator +=(const DirVector& rhs);
    DirVector operator -=(const DirVector& rhs);
};

DirVector operator +(const DirVector& lhs, const DirVector& rhs);
DirVector operator -(const DirVector& lhs, const DirVector& rhs);

#endif /* DIRVECTOR_H */

