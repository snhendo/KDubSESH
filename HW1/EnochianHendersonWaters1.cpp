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

vector<int> Polygon::getSides(int numSides) {
    int temp = 0;
    for (int i = 0; i < numSides; i++) {
        cout << "Side length " << i+1 << ": " << endl;
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
    int numSides = 1;
    vector<int> sides;
    switch (shape) {
        case 1: {//triangle
            type = shapeType(shape);
            if (type == 2) { numSides = 3; }
            sides = a->getSides(numSides);
            break;
        }
        case 2: {// quadrilateral
            type = shapeType(shape);
            if (type == 1) { numSides = 2; }
            sides = a->getSides(numSides);
            break;
        }
        case 3: {//pentagon
            sides = a->getSides(numSides);
            break;
        }
        case 4: {//hexagon
            sides = a->getSides(numSides);
            break;
        }
        case 5: {//octagon
            sides = a->getSides(numSides);
            break;
        }
    }

    return 0;
}
