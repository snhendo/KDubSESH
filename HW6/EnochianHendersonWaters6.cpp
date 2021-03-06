/* 20CS2028 Data Structures Assignment #6 - Due July 30, 2015
Author: Stephen Enochian, Shannon Henderson, Kaitlyn Waters
Course title: Data Structures
Course number: CS2028
Instructor: Anca Ralescu
TA: Suryadip Chakraborty
Abstract: This program stores and reads information in a hash table.
Preconditions: This program sorts integers only.
Postconditions: None
Credit: Referred to Dr. Talaga's examples from CS2, consulted the web for various parts of our code (i.e. Hash Table/Hash Entry classes)
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <ctime>

using namespace std;

//DECLARE TABLE SIZE
const int N = 1009;

int main () {
    srand(time(0));                 //will move whenever we incorporate the for loop
    int bucket[N];                  // declare bucket array of size N (23)
    for (int a = 0; a < N; a++){    // fill with -1 to indicate emptiness of bucket (values will be >= 0)
        bucket[a] = -1;             //initialize bucket array
    }

    vector<vector<int> > bucket2(N, vector<int>(0));

    char choice;                                // initialize the choice (user input)
    cout << "Assignment #6" << endl << endl;
    cout << "Select your collision resolution scheme:\n(a) Double Hashing\n(b) Quadratic\n(c) Chaining within the Hash Table\n";
    cin >> choice;                              // store response to cout statement here
    cout << "Choice: " << choice << endl;       // prints to user (testing purposes)
    cout << "What load ratio would you like to use? Enter a value between 0 and 1.0" << endl;
    float loadRatio = 0.0;                      // initialize loadRatio
    cin >> loadRatio;                           // store user's response to the cout statement here
    const int keyListSize = ceil(loadRatio*N);  // since the load ratio is a percentage (load ratio = n/N), if we multiply N by the percentage we will acquire the same value
    int keysNeeded = 0;
    int keyList[keyListSize];                   // initialize a keyList array to store the keys that will be used
    int totalComparisons = 0;                   // inititalized counter for comparisons

<<<<<<< Updated upstream
    while (keysNeeded != keyListSize){          // while loop that checks to see if that the keys are all unique
        int randKey = rand() % 1000;            // generates a randomKey
=======
    while (keysNeeded != keyListSize){                    // while loop that checks to see if keysNeeded (list size) = 0 (empty)
        int randKey = rand() % 1500;              // generates a randomKey
>>>>>>> Stashed changes
        bool unique = true;                     // automatically sets unique boolean to true
        for(int i = 0; i < keyListSize; i++){   // checks to make sure the key really is unique
            if(keyList[i] == randKey){
                unique = false;                 // if it's not unique, we set the unique variable to false and exit the for loop
                break;
            }
        }
        if (unique){                                            // if the key is unique
            keyList[keysNeeded] = randKey;                      // put the key at the end
            keysNeeded++;                                       // decrement keysNeeded
            int h1 = randKey % N;                               // creates the hash value (h(k))
            //cout << "This should go in entry: " << h1 << endl;// prints hash value to user (testing)
            if((choice != 'c' && bucket[h1] < 0)){              // if the bucket is <0 (-1) and as long as the separate chaining isn't chosen, it is empty and we can put something there
                bucket[h1] = randKey;                           // put that key in the bucket at the h1'th location
                totalComparisons += 1;                          // increments comparison counter because a comparison was made
            }
            else{                                               // otherwise we have to do collision resolution (dependent on user's choice)
                if (choice == 'a'){                             //double hashing
                    int q = 19;                                 // set up an arbitrary (prime) q
                    int h2 = q - (randKey % q);                 // calculate h2 (h')
                    for (int n = 0; n < N; n++){                // this represents the j = 0, 1, 2, . . . listed in the book under double hashing
                        int location = (h1 + (h2*n)) % N;       // calculates a new location
                        if (bucket[location] < 0){              // if it's empty, put the key in that location
                            bucket[location] = randKey;
                            totalComparisons += 1;              // increment the number of comparisons (once it's finally inserted - final comparison)
                            break;                              // leave for loop
                        }                                       // iterates through for loop until an empty bucket is found
                        totalComparisons += 1;                  // increment comparisons outside if statement in case that location is still invalid (still counts as comparison)
                    }
                }
                else if (choice == 'b'){                            // quadratic probing
                    for(int x = 0; x < N; x++){                     // for loop to try to find the empty bucket where we can put the key that caused the collision
                        int location = (h1 + (int)pow(x,2)) % N;    // generate a new location to check (using the formula provided in textbook -> (h1 + x^2)%N)
                        if (bucket[location] < 0){                  // if it's empty, add it to that bucket and leave for loop - otherwise, loop to next value for x
                            bucket[location] = randKey;
                            totalComparisons += 1;                  // increment number of comparisons
                            break;
                        }
                        totalComparisons += 1;                      // increment number of comparisons if the code doesn't step through the if statement
                    }
                }
                else if (choice == 'c'){                        // chaining
                    bucket2[h1].push_back(randKey);             // put original key into corresponding hashvalue vector
                    totalComparisons += 1;                      // increment number of comparisons
                }
                else{
                    cout << "Program ended." << endl;
                    return 0;
                }
            }

        }else{
            cout << "Duplicate random key generated. Generating new random key." << endl;
        }
    }

    // This segment is just for testing purposes. It prints out the keyList array.//
    cout << "KeyList: [ ";
    for (int t = 0; t < keyListSize; t++){
        cout << keyList[t] << ", ";
    }
    cout << "]" << endl;
    // End of testing segment //

    // Prints out the bucket array for testing purposes to make sure our collision resolution methods work
    if (choice != 'c'){
        cout << "[";
        for(int z = 0; z < N; z++){
            if (bucket[z] == -1){
                cout << " _, ";
            }
            else{
            cout << bucket[z] << ", ";
            }
        }
        cout << "]" << endl;
    }
    else{
        cout << endl;
        for(int z = 0; z < N; z++){
            cout << "Bucket " << z << ": ";
            if (bucket2[z].size() == 0){
                cout << endl;
            }
            else{
                for(int index = 0; index < bucket2[z].size(); index++){
                    cout << bucket2[z][index] << ", ";
                }
                cout << endl;
            }
        }
    }

    // End of print segment

    // Print number of comparisons and average comparisons//
    cout << "The total number of comparisons that had to be made for this hash table is: " << totalComparisons << endl;
    float AvgComp = (float)totalComparisons/(float)keyListSize;
    cout << endl << "Average Comparisons: " << AvgComp << endl;
    cout << "Please enter a key to check if it is currently in the table: ";    // Ask user for key to be added to table, if key is present, collision prevention will occur and it will be placed accordingly
    int testKey = -1;                                                           // Initialize testKey to store user's response
    cin >> testKey;                                                             // Store user's response
    int h1 = testKey % N;                                                       // creates the hash value (h(k))
    bool uniqueTest = true;                                                     // set up a uniqueTest variable and initialize to true
    if(choice != 'c'){                                                          // if user chooses a or b (NOT c), then we look in each bucket and see if the test is true
        for (int i = 0; i < N; i++){                                            // runs through the bucket and checks if the value at bucket[h1] is greater than -1 (has something in it)
            if(bucket[h1] > -1){                                                // if so, the test is false
                uniqueTest = false;
            }
        }
    }else{
        for(int i = 0; i < N; i++){                                             // if user chose c, we step through 2 for loops to look at each element and look for the testKey value in all lists
            for(int j = 0; j < bucket2[i].size(); j++){
                if(bucket2[i][j] == testKey){
                    uniqueTest = true;                                          // if the testKey is found, uniqueTest is true
                }
            }
        }
    }


    if (uniqueTest){                                                            // if the uniqueTest is true that value is not in the table, if false it is in the table already
        cout << "It's NOT in the table." << endl;
    }else{
        cout << "It's in the table." << endl;
    }


    return 0;
    //end of main function
}
