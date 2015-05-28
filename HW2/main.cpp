/*
20CS2028Assignment2-2015
Authors: Stephen Enochian, Shannon Henderson, Kaitlyn Waters
Course: Data Structures
Course Number: CS2028
Instructor: Anca Ralescu
TA: Suryadip Chakraborty
Abstract: Assignment 2 main.cpp uses three algorithms (Algorithm isUnique1 (A, first, last), Algorithm isUnique2 (A, first, last), and Algorithm isUnique3 (A, first last)) to ensure that an array does not have any repeated elements as well as check that two arrays of the same size and type represent the same set.
Preconditions: N/A
Postconditions: N/A
*/

#include<iostream>
#include<cmath>
#include<ctime>

using namespace std;

int main(){

bool Algorithm isUnique1(A, first, last){
   /*Input: Array A, first, last
   Output:
true if the array contains no repeated elements
false if the array contains repeated elements*/
   if (first >= last)
return true;
    if (!isUnique1(A, first, last-1) {return false};
    if (!isUnique1(A, first+1, last) {return false};
    return(A[first]!=A[last])
}


bool Algorithm isUnique2(A, first, last){
   /*Input: Array A, first, last
   Output:
true if the array contains no repeated elements
false if the array contains repeated elements*/
    if (first >= last) {return true;}
    for (int i =  first; i < last; i++) {
        for (int j = i+1; j <=last; j++) {
            if (A[i] == A[j]) {return false};
        }
    }
   return true;
}

bool Algorithm isUnique3(A, first, last){
   /*Input: Array A, first, last
   Output:
true if the array contains no repeated elements
false if the array contains repeated elements*/
    if (first >= last) {return true;}
   SORT(A, first, last); // lol wut
    for (int i =  first; i < last; i++) {
        if (A[i] == A[i+1]) {return false};
    }
   return true;
}

return 0;

}
