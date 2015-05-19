/*

Author: Stephen Enochian, Shannon Henderson, Kaitlyn Waters
Course Title: Data Structures
Course Number: CS2028
Instructor: Anca Ralescu
TA: Suryadip Chakraborty
Abstract:
Preconditions:
Postcondition:
Credit:

*/

#include <iostream>
#include <cmath>

using namespace std;



int shapeType (int shape) {
    int type = 0;
    switch (shape) {
        case 1: {
            //isosceles or equilateral
            cout << "Equilateral or Isosceles?" << endl
                 << "1 = Equilateral" << endl
                 << "2 = Isosceles" << endl;
                cin >> type;
            if (!cin) {
            cout << endl << "ERROR. Try again." << endl
                 << "Please start program again and enter 1 or 2." << endl;
                 break;
            }
            else if (type < 1 || type > 2) {
                cout << endl << "ERROR. Try again." << endl
                     << "Please start program again and enter 1 or 2." << endl;
                    break;
            }
            break;
        }
        case 2: {
            //rectangle or square 
            cout << "Rectangle or Square?" << endl
                 << "1 = Rectangle" << endl
                 << "2 = Square" << endl;
                cin >> type;
            if (!cin) {
                cout << endl << "ERROR. Try again." << endl
                     << "Please start program again and enter 1 or 2." << endl;
                break;
            }
            else if (type < 1 || type > 2) {
                cout << endl << "ERROR. Try again." << endl
                     << "Please start program again and enter 1 or 2." << endl;
                break;
            }
            break;
        }
    }
    return type;
}

void getSides(int shape, int type) {
    //get side lengths???????
    switch (shape){
        case 1: { //triangle
            switch (type){
                case 1: { 
                    //isosceles
                }
                case 2: { 
                    //equilateral
                }
            }
        }
        case 2: {//quadrilateral
            switch (type) {
                case 1: {
                    //rectangle   
                }
                case 2: {
                    //square   
                }
            }
        }
        case 3: {
            //pentagon   
        }
        case 4: {
            //hexagon   
        }
        case 5: {
            //octagon   
        }
    }
}

class Polygon {
    public:
    virtual float area() = 0;
    virtual float perimeter() = 0;
};

class Triangle : public Polygon {
    public:
    virtual float area() {
        return 0.0;
    }
    
    virtual float perimeter() {
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

int main () {
    int shape = 0;
    while (shape < 1 || shape > 5) {
        cout << endl << "Pick a shape:" << endl << endl
             << "1 = Triangle" << endl
             << "2 = Quadrilateral" << endl
             << "3 = Pentagon" << endl
             << "4 = Hexagon" << endl
             << "5 = Octagon" << endl;
        cin >> shape;
        if (!cin) {
            cout << endl << "ERROR. Try again." << endl
                 << "Please start program again and" << endl
                 << "enter a number from 1 to 5." << endl;
                 break; //creates infinite loop if char/string is entered
                        //how to repeat while loop after break?
        }
        else if (shape < 1 || shape > 5) {
            cout << endl << "ERROR. Try again." << endl
                 << "Please enter a number from 1 to 5." << endl;
                continue;
        }
    }
    
    int type = 0;
    switch (shape) {
        case 1: {
            //triangle
            type = shapeType(shape);
            getSides(shape, type);
            break;
        }
        case 2: {
            // quadrilateral
            type = shapeType(shape);
            getSides(shape, type);
            break;
        }
        case 3: {
            //pentagon
            getSides(shape, type);
            break;
        }
        case 4: {
            //hexagon 
            getSides(shape, type);
            break;
        }
        case 5: {
            //octagon
            getSides(shape, type);
            break;
        }
    }
    
    return 0;
}
