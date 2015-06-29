/* 20CS2028 Data Structures Assignment #4 - Due July 7, 2015
Author: Stephen Enochian, Shannon Henderson, Kaitlyn Waters
Course title: Data Structures
Course number: CS2028
Instructor: Anca Ralescu
TA: Suryadip Chakraborty
Abstract: This program prompts for information and then sorts the given list given its size using MergeSort, QuickSort, BubbleSort, and InsertionSort via a HybridSort function.
Preconditions: This program sorts integers only.
Postconditions: None
Credit: Referred to Dr. Talaga's examples from CS2
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

// insertion sort from http://mycodinglab.com/insertion-sort-algorithm/
void insertionSort(vector<int> &v, int &comparisons){
    int i, j, tmp;
    for (i = 1; i < v.size(); i++) {
        j = i;
        while (j > 0 && v[j - 1] > v[j]) {
            tmp = v[j];
            v[j] = v[j - 1];
            v[j - 1] = tmp;
            j--;
            comparisons++;
        }
    }
}

// quick sort from http://www.csepedia.com/Quick_Sort.html
int Partition(vector<int> &a, int beg, int end) {         //Function to Find Pivot Point
    int p=beg, pivot=a[beg], loc;
    for(loc=beg+1;loc<=end;loc++) {
        if(pivot>a[loc]) {
            a[p]=a[loc];
            a[loc]=a[p+1];
            a[p+1]=pivot;
            p=p+1;
        }
    }
    return p;
}


void quickSort(vector<int> &a, int beg, int end, int &comparisons)
{
    comparisons++;
    if(beg<end) {
        int p=Partition(a,beg,end);                       //Calling Procedure to Find Pivot
        quickSort(a,beg,p-1, comparisons);                             //Calls Itself (Recursion)
        quickSort(a,p+1,end, comparisons);			              //Calls Itself (Recursion)
    }
}

// quick sort from Dr. Talaga's examples from CS2
/*void quickSort(vector<int> &v, int start, int end){
  // sort the elements between (and including) start and end
  if(end-start < 1){ // 0 or 1
    return;
  }
  int so = start;
  int se = end;
  // put pivot at start location
  //int pivot = start;
  //int pv = v[pivot];
  int pivot = (rand() % (end-start +1)) + start;
  int pv = v[pivot];
  while(end-start >= 1){
    // 4 cases
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
      cout << "Well crap\n";
      return;
    }
  }
  //cout << "mid: " << v[start] << endl;
  quickSort(v,so, start-1);
  quickSort(v,end+1,se);
  //cout << "s: " << start << " e: " << end << endl;
}*/


// bubble sort from Dr. Talaga's examples from CS2
void bubbleSort(vector<int> &numbers, int &comparisons){ // bubbleSort takes a vector of numbers
    int flips = 0;
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
        comparisons++;
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

  void mergeSort(vector<int> &v, int &comparisons){ // mergeSort sorts a vector
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
        comparisons++;
    }
    mergeSort(left, comparisons); // recursively calls mergesSort on the left hand side (breaks down the left vector until there's only one element
    mergeSort(right, comparisons); // recursively calls mergeSort on the right hand side (breaks down the right vector until there's only one element
    v = merge(left,right); // merges the left and right vectors together to complete the sorting process
  }

void hybridSort (vector<int> &v, string Large, string Small, int T, int &comparisons, string &sortType) {
    if (v.size() > T) {
        if (Large == "MergeSort") {
            sortType = "Merge Sort";
            mergeSort(v, comparisons);
        } else {
            sortType = "Quick Sort";
            quickSort(v, 0, v.size(), comparisons);
        }
    } else {
        if (Small == "BubbleSort") {
            sortType = "Bubble Sort";
            bubbleSort(v, comparisons);
        } else {
            sortType = "Insertion Sort";
            insertionSort(v, comparisons);
        }
    }
}

void listDisplayer(vector<int> &v) {
    cout << "{";
    for (int i = 0; i < v.size(); i++) {
        if (i != 0){
            cout << ", ";
        }
        cout << v[i];
    }
    cout << "}" << endl;
}

int main () {
    cout << "Welcome to Sort! Follow the prompts to produce a sorted list." << endl;
    char restart = 'y';
    while (restart == 'y') {
        cout << "At what threshold should this be considered a large list?" << endl;
        int sortThreshold = 0;
        cin >> sortThreshold;
        cout << "What is the size of your list?" << endl;
        int listSize = 0;
        cin >> listSize;
        char listGeneration = 'm';
        char listDisplay = 'y';
        if (listSize <= 100) {
            cout << "Would you like to enter it manually (m) or have it randomly generated (r)?" << endl;
            cin >> listGeneration;
            cout << "Would you like the list to be displayed? Yes (y) or No (n)?" << endl;
            cin >> listDisplay;
        } else {
            listGeneration = 'r';
            listDisplay = 'n';
        }
        vector<int> listValues;
        if (listGeneration == 'm') {
            cout << "Enter one value at a time. Press return before entering another value." << endl;
            int temp = 0;
            for (int i = 0; i < listSize; i++) {
                cout << "Value " << listValues.size() + 1 << ": ";
                cin >> temp;
                listValues.push_back(temp);
            }
        } else if (listGeneration == 'r') {
            srand(time(0));
            for (int i = 0; i < listSize; i++) {
                int randValue = rand() % (listSize * 10);
                listValues.push_back(randValue);
            }
        }
        if (listDisplay == 'y') {
            cout << "Original List: ";
            listDisplayer(listValues);
        }
        vector<int> result = listValues;
        int comparisons = 0;
        string sortType="";
        hybridSort(result, "MergeSort", "BubbleSort", sortThreshold, comparisons, sortType);
        if (listDisplay == 'y') {
            cout << sortType << endl;
            listDisplayer(result);
            cout << "Comparisons: " << comparisons << endl;
        }
        result = listValues;
        comparisons = 0;
        hybridSort(result, "MergeSort", "InsertionSort", sortThreshold, comparisons, sortType);
        if (listDisplay == 'y') {
            cout << sortType << endl;
            listDisplayer(result);
            cout << "Comparisons: " << comparisons << endl;
        }
        result = listValues; // avoiding an error
        comparisons = 0;
        hybridSort(result, "QuickSort", "BubbleSort", sortThreshold, comparisons, sortType);
        result = listValues;
        comparisons = 0;
        hybridSort(result, "QuickSort", "BubbleSort", sortThreshold, comparisons, sortType);
        if (listDisplay == 'y') {
            cout << sortType << endl;
            listDisplayer(result);
            cout << "Comparisons: " << comparisons << endl;
        }
        result = listValues;
        comparisons = 0;
        hybridSort(result, "QuickSort", "InsertionSort", sortThreshold, comparisons, sortType);
        if (listDisplay == 'y') {
            cout << sortType << endl;
            listDisplayer(result);
            cout << "Comparisons: " << comparisons << endl;
        }
        cout << "Would you like to sort another list? (y/n)" << endl;
        cin >> restart;
    }
}
