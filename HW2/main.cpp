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
		  Algorithm isUnique3 (A, first, last),
		  to ensure that an array does not have any repeated elements as well as
		  check that two arrays of the same size and type represent the same set.
Preconditions: N/A
Postconditions: N/A
Credit: Used examples from CS2/Dr. Paul Talaga
*/

#include<iostream>
#include<cmath>
#include<ctime>
#include<vector>
#include<cstdlib>

using namespace std;


void fill(vector<int> &numbers, int count){ // fill takes a vector of numbers and the number of elements desired by the user
	int size = count;
	while(count > 0){ // as long as count is greater than zero...
	numbers.push_back(rand() % (size*2)); // fills the vector of numbers with random integers
	count--; // decrements count
  }
}

void print(vector<int> &numbers){ // print prints the vector's entries
	cout << "vector = [";
	for(int i = 0; i < numbers.size(); i++){ // steps through the vector and prints each element
		cout << numbers[i] << ",";
	}
	cout << "]" << endl;
}

// bubble sort from Dr. Talaga's examples from CS2
void bubbleSort(vector<int> &numbers){ // bubbleSort takes a vector of numbers
	for(unsigned int i = 0; i < numbers.size(); i++){ // for will execute for the number of elements in the vector
		bool swapped = false; // initialize swapped variable and set to false (to be switched to true later)
		for(unsigned int j = 0; j < numbers.size()-1; j++){ // second for loop actually takes care of swapping of elements
			if(numbers[j] > numbers[j+1]){  // if the next element is greater than the current element, swap them
				int temp = numbers[j]; // set a temporary variable to hold the current element
				numbers[j] = numbers[j+1]; // set the current position to equal the next element
				numbers[j+1] = temp; // put the "current" element in the next position
				swapped = true; // changed swap to true
		  }
		}
		if(!swapped){return;} // when swapped is false, everything is sorted, so we leave the function
	}
}

// merge and mergeSort functions (referred to Dr. Talaga's examples from CS2 (and previous homeworks from CS2)
vector<int> merge(vector<int> &left, vector<int> &right){ // merge takes in the 2 vectors (right and left "sides") and merges them
	vector<int> result; // initialize result (will store the left/right merged together)
	unsigned i = 0; // initialize i and j for while loop
	unsigned j = 0;
	while(i < left.size() || j < right.size()){ // as long as the left or right sides have a size greater than whatever i and j equal, the loop will execute
	  if( i == left.size()){ // when i is equal to the size of the left vector (end of the left vector), it will push the element from the right vector into the result vector and increment j (move to next position in the right vector)
		result.push_back(right[j]);
		j++;
	  }else if( j == right.size()){ // if j is equal to the size of the right vector (end of the right vector), it will push the element from the left vector into the result vector and increment i (move to next position in the left vector)
		result.push_back(left[i]);
		i++;
	  }else if(left[i] < right[j]){ // if the element in the i-th position of the left vector is of lesser value than the element in the j-th position of the right vector, the element in the left vector is pushed into the result vector and i is incremented (move to next position in the left vector)
		result.push_back(left[i]);
		i++;
	  }else{ // otherwise, we assume that the element in the j-th position of the right vector is less than the element in the i-th position of the left vector, so we push the element in the right vector to the result vector and j is incremented (move to next position in the right vector)
		result.push_back(right[j]);
		j++;
	  }
	}
	return result; // return the merged vector
  }

  void mergeSort(vector<int> &v){ // mergeSort sorts a vector
	if(v.size() <= 1){ // if size is 0 or 1, it's safe to assume that the vector is sorted
	  return; // leave the function
	}
	unsigned split = v.size() / 2; // will split the vectors in two, so we create a split variable to use for comparison later
	vector<int> left; // initialize the left side (vector)
	vector<int> right; // initialize the right side (vector)
	for(unsigned i = 0; i < v.size(); i++){ // for loop designed to push elements into each vector
	  if( i < split){ // first half of the merged vector will be pushed into the left vector
		left.push_back(v[i]);
	  }else{
		right.push_back(v[i]); // second half will be pushed into the right vector
	  }
	}
	mergeSort(left); // recursively calls mergesSort on the left hand side (breaks down the left vector until there's only one element
	mergeSort(right); // recursively calls mergeSort on the right hand side (breaks down the right vector until there's only one element
	v = merge(left,right); // merges the left and right vectors together to complete the sorting process
  }


void selectionSort(vector<int> &numbers) { // selectionSort takes in a vector
	int min, temp; // initialize minimum and temp variable
	for (int i = 0; i < numbers.size() -1; i++) { // for loop sets i as the min (steps through each element of the vector for comparison with the following elements (will be compared in the next for loop)
		min = i;
		for (int j = i + 1; j < numbers.size(); j++) // for loop compares the min to elements throughout the rest of the vector and swaps if necessary
			if (numbers[j] < numbers[min]) // if the element in the j-th position is less than the element at the min position
				min = j; // set min to equal the j-th position
			if (min != i) { // if min is set to the j-th position (previous if statement)
				temp = numbers[i]; // set temp equal to the element at the i-th position
				numbers[i] = numbers[min]; // change the element in the i-th position to the element at the min position
				numbers[min] = temp; // set the element that is at the min position to the element that was at the i-th position
		}
	}
}


bool isUnique1(vector<int> &numbers, int first, int last){ //Recursive validation, takes in a vector of numbers and the first and last value (positions of the elements in the vectors) -- other isUnique algorithms take in the same parameters (isUnique3 takes an additional parameter, sortType) and checks uniqueness through various methods (iterative and sorted)
   /*Input: Array A, first, last
   Output:
true if the array contains no repeated elements
false if the array contains repeated elements*/
	if (first >= last) {return true;} // if there's one element in the vector, it's unique (only one position) -- base case
	if (!isUnique1(numbers, first, last-1)) {return false;} // recursively calls isUnique1 to compare the first and second to last position
	if (!isUnique1(numbers, first+1, last)) {return false;} // recursively calls isUnique1 to compare the second and last position
	return (numbers[first]!=numbers[last]); // returns the result of checking if the elements in those positions are equal
}


bool isUnique2(vector<int> &numbers, int first, int last){ //Iterative validation
   /*Input: Array A, first, last
   Output:
true if the array contains no repeated elements
false if the array contains repeated elements*/
	//print(numbers); // prints the vector of numbers
	if (first >= last) {return true;} // if the first and last are equal, it's unique (only one position)
	for (int i = first; i < last; i++) { // iterates through the vector
		for (int j = i+1; j <=last; j++) { // looks at the next element and goes through the remainder of the vector
			if (numbers[i] == numbers[j]) {return false;} // if any values in the vector are the same, the vector is not unique
		}
	}
	//print(numbers); // print the vector
   return true; //if it successfully goes through the for loop without having any duplicated values, then the vector is unique
}

bool isUnique3(vector<int> numbers, int first, int last, int sortType){ //Sorted validation, takes in sort type to determine which method is faster
   /*Input: Array A, first, last
   Output:
true if the array contains no repeated elements
false if the array contains repeated elements*/
	if (sortType == 0) { // bubbleSort
		//print(numbers); // prints unsorted vector
		bubbleSort(numbers); // sorts the vector using bubbleSort
		//print(numbers); // prints sorted vector
	}
	else if (sortType == 1) { // mergeSort
		//print(numbers); // prints unsorted vector
		mergeSort(numbers); // sorts the vector using mergeSort
		//print(numbers); // prints sorted vector
	} else { // selectionSort
		//print(numbers); // prints unsorted vector
		selectionSort(numbers); // sorts the vector using selectionSort
		//print(numbers); // prints sorted vector
	} if (first >= last) {return true;} // if first and last are the same, the solution will be unique
	for (int i =  first; i < last; i++) { // if they're not the same, for loop will check the values of the vector and check for duplicates
		if (numbers[i] == numbers[i+1]) {return false;} // if any duplicates are detected, the vector is not unique
	}
   return true; // if no duplicates are found, the vector is unique
}


int main(){
	clock_t start = clock(); // initializes timing variables to be able to time sorting methods later in the code
	clock_t end = clock();
	bool result = true; // initializes result
	int size = 0; // initializes size

	cout << "Enter the number of elements for the vector: " << endl; // prompt user for the number of elements they want in the vector, which will be saved as the size
	cin >> size;

	vector<int> numbers; // initialize the vector of numbers
	srand(time(0)); // randomizes the rand
	fill(numbers, size); // calls fill function to fill vector with random elements (vector will be the size that the user determined earlier)
	print(numbers); // prints the vector (unsorted)
	start = clock(); //starts timer
	result = isUnique1(numbers, 0, numbers.size()); // calls the isUnique1 function (recursive check) with first = 0 and last = numbers.size()
	end = clock(); // ends timer
	//print(numbers); // prints vector
	cout << "Recursive Validation :: "; // prints a statement to the user saying whether the vector is unique or not unique
	if (result == false) {
		 cout << "NOT ";
	}
	cout << "Unique! Time: " << (float)(end-start)*1000/(float)CLOCKS_PER_SEC << endl; // prints out the time it took to determine uniqueness of the vector

	start = clock(); // start timer
	result = isUnique2(numbers, 0, numbers.size()); // calls the isUnique2 function (iterative check) with first = 0 and last = numbers.size()
	end = clock(); // end timer
	cout << "Iterative Validation :: "; // prints a statement to the user saying whether the vector is unique or not unique
	if (result == false) {
		 cout << "NOT ";
	}
	cout << "Unique! Time: " << (float)(end-start)*1000/(float)CLOCKS_PER_SEC << endl; // prints out the time it took to determine uniqueness of the vector

	for (int sortType = 0; sortType <= 2; sortType++) { // for loop enables the same set of functions to be run for each sortType
		start = clock(); // start timer
		result = isUnique3(numbers, 0, numbers.size(), sortType); // set result vector to equal whatever is returned by using the given sorting method and calling isUnique3 with that sorting method
		end = clock(); // end timer
		if (sortType == 0) {
			cout << "BubbleSort "; // print out the sorting method used
		} else if (sortType == 1) {
			cout << "MergeSort ";
		} else {
			cout << "SelectionSort ";
		}
		cout << "Sorted Validation :: "; // prints a statement to the user saying whether the vector is unique or not unique
		if (result == false) {
			 cout << "NOT ";
		}
		cout << "Unique! Time: " << (float)(end-start)*1000/(float)CLOCKS_PER_SEC << endl; // prints out the time it took to determine uniqueness of the vector
	}

return 0;

} // end of main function (and main.cpp)
