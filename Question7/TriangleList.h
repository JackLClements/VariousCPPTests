/*
 */

/* 
 * File:   TriangleList.h
 * Author: Jack L. Clements
 *
 * Created on 20 June 2018, 21:48
 */

#include "Triangle.h"
#include <vector>

#ifndef TRIANGLELIST_H
#define TRIANGLELIST_H

class TriangleList{
private:
    std::vector<Triangle> triangles;
    
public:
    TriangleList();
    TriangleList(TriangleList& list);
    ~TriangleList();
    
    void add(Triangle triangle);
    Triangle at(int i);
    int size();
};

#endif /* TRIANGLELIST_H */

