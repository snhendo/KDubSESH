/*

Authors: Stephen Enochian, Shannon Henderson, Kaitlyn Waters
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
#include <vector>
#include "Polygon.h"

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
            if (!cin || type < 1 || type > 2) {
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
            if (!cin || type < 1 || type > 2) {
                cout << endl << "ERROR. Try again." << endl
                     << "Please start program again and enter 1 or 2." << endl;
                break;
            }
            break;
        }
    }
    return type;
}



vector<float> getSides(vector<float> sides, int numSides) {
    float temp = 0.0;
    for (int i = 0; i < numSides; i++) {
        cout << "Input Side Length: " << endl
             << "(assuming equal side lengths for penta/hexa/octagons)" << endl;
        cin >> temp;
        sides.push_back(temp);
    }
    return sides;
}



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
        if (!cin || shape < 1 || shape > 5) {
            cout << endl << "ERROR. Try again." << endl
                 << "Please start program again and" << endl
                 << "enter a number from 1 to 5." << endl;
                 break; //creates infinite loop if char/string is entered
                        //how to repeat while loop after break?
        }
    }

    int type = 0;
    int numSides = 1;
    vector<float> sides;
    Polygon* poly;
    switch (shape) {
        case 1: {//triangle
            type = shapeType(shape);
            if (type == 2) {numSides = 3;}
            sides = getSides(sides, numSides);
            if (type == 2) {
                if (sides[0] != sides[1] && sides[1] != sides[2] && sides[0] != sides[2]){
                    cout << "Two of the side lengths must be equal for an Isosceles" << endl
                         << "triangle. Please restart the program and try again" << endl;
                    break;
                }
                else{poly = new IsoscelesTriangle(sides);}
            }
            else{poly = new EquilateralTriangle(sides);}
            break;
        }
        case 2: {// quadrilateral
            type = shapeType(shape);
            if (type == 1) {numSides = 2;}
            sides = getSides(sides, numSides);
            if (type == 1) {poly = new Rectangle(sides);}
            else{poly = new Square(sides);}
            break;
        }
        case 3: {//pentagon
            sides = getSides(sides, numSides);
            poly = new Pentagon(sides);
            break;
        }
        case 4: {//hexagon
            sides = getSides(sides, numSides);
            poly = new Hexagon(sides);
            break;
        }
        case 5: {//octagon
            sides = getSides(sides, numSides);
            poly = new Octagon(sides);
            break;
        }
    }
    cout << "Area = " << poly->area() << endl;
    cout << "Perimeter = " << poly->perimeter() << endl;

    // = NULL;
    //delete poly;
    return 0;
}
