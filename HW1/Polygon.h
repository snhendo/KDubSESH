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

    Polygon() {

    }

    vector<int> getSides(int numSides);


    private:
    vector<int> sides;

};

class Triangle : public Polygon {
    public:
    virtual float area() {
        //something with trig
        return 0.0;
    }

    virtual float perimeter() {
        //sum of sides
        return 0.0;
    }
};

class IsoscelesTriangle : public Triangle {
    public:
    virtual float area() {
        return 0.0;
    }

    virtual float perimeter() {
        return 0.0;
    }
};

class EquilateralTriangle : public Triangle {
    public:
    virtual float area() {
        return 0.0;
    }
    virtual float perimeter() {
        return 0.0;
    }
};

class Quadrilateral : public Polygon {
    public:
    virtual float area() {
        return 0.0;
    }

    virtual float perimeter() {
        return 0.0;
    }
};

class Rectangle : public Quadrilateral {
    public:
    virtual float area() {
        return 0.0;
    }

    virtual float perimeter() {
        return 0.0;
    }
};

class Square : public Quadrilateral {
    public:
    virtual float area() {
        return 0.0;
    }

    virtual float perimeter() {
        return 0.0;
    }
};

class Pentagon : public Polygon {
    public:
    virtual float area() {
        return 0.0;
    }

    virtual float perimeter() {
        return 0.0;
    }
};

class Hexagon : public Polygon {
    public:
    virtual float area() {
        return 0.0;
    }

    virtual float perimeter() {
        return 0.0;
    }
};

class Octagon : public Polygon {
    public:
    virtual float area() {
        return 0.0;
    }

    virtual float perimeter() {
        return 0.0;
    }
};


#endif
