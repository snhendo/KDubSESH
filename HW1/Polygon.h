#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Polygon {
    public:
    virtual float area() = 0;
    virtual float perimeter() = 0;
};

class Triangle : public Polygon {
    public:
    virtual float area() {return 0.0;}
    virtual float perimeter() {return 0.0;}
};

class IsoscelesTriangle : public Triangle {
    public:

    IsoscelesTriangle(vector<float> sides) { //constructor
        side1 = sides[0];
        side2 = sides[1];
        side3 = sides[2];
    }

    virtual float area() {
        float base = 0;
        float s = 0;
        if (side1 == side2){
            base = side3;
            s = side2;
        }
        else if (side2 == side3) {
            base = side1;
            s = side3;
        }
        else {
            base = side2;
            s = side1;
        }
        float result = (.5)*pow(base,2)*sqrt((pow(s,2)/pow(base,2))-(.25));
        return result;
    }

    virtual float perimeter() {
        return side1 + side2 + side3;
    }

    private:
    float side1, side2, side3;

};

class EquilateralTriangle : public Triangle {
    public:
    EquilateralTriangle(vector<float> sides){
        side1 = sides[0];
    }

    virtual float area() {
        float result = (sqrt(3)/4)*pow(side1,2);
        return result;
    }
    virtual float perimeter() {
        return 3*side1;
    }

    private:
    float side1;
};

class Quadrilateral : public Polygon {
    public:
    virtual float area() {return 0.0;}

    virtual float perimeter() {return 0.0;}
};

class Rectangle : public Quadrilateral {
    public:
    Rectangle(vector<float> sides){
        side1 = sides[0];
        side2 = sides[1];
    }
    virtual float area() {
        return side1*side2;
    }

    virtual float perimeter() {
        return (2*side1)+(2*side2);
    }

    private:
    float side1, side2;
};

class Square : public Quadrilateral {
    public:
    Square(vector<float> sides){
        side1 = sides[0];
    }

    virtual float area() {
        return pow(side1,2);
    }

    virtual float perimeter() {
        return 4*side1;
    }

    private:
    float side1;
};

class Pentagon : public Polygon {
    public:
    Pentagon(vector<float> sides){
        side1 = sides[0];
    }

    virtual float area() {
        float result = (.25)*sqrt(5*(5+2*sqrt(5)))*pow(side1,2);
        return result;
    }

    virtual float perimeter() {
        return 5*side1;
    }

    private:
    float side1;
};

class Hexagon : public Polygon {
    public:
    Hexagon(vector<float> sides){
        side1 = sides[0];
    }

    virtual float area() {
        float result = (3*sqrt(3)*pow(side1,2))/2;
        return result;
    }

    virtual float perimeter() {
        return 6*side1;
    }

    private:
    float side1;
};

class Octagon : public Polygon {
    public:
    Octagon(vector<float> sides){
        side1 = sides[0];
    }
    virtual float area() {
        float result = 2*(1+sqrt(2))*pow(side1,2);
        return result;
    }

    virtual float perimeter() {
        return 8*side1;
    }

    private:
    float side1;
};


#endif