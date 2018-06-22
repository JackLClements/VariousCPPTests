/*
 */

#include "Triangle.h"

#define CROSS(n, a, b){n[0] = (a[1]*b[2]) - (a[2]*b[1]); n[1] = (a[0]*b[2]) - (a[2]*b[0]); n[2] = (a[0]*b[1]) - (a[1]*b[0]);}

Triangle::Triangle() {
    vertices = new float[9];
    colours = new float[9];
    normal = new float[3];
}

Triangle::Triangle(float* vertices, float* colours, float* normal) {
    this->vertices = vertices;
    this->colours = colours;
    this->normal = normal;
}

Triangle::Triangle(float ax, float ay, float az, float bx, float by, float bz, float cx, float cy, float cz) {
    vertices = new float[9];
    colours = new float[9];
    normal = new float[3];

    vertices[0] = ax;
    vertices[1] = ay;
    vertices[2] = az; //vertex 1
    vertices[3] = bx;
    vertices[4] = by;
    vertices[5] = bz; //vertex 2
    vertices[6] = cx;
    vertices[7] = cy;
    vertices[8] = cz; //vertex 3

    //colours
    colours[0] = ax;
    colours[1] = ay;
    colours[2] = az; //vertex 1, Red/Green/Blue
    colours[3] = bx;
    colours[4] = by;
    colours[5] = bz; //vertex 2, Red/Green/Blue
    colours[6] = cx;
    colours[7] = cy;
    colours[8] = cz; //vertex 3, Red/Green/Blue


    calculateNormal();
}

Triangle::Triangle(const Triangle& triangle) {
    vertices = new float[9];
    colours = new float[9];
    normal = new float[3];
    
    for(int i = 0; i < 9; i++){
        vertices[i] = triangle.vertices[i];
        colours[i] = triangle.colours[i];
    }
    for(int i = 0; i < 3; i++){
        normal[i] = triangle.normal[i];
    }  
}

Triangle::~Triangle() {
    delete [] vertices;
    delete [] colours;
    delete [] normal;
}

//cross product of A and B

void Triangle::calculateNormal() {
    //Non-parallel edge vectors
    float edge1[3];
    float edge2[3];
    for (int i = 0; i < 3; i++) {
        edge1[i] = vertices[i + 3] - vertices[i];
        edge2[i] = vertices[i + 6] - vertices[i];
    }

    //Cross product
    CROSS(normal, edge1, edge2);
}

float* Triangle::getVertices() const {
    return vertices;
}

float* Triangle::getColours() const {
    return colours;
}

float* Triangle::getNormal() const {
    return normal;
}

float Triangle::getNormalAt(int i) {
    return normal[i];
}