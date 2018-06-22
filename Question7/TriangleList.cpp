/*
 */

#include "TriangleList.h"


TriangleList::TriangleList(){
    
}

TriangleList::TriangleList(TriangleList& list){
    
}

TriangleList::~TriangleList(){
    
}

void TriangleList::add(Triangle triangle){
    triangles.push_back(triangle);
}

Triangle TriangleList::at(int i){
    return triangles.at(i);
}

int TriangleList::size(){
    return triangles.size();
}