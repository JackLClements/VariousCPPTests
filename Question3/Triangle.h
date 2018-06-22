/*
 */

/* 
 * File:   Triangle.h
 * Author: Jack L. Clements
 *
 * Created on 19 June 2018, 19:57
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle{
private:
    float* vertices; //Ax/Ay/Az/Bx/By/Bz/Cx/Cy/Cz
    float* colours; //Red/Green/Blue
    float* normal; //x/y/z
public:
    Triangle();
    Triangle(float* vertices, float* colours, float* normal);
    Triangle(float ax, float ay, float az, float bx, float by, float bz, float cx, float cy, float cz);
    Triangle(const Triangle& triangle);
    ~Triangle();
    
    float* getVertices() const;
    float* getColours() const;
    float* getNormal() const;
    void calculateNormal();
    float getNormalAt(int i); //method for testing
};

#endif /* TRIANGLE_H */

