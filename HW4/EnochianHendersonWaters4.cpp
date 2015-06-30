/* 20CS2028 Data Structures Assignment #4 - Due July 7, 2015
Author: Stephen Enochian, Shannon Henderson, Kaitlyn Waters
Course title: Data Structures
Course number: CS2028
Instructor: Anca Ralescu
TA: Suryadip Chakraborty
Abstract: This program prompts for information and then sorts the given list given its size using MergeSort, QuickSort, BubbleSort, and InsertionSort via a HybridSort function.
Preconditions: This program sorts integers only.
Postconditions: None
Credit: Referred to Dr. Talaga's examples from CS2, consulted the web for various sorts
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

// insertion sort from http://mycodinglab.com/insertion-sort-algorithm/
void insertionSort(vector<int> &v, int &comparisons){ // insertionSort passes in a vector and the number of comparisons used by the sorting method by reference
    int i, j, tmp; // initialize i, j, and a temporary variable
    for (i = 1; i < v.size(); i++) { // iterates through the vector
        j = i; // set j equal to i
        while (j > 0 && v[j - 1] > v[j]) { // as long as j is greater than zero and the previous element is greater than the current element, swap and decrement the number of comparisons
            tmp = v[j]; // temp = current element
            v[j] = v[j - 1]; // current element = previous element
            v[j - 1] = tmp; // previous element = temp
            j--; // decrement j
            comparisons++; // decrement comparisons (value)
        }
    }
}

// quick sort from http://www.csepedia.com/Quick_Sort.html
int Partition(vector<int> &a, int beg, int end) {         //Function to Find Pivot Point, passes a vector in by reference, also takes beginning and ending variables
    int p=beg, pivot=a[beg], loc; // initialize variables and set them to values as needed
    for(loc=beg+1;loc<=end;loc++) { // start loc at beginning+1 and increment through to the end
        if(pivot>a[loc]) { // if the pivot is greater than the value at that location within the vector, swap them
            a[p]=a[loc]; // a[p] = value at the loc of a
            a[loc]=a[p+1]; // the value at loc of a = the value at the p+1 element of a
            a[p+1]=pivot; // the element at p+1 of a = pivot
            p=p+1; // increment p
        }
    }
    return p; // return the value of p
}


void quickSort(vector<int> &a, int beg, int end, int &comparisons) // passes in a vector and a number of comparisons by reference, as well as beginning and ending variables
{
    comparisons++; // increment comparisons
    if(beg<end) { // if the beginning value is greater than the end, recursively call itself to sort the vector after finding a pivot
        int p=Partition(a,beg,end);                       //Calling Procedure to Find Pivot
        quickSort(a,beg,p-1, comparisons);                             //Calls Itself (Recursion)
        quickSort(a,p+1,end, comparisons);			              //Calls Itself (Recursion)
    }
}

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

void hybridSort (vector<int> &v, string Large, string Small, int T, int &comparisons, string &sortType) { // hybridSort takes in a vector, number of comparisons, and a sortType by reference, on top of taking in a Large, Small, and T (efficiency of the sorts -- i.e. large is efficient for large lists, small is efficient for small lists, T is the threshhold at which the list considered to require the large or small sort algorithm)
    if (v.size() > T) { // if the size is greater than T, sort depending on what large is decided to be and then sort accordingly
        if (Large == "MergeSort") { // sorts using mergesort
            sortType = "Merge Sort";
            mergeSort(v, comparisons);
        } else { // sorts using quicksort
            sortType = "Quick Sort";
            quickSort(v, 0, v.size(), comparisons);
        }
    } else { // otherwise size < T, so we sort depending on what small is decided to be and the vector is sorted accordingly
        if (Small == "BubbleSort") { // sort via bubblesort
            sortType = "Bubble Sort";
            bubbleSort(v, comparisons);
        } else { // sort via insertion sort
            sortType = "Insertion Sort";
            insertionSort(v, comparisons);
        }
    }
}

void listDisplayer(vector<int> &v) { // print function
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
    char restart = 'y'; // automatically set to yes (can be changed by user at the end of the program)
    while (restart == 'y') {
        cout << "At what threshold should this be considered a large list? Please choose a value between 8 and 16." << endl; // prompts user for a value to determine what a large list is
        int sortThreshold = 0; // initialize sortThreshold
        cin >> sortThreshold; // store user input in the variable
        cout << "What is the size of your list?" << endl; // prompts for size of list
        int listSize = 0;
        cin >> listSize; // stores list
        char listGeneration = 'm'; // automatically set the list to be maunally entered (user can change if desired)
        char listDisplay = 'y'; // automatically set the list to be printed (user can change if desired)
        char listComparisonsDisplay = 'y'; // automatically sets number of comparisons to be displayed (user can change if desired)
        if (listSize <= 100) { // if list size is less than or equal to 100, user can enter the list manually if they so choose
            cout << "Would you like to enter it manually (m) or have it randomly generated (r)?" << endl; // prompt user if they want to manually enter the list or randomly generate a list
            cin >> listGeneration; // store response
            cout << "Would you like the list to be displayed? Yes (y) or No (n)?" << endl; // prompt user if they want to print the list
            cin >> listDisplay; // store response
        } else { // if list size is greater than 100, automatically generate a random list and don't display the list
            listGeneration = 'r';
            listDisplay = 'n';
        }
        cout << "Would you like the comparisons counts to be displayed? Yes (y) or No (n)?" << endl; // prompt user if they want to display the number of comparisons
        cin >> listComparisonsDisplay; //store response
        vector<int> listValues; // initialize vector
        if (listGeneration == 'm') { // if user wants to enter list manually, ask for each value individually and store in the vector
            cout << "Enter one value at a time. Press return before entering another value." << endl;
            int temp = 0;
            for (int i = 0; i < listSize; i++) {
                cout << "Value " << listValues.size() + 1 << ": ";
                cin >> temp;
                listValues.push_back(temp);
            }
        } else if (listGeneration == 'r') { // if user wants list randomly generated, store random integers in the vector
            srand(time(0));
            for (int i = 0; i < listSize; i++) {
                int randValue = rand() % (listSize * 10);
                listValues.push_back(randValue);
            }
        }
        if (listDisplay == 'y') { // if the user wants the list to be display, print out the original list
            cout << "Original List: ";
            listDisplayer(listValues);
        }
        vector<int> result = listValues; //initialize result to be the vector
        int comparisons = 0; // intialize the number of comparisons to 0 (we haven't done anything yet)
        string sortType=""; // intialize the type of sort
        hybridSort(result, "MergeSort", "BubbleSort", sortThreshold, comparisons, sortType); // decide what sort to do between mergesort and bubblesort
        if (listDisplay == 'y' || listComparisonsDisplay == 'y') { // if user wants to display the list or the comparisons, print out the the value of sortType
            cout << sortType << endl;
        }
        if (listDisplay == 'y') { // if user wants to display the list, call the print function
            listDisplayer(result);
        }
        if (listComparisonsDisplay == 'y'){ // if user wants to display the comparisons, print out the comparisons
            cout << "Comparisons: " << comparisons << endl;
        }
        result = listValues; // reinitialize result to listValues
        comparisons = 0; // reinitialize comparsions to 0
        hybridSort(result, "MergeSort", "InsertionSort", sortThreshold, comparisons, sortType); // decide what sort to do between mergesort and insertionsort
        if (listDisplay == 'y' || listComparisonsDisplay == 'y') {
            cout << sortType << endl;
        }
        if (listDisplay == 'y') {
            listDisplayer(result);
        }
        if (listComparisonsDisplay == 'y'){
            cout << "Comparisons: " << comparisons << endl;
        }
        result = listValues; // avoiding an error
        comparisons = 0;
        hybridSort(result, "QuickSort", "BubbleSort", sortThreshold, comparisons, sortType); // decide what sort to do between quicksort and bubblesort
        result = listValues;
        comparisons = 0;
        hybridSort(result, "QuickSort", "BubbleSort", sortThreshold, comparisons, sortType);
        if (listDisplay == 'y' || listComparisonsDisplay == 'y') {
            cout << sortType << endl;
        }
        if (listDisplay == 'y') {
            cout << sortType << endl;
            listDisplayer(result);
        }
        if (listComparisonsDisplay == 'y'){
            cout << "Comparisons: " << comparisons << endl;
        }
        result = listValues;
        comparisons = 0;
        hybridSort(result, "QuickSort", "InsertionSort", sortThreshold, comparisons, sortType); // decide what sort to do between quicksort and insertion sort
        if (listDisplay == 'y' || listComparisonsDisplay == 'y') {
            cout << sortType << endl;
        }
        if (listDisplay == 'y') {
            listDisplayer(result);
        }
        if (listComparisonsDisplay == 'y'){
            cout << "Comparisons: " << comparisons << endl;
        }
        cout << "Would you like to sort another list? (y/n)" << endl; // ask the user if they want to sort another list
        cin >> restart; // store response
    }
}
