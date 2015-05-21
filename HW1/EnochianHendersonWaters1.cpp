/*

Authors: Stephen Enochian, Shannon Henderson, Kaitlyn Waters
Course Title: Data Structures
Course Number: CS2028
Instructor: Anca Ralescu
TA: Suryadip Chakraborty
Abstract: This program uses the abstract interface Polygon and abstract functions area() and perimeter() to implement classes for a variety of polygons and to compute their respective areas and perimeters.
Preconditions: None.
Postcondition: None.
Credit: N/A.

*/

#include <iostream>
#include <cmath>
#include <vector>
#include "Polygon.h"

using namespace std;



int shapeType (int shape) {
    int type = 0; // initializes type variable to be used later in the code
    switch (shape) {
        case 1: {
            //isosceles or equilateral
            cout << "Equilateral or Isosceles?" << endl
                 << "1 = Equilateral" << endl
                 << "2 = Isosceles" << endl;
                cin >> type; // stores type of triangle in type variable
            if (!cin || type < 1 || type > 2) { // checks to make sure user either entered a 1 or a 2
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
                cin >> type; // stores type of quadrilateral in type variable
            if (!cin || type < 1 || type > 2) { // checks that user entered either a 1 or a 2
                cout << endl << "ERROR. Try again." << endl
                     << "Please start program again and enter 1 or 2." << endl;
                break;
            }
            break;
        }
    }
    return type; // returns the type of polygon to be used later in the program
}



vector<float> getSides(vector<float> sides, int numSides) {
    float temp = 0.0; // initializes a temp variable so user input can be stored
    for (int i = 0; i < numSides; i++) { // for loop that prompts user for side lengths of each side of polygon
        cout << "Input Side Length: " << endl
             << "(assuming equal side lengths for penta/hexa/octagons)" << endl;
        cin >> temp; // stores the value in the temp variable
        sides.push_back(temp); // pushes value into a vector (sides)
    }
    return sides; // returns the completed vector to be used later in the program
}



int main () {
    int shape = 0; // initialize shape variable
    while (shape < 1 || shape > 5) { // checks that shape variable will be between 1 and 5
        cout << endl << "Pick a shape:" << endl << endl
             << "1 = Triangle" << endl
             << "2 = Quadrilateral" << endl
             << "3 = Pentagon" << endl
             << "4 = Hexagon" << endl
             << "5 = Octagon" << endl;
        cin >> shape;
        if (!cin || shape < 1 || shape > 5) { // if user doesn't enter a value or a number between 1 and 5
            cout << endl << "ERROR. Try again." << endl
                 << "Please start program again and" << endl
                 << "enter a number from 1 to 5." << endl;
                 break;
        }
    }

    int type = 0; // initialize type variable
    int numSides = 1; // initialize the number of sides
    vector<float> sides; // initialize the vector of side lengths
    Polygon* poly; // create new polygon
    switch (shape) {
        case 1: {//triangle
            type = shapeType(shape); // calls shapeType function to find out the type of triangle
            if (type == 2) {numSides = 3;} // if Isosceles
            sides = getSides(sides, numSides); // calls getSides function to retrieve side lengths from user
            if (type == 2) {
                if (sides[0] != sides[1] && sides[1] != sides[2] && sides[0] != sides[2]){ // checks to make sure at least 2 sides are equal
                    cout << "Two of the side lengths must be equal for an Isosceles" << endl
                         << "triangle. Please restart the program and try again" << endl;
                    break;
                }
                else{poly = new IsoscelesTriangle(sides);} // calls IsoscelesTriangle function
            }
            else{poly = new EquilateralTriangle(sides);} // calls Equilateral Triangle function (only 1 side length is needed)
            break;
        }
        case 2: {// quadrilateral
            type = shapeType(shape); // calls shapeType function to find out the type of quadrilateral
            if (type == 1) {numSides = 2;} // if Rectangle (only 2 side lengths are needed)
            sides = getSides(sides, numSides); // calls getSides function to retrieve side lengths
            if (type == 1) {poly = new Rectangle(sides);} // if Rectangle, poly = a rectangle with the side lengths entered by user
            else{poly = new Square(sides);} // otherwise poly = a square with a side length entered by a user
            break;
        }
        case 3: {//pentagon
            sides = getSides(sides, numSides); // retrieves the side lengths of a regular pentagon (1 value entered by user)
            poly = new Pentagon(sides); // the polygon is a Pentagon with the side lengths provided by the user
            break;
        }
        case 4: {//hexagon
            sides = getSides(sides, numSides); // retrieves the side lengths of a regular hexagon (1 value entered by user)
            poly = new Hexagon(sides); // the polygon is a Hexagon with the side lengths provided by the user
            break;
        }
        case 5: {//octagon
            sides = getSides(sides, numSides); // retrieves the side lengths of a regular octagon (1 value entered by user)
            poly = new Octagon(sides); // the polygon is an Octagon with side lengths provided by the user
            break;
        }
    }
    cout << "Area = " << poly->area() << endl; // calculates the area of the polygon using the appropriate Area function (calculations)
    cout << "Perimeter = " << poly->perimeter() << endl; // calculates the perimeter of the polygon using the appropriate Perimeter function (calculations)

    //poly = NULL;
    //delete poly;
    return 0; // end of main function
}
