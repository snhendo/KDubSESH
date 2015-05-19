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
                 break;
        }
        else if (shape < 1 || shape > 5) {
            cout << endl << "ERROR. Try again." << endl
                 << "Please enter a number from 1 to 5." << endl;
                continue;
        }
    }
}

class Polygon {
    virtual float area() = 0;
    virtual float perimeter() = 0;
};

class Triangle : public Polygon {
    //virtual area ()
};

class IsoscelesTriangle : public Triangle {
    
};

class EquilateralTriangle : public Triangle {
    
};

class Quadrilateral : public Polygon {
    
};

class Rectangle : public Quadrilateral {
    
};

class Square : public Quadrilateral {
    
};

class Pentagon : public Polygon {
    
};

class Hexagon : public Polygon {
    
};

class Octagon : public Polygon {
    
};
