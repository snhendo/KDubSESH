/* 20CS2028 Data Structures Assignment #6 - Due July 30, 2015
Author: Stephen Enochian, Shannon Henderson, Kaitlyn Waters
Course title: Data Structures
Course number: CS2028
Instructor: Anca Ralescu
TA: Suryadip Chakraborty
Abstract: This program stores and reads information in a hash table.
Preconditions: This program sorts integers only.
Postconditions: None
Credit: Referred to Dr. Talaga's examples from CS2, consulted the web for various sorts
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

int main () {
    cout << "Assignment #6" << endl << endl;
    cout << "Select your collision resolution scheme:\n(a) Double Hashing\n(b) Quadritic\n(c) Chaining within the Hash Table\n";
    char collisionResolutionSelection = '';
    cin >> collisionResolutionSelection;
    if (collisionResolutionSelection < 'a' || collisionResolutionSelection > 'c') {
        return 0;
    }
    cout << "What load ratio would you like to use? Enter a value between 0 and 1.0" endl;
    float loadRatio = 0.0;
    cin >> loadRadio;
    return 0;
}
