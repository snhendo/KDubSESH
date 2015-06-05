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


void fill(vector<int> &numbers, int count){
	int size = count;
	while(count > 0){
	numbers.push_back(rand() % (size*2));
	count--;
  }
}

void print(vector<int> &numbers){
	cout << "vector = [";
	for(int i = 0; i < numbers.size(); i++){
		cout << numbers[i] << ",";
	}
	cout << "]" << endl;
}

// bubble sort from talaga's examples
void bubbleSort(vector<int> &numbers){
	for(unsigned int i = 0; i < numbers.size(); i++){
		bool swapped = false;
		for(unsigned int j = 0; j < numbers.size()-1; j++){
			if(numbers[j] > numbers[j+1]){  //swap
				int temp = numbers[j];
				numbers[j] = numbers[j+1];
				numbers[j+1] = temp;
				swapped = true;
		  }
		}
		if(!swapped){return;}
	}
}

//talaga
/*
void quickSort(vector<int> &v, int start, int end){
  // sort the elements between (and including) start and end
  if(end-start < 1){ // 0
	return;
  }
  int so = start;
  int se = end;
  // put pivot at start location
  int pivot = start;
  int pv = v[pivot];
  while(end-start >= 1){
	if(v[start] == pv && v[end] == pv){
	  start++;
	}else if(v[start] >= pv && v[end] <= pv){ // switch
	  int temp = v[start];
	  v[start] = v[end];
	  v[end] = temp;
	  // don't change start or end
	}else if(v[end] > pv){
	  end--;
	}else if(v[start] < pv){ // low OK
	  start++;
	}else{
	  cout << "something went wrong";
	  return;
	}
  }
  quickSort(v,so, start-1);
  quickSort(v,end+1,se);
}
*/


vector<int> merge(vector<int> &left, vector<int> &right){
	vector<int> result;
	unsigned i = 0;
	unsigned j = 0;
	while(i < left.size() || j < right.size()){
	  if( i == left.size()){
		result.push_back(right[j]);
		j++;
	  }else if( j == right.size()){
		result.push_back(left[i]);
		i++;
	  }else if(left[i] < right[j]){
		result.push_back(left[i]);
		i++;
	  }else{
		result.push_back(right[j]);
		j++;
	  }
	}
	return result;
  }

  void mergeSort(vector<int> &v){
	if(v.size() <= 1){
	  return;
	}
	unsigned split = v.size() / 2;
	vector<int> left;
	vector<int> right;
	for(unsigned i = 0; i < v.size(); i++){
	  if( i < split){
		left.push_back(v[i]);
	  }else{
		right.push_back(v[i]);
	  }
	}
	mergeSort(left);
	mergeSort(right);
	v = merge(left,right);
  }


void selectionSort(vector<int> &numbers) {
	int min, temp;
	for (int i = 0; i < numbers.size() -1; i++) {
		min = i;
		for (int j = i + 1; j < numbers.size(); j++)
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
	if (first >= last) {return true;}
	if (!isUnique1(numbers, first, last-1)) {return false;}
	if (!isUnique1(numbers, first+1, last)) {return false;}
	return (numbers[first]!=numbers[last]);
}


bool isUnique2(vector<int> &numbers, int first, int last){ //Iterative validation
   /*Input: Array A, first, last
   Output:
true if the array contains no repeated elements
false if the array contains repeated elements*/
	print(numbers);
	if (first >= last) {return true;}
	for (int i = first; i < last; i++) {
		for (int j = i+1; j <=last; j++) {
			if (numbers[i] == numbers[j]) {return false;}
		}
	}
	print(numbers);
   return true;
}

bool isUnique3(vector<int> numbers, int first, int last, int sortType){ //Sorted validation
   /*Input: Array A, first, last
   Output:
true if the array contains no repeated elements
false if the array contains repeated elements*/
	if (sortType == 0) {
		print(numbers);
		bubbleSort(numbers);
		print(numbers);
	}
	else if (sortType == 1) {
		print(numbers);
		mergeSort(numbers);
		print(numbers);
	} else {
		print(numbers);
		selectionSort(numbers);
		print(numbers);
	} if (first >= last) {return true;}
	for (int i =  first; i < last; i++) {
		if (numbers[i] == numbers[i+1]) {return false;}
	}
   return true;
}


int main(){
	clock_t start = clock();
	clock_t end = clock();
	bool result = true;
	int size = 0;

	cout << "Enter the number of elements for the vector: " << endl;
	cin >> size;

	vector<int> numbers;
	srand(time(0));
	fill(numbers, size);
	print(numbers);
	start = clock();
	result = isUnique1(numbers, 0, numbers.size());
	end = clock();
	print(numbers);
	cout << "Recursive Validation :: ";
	if (result == false) {
		 cout << "NOT ";
	}
	cout << "Unique! Time: " << (float)(end-start)*1000/(float)CLOCKS_PER_SEC << endl;

	start = clock();
	result = isUnique2(numbers, 0, numbers.size());
	end = clock();
	cout << "Iterative Validation :: ";
	if (result == false) {
		 cout << "NOT ";
	}
	cout << "Unique! Time: " << (float)(end-start)*1000/(float)CLOCKS_PER_SEC << endl;

	for (int sortType = 0; sortType <= 2; sortType++) {
		start = clock();
		result = isUnique3(numbers, 0, numbers.size(), sortType);
		end = clock();
		if (sortType == 0) {
			cout << "BubbleSort ";
		} else if (sortType == 1) {
			cout << "MergeSort ";
		} else {
			cout << "SelectionSort ";
		}
		cout << "Sorted Validation :: ";
		if (result == false) {
			 cout << "NOT ";
		}
		cout << "Unique! Time: " << (float)(end-start)*1000/(float)CLOCKS_PER_SEC << endl;
	}

return 0;

}
