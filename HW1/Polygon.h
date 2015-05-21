#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Polygon {
    public:
    virtual float area() = 0; // initialize area function
    virtual float perimeter() = 0; // initialize perimeter function
};

class Triangle : public Polygon { // Triangle inherits from Polygon
    public:
    virtual float area() {return 0.0;} // initializes Triangle area (dependent on type of triangle)
    virtual float perimeter() {return 0.0;} // initializes Triangle perimeter (dependent on type of triangle)
};

class IsoscelesTriangle : public Triangle { // IsoscelesTriangle inherits from Triangle
    public:

    IsoscelesTriangle(vector<float> sides) { //constructor
        side1 = sides[0]; // assigns each element in the vector to a variable that can be used within this function
        side2 = sides[1];
        side3 = sides[2];
    }

    virtual float area() {
        float base = 0; // initialize base
        float s = 0; // initialize s
        if (side1 == side2){ // legs
            base = side3; // if the 2 legs are equal, the last side avaialable will be the base
            s = side2; // s = side 2 because it is equal to side 1
        }
        else if (side2 == side3) { // legs
            base = side1; // if the 2 legs are equal, the last side available will be the base
            s = side3; // s = side 3 because it is equal to side 2
        }
        else {
            base = side2; // (assuming that sides 1 and 3 are the equal sides)
            s = side1; // s = side 1 because it is equal to side 3
        }
        float result = (.5)*pow(base,2)*sqrt((pow(s,2)/pow(base,2))-(.25)); // calculate area using base and sides (rather than using 1/2xbasexheight
        return result; // return the area
    }

    virtual float perimeter() {
        return side1 + side2 + side3; // calculate perimeter and return the result
    }

    private:
    float side1, side2, side3; // initialize sides 1-3

};

class EquilateralTriangle : public Triangle { // EquilateralTriangle inherits from Triangle
    public:
    EquilateralTriangle(vector<float> sides){ // constructor
        side1 = sides[0]; // initialize side 1 to the first entry of side (because it's an equilateral triangle)
    }

    virtual float area() {
        float result = (sqrt(3)/4)*pow(side1,2); // calculate area
        return result; // return the area
    }
    virtual float perimeter() {
        return 3*side1; // return the calculated result for the perimeter of the triangle
    }

    private:
    float side1; // initialize side 1
};

class Quadrilateral : public Polygon { // Quadrilateral inherits from Polygon
    public:
    virtual float area() {return 0.0;} // initialize area function

    virtual float perimeter() {return 0.0;} // initialize perimeter function
};

class Rectangle : public Quadrilateral { // Rectangle inherits from Quadrilateral
    public:
    Rectangle(vector<float> sides){ // constructor
        side1 = sides[0];
        side2 = sides[1];
    }
    virtual float area() {
        return side1*side2; // return the calculated area
    }

    virtual float perimeter() {
        return (2*side1)+(2*side2); // return the calculated perimeter
    }

    private:
    float side1, side2; // initialize private variables (sides)
};

class Square : public Quadrilateral { // Square inherits from Quadrilateral
    public:
    Square(vector<float> sides){ // constructor
        side1 = sides[0];
    }

    virtual float area() {
        return pow(side1,2); // return the calculated area
    }

    virtual float perimeter() {
        return 4*side1; // return the calculated perimeter
    }

    private:
    float side1; // initialize private variable (side)
};

class Pentagon : public Polygon { // Pentagon inherits from Polygon
    public:
    Pentagon(vector<float> sides){ // constructor
        side1 = sides[0];
    }

    virtual float area() {
        float result = (.25)*sqrt(5*(5+2*sqrt(5)))*pow(side1,2); // calculate area
        return result; // return area
    }

    virtual float perimeter() {
        return 5*side1; // return the calculated perimeter
    }

    private:
    float side1; // initialize private variable (side)
};

class Hexagon : public Polygon { // Hexagon inherits from Polygon
    public:
    Hexagon(vector<float> sides){ // constructor
        side1 = sides[0];
    }

    virtual float area() {
        float result = (3*sqrt(3)*pow(side1,2))/2; // calculate area
        return result; // return area
    }

    virtual float perimeter() {
        return 6*side1; // return the calculated perimeter
    }

    private:
    float side1; // initialize private variable (side)
};

class Octagon : public Polygon { // Octagon inherits from Polygon
    public:
    Octagon(vector<float> sides){ // constructor
        side1 = sides[0];
    }
    virtual float area() {
        float result = 2*(1+sqrt(2))*pow(side1,2); // calculate area
        return result; // return area
    }

    virtual float perimeter() {
        return 8*side1; // return the calculated perimeter
    }

    private:
    float side1; // initialize private variable (side)
};


#endif
