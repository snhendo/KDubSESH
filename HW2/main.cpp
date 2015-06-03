/*
20CS2028Assignment2-2015
Authors: Stephen Enochian, Shannon Henderson, Kaitlyn Waters
Course: Data Structures
Course Number: CS2028
Instructor: Anca Ralescu
TA: Suryadip Chakraborty
Abstract: Assignment 2 main.cpp uses three algorithms:
          Algorithm isUnique1(A, first, last)
          Algorithm isUnique2 (A, first, last)
          Algorithm isUnique3 (A, first last),
          to ensure that an array does not have any repeated elements as well as
          check that two arrays of the same size and type represent the same set.
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


// bubble sort from talaga's examples
//i think we're supposed to use arrays not vectors?
void bubbleSort(vector<int> &v){
  for(unsigned int runs = 0; runs < v.size(); runs++){
    bool swapped = false;
    for(unsigned int i = 0; i < v.size()-1; i++){
      if(v[i] > v[i+1]){  // swap needed!
        int temp = v[i];
        v[i] = v[i+1];
        v[i+1] = temp;
        swapped = true;
      }
    }
    if(!swapped){
      //cout << "Out for good behavior\n";
      return;
    }
  }
}

return 0;

}
