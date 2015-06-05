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

using namespace std;


void fill(vector<int> &numbers, int count){
	int size = count;
	while(count > 0){
	numbers.push_back(rand() % (size*2));
	count--;
  }
}

// bubble sort from talaga's examples
void bubbleSort(vector<int> &numbers){
  for(unsigned int runs = 0; runs < numbers.size(); runs++){
	bool swapped = false;
	for(unsigned int i = 0; i < numbers.size()-1; i++){
	  if(numbers[i] > numbers[i+1]){  //swap
		int temp = numbers[i];
		numbers[i] = numbers[i+1];
		numbers[i+1] = temp;
		swapped = true;
	  }
	}
	if(!swapped){
	  //cout << "Out for good behavior\n";
	  return;
	}
  }
}

//talaga
void quickSort(vector<int> &numbers, int first, int last){
	// sort the elements between (and including) start and end
	if(last-first < 1){ // 0
		return;
	}
	int so = first;
	int se = last;
	// put pivot at start location
	int pivot = first;
	int pv = numbers[pivot];
	while(last-first >= 1){
		if(numbers[first] == pv && numbers[last] == pv){
		  first++;
		}else if(numbers[first] >= pv && numbers[last] <= pv){ // switch
		  int temp = numbers[first];
		  numbers[first] = numbers[last];
		  numbers[last] = temp;
		  // don't change start or end
		}else if(numbers[last] > pv){
		  last--;
		}else if(numbers[first] < pv){ // low OK
		  first++;
		}else{
		  cout << "Something went wrong\n";
		  return;
		}
	}
	quickSort(numbers,so, first-1);
	quickSort(numbers,last+1,se);
}


void selectionSort(vector<int> &numbers) {
	int min, temp;
	for (int i = 0; i < numbers.size() -1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++)
			if (numbers[j] < numbers[min])
				min = j;
			if (min != i) {
				temp = numbers[i];
				numbers[i] = numbers[min];
				numbers[min] = temp;
		}
	}
}


bool isUnique1(vector<int> &numbers, int first, int last){ //Recursive validation
   /*Input: Array A, first, last
   Output:
true if the array contains no repeated elements
false if the array contains repeated elements*/
	if (first >= last) {return true};
	if (!isUnique1(numbers, first, last-1) {return false};
	if (!isUnique1(numbers, first+1, last) {return false};
	return(numbers[first]!=numbers[last])
}


bool isUnique2(vector<int> &numbers, int first, int last){ //Iterative validation
   /*Input: Array A, first, last
   Output:
true if the array contains no repeated elements
false if the array contains repeated elements*/
	if (first >= last) {return true;}
	for (int i =  first; i < last; i++) {
		for (int j = i+1; j <=last; j++) {
			if (numbers[i] == numbers[j]) {return false};
		}
	}
   return true;
}

bool isUnique3(vector<int> numbers, int first, int last, int sortType){ //Sorted validation
   /*Input: Array A, first, last
   Output:
true if the array contains no repeated elements
false if the array contains repeated elements*/
	if (sortType == 0) {
		bubbleSort(numbers);
	}
	else if (sortType == 1) {
		quickSort(numbers, first, last);
	} else {
		selectionSort(numbers);
	} if (first >= last) {return true;}
	for (int i =  first; i < last; i++) {
		if (numbers[i] == numbers[i+1]) {return false};
	}
   return true;
}


int main(){
	time_t start = time;
	time_t end = time;
	bool result = true;

	vector<int> numbers;
	fill(number, size);

	start = time;
	result = isUnique1(numbers, 0, numbers.size());
	end = time;
	cout << "Recursive Validation :: ";
	if (result == false) {
		 cout << "NOT ";
	}
	cout << "Unique! Time: " << ctime(difftime(end,start)) << endl;

	start = time;
	result = isUnique2(numbers, 0, numbers.size());
	end = time;
	cout << "Iterative Validation :: ";
	if (result == false) {
		 cout << "NOT ";
	}
	cout << "Unique! Time: " << ctime(difftime(end,start)) << endl;

	for (int sortType = 0; sortType <= 2; sortType++) {
		start = time;
		result = isUnique3(numbers, 0, numbers.size(), sortType);
		end = time;
		if (sortType == 0) {
			cout << "BubbleSort ";

		} else if (sortType == 1) {
			cout << "QuickSort ";
		} else {
			cout << "SelectionSort ";
		}
		cout << "Sorted Validation :: ";
		if (result == false) {
			 cout << "NOT ";
		}
		cout << "Unique! Time: " << ctime(difftime(end,start)) << endl;
	}

return 0;

}
