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
const int N = 23;

class HashEntry{                        // initialize the hashEntry class to have the key/value properties
    private:
        int key;
        int value;
    public:
        HashEntry(int key, int value){  // constructor to intialize key and value
            this->key = key;
            this->value = value;
        }

        int getKey(){ return key; }     // sets up getKey
        int getValue(){ return value; } // sets up getValue
};

class HashTable{                    // initialize the HashTable class to set up the bucket array
    private:
    HashEntry** table;              // declare the table

    public:
    HashTable(){                    // constructs the table
        table = new HashEntry*[N];  // create a new table of size N
        for(int i = 0; i < N; i++){ // fill table with pointers to NULL
            table[i] = NULL;
        }
    }

    int get(int key){                                               // definition of get (for the hash table)
        int hash = (key %  N);                                      // this is our h(k) -> as described in the textbook
        while(table[hash] != NULL && table[hash]->getKey() != key){ // as long as there are entries (not pointing to NULL) and the value at that location in the hash table is not equal to the key value
            hash = (hash + 1) % N;                                  // change h(k) to equal (h(k) + 1) % N (23)
        }
        if(table[hash] == NULL){                                    // if the pointer points to NULL
            return -1;                                              // return a -1 (to represent empty)
        }
        else{
            return table[hash]->getValue(); // otherwise we return the value at that location in the hash table
        }
    }

    void put(int key, int value){                                   // definition of the put function
        int hash = (key % N);                                       // set up our h(k)
        while(table[hash] != NULL && table[hash]->getKey() != key){ // make sure we have a valid hash location
            hash = (hash + 1) % N;
        }
        if (table[hash] != NULL){                                   // if that location points to NULL (is empty)
            delete table[hash];                                     // delete the pointer? (Is this right?)
        }
        table[hash] = new HashEntry(key, value);                    // otherwise we create a new entry in the table and fill it with (k,v)
    }

    ~HashTable(){                                                   // destructor
        for(int i = 0; i < N; i++){                                 // deletes pointers
            if(table[i] != NULL){
                delete table[i];
            }
        }
        delete[] table;                                             // makes sure everything is deleted
    }
};



int main () {
    srand(time(0));                 //will move whenever we incorporate the for loop
    int bucket[N];                  // declare bucket array of size N (23)
    for (int a = 0; a < N; a++){    // fill with -1 to indicate emptiness of bucket (values will be >= 0)
        bucket[a] = -1;             //initialize bucket array
    }
    vector<int>* bucket2[N];        // initialize an array of pointers to vectors (bucket2) of size N (23)
    for(int b = 0; b < N; b++){     // make all pointers point to NULL
        bucket2[b] = NULL;
    }

    vector<vector<int> > bucket3(N, vector<int>(0));

    char choice;                                // initialize the choice (user input)
    cout << "Assignment #6" << endl << endl;
    cout << "Select your collision resolution scheme:\n(a) Double Hashing\n(b) Quadratic\n(c) Chaining within the Hash Table\n";
    cin >> choice;                              // store response to cout statement here
    cout << "Choice: " << choice << endl;       // prints to user (testing purposes)
    cout << "What load ratio would you like to use? Enter a value between 0 and 1.0" << endl;
    float loadRatio = 0.0;                      // initialize loadRatio
    cin >> loadRatio;                           // store user's response to the cout statement here
    const int keyListSize = ceil(loadRatio*N);  // since the load ratio is a percentage (load ratio = n/N), if we multiply N by the percentage we will acquire the same value
    int keysNeeded = keyListSize;
    int keyList[keyListSize];                   // initialize a keyList array to store the keys that will be used
    //for (int i = 0; i < keyListSize; i++) {     // for each entry in keyList, we will assign a random value between 0 and 50
    //    int value = rand() % 50;
    //    keyList[i] = value;
    //}

    // for loop that steps through each element in keyList array and tries to put it in a bucket
    // if the bucket is already filled with an entry, then we will use 1 of 3 collision-resolution methods
    // as defined by the user earlier in the code (see lines 101-102)

    while (keysNeeded != 0){
        int randKey = rand() % 50;
        bool unique = true;
        for(int i = 0; i < keyListSize; i++){
            if(keyList[i] == randKey){
                unique = false;
                break;
            }
        }
        if (unique){
            keyList[keysNeeded-1] = randKey;
            keysNeeded--;
            int h1 = randKey % N;                           // creates the hash value (h(k))
            cout << "This should go in entry: " << h1 << endl; // prints hash value to user (testing)
            if((choice != 'c' && bucket[h1] < 0) /*&& (bucket2[h1] == NULL)*/){ // if the bucket is <0 (-1), it is empty and we can put something there
                bucket[h1] = randKey;
                //bucket2[h1]->push_back(keyList[j]);
            }
            else{                                           // otherwise we have to do collision resolution (dependent on user's choice)
                if (choice == 'a'){                         //double hashing
                    int q = 19;                             // set up an arbitrary (prime) q
                    int h2 = q - (randKey % q);          // calculate h2 (h')
                    for (int n = 0; n < N; n++){            // this represents the j = 0, 1, 2, . . . listed in the book under double hashing
                        int location = (h1 + (h2*n)) % N;   // calculates a new location
                        if (bucket[location] < 0){          // if it's empty, put the key in that location
                            bucket[location] = randKey;
                            break;                          // leave for loop
                        }                                   // iterates through for loop until an empty bucket is found
                    }
                }
                else if (choice == 'b'){                            // quadratic probing
                    for(int x = 0; x < N; x++){                     // for loop to try to find the empty bucket where we can put the key that caused the collision
                        int location = (h1 + (int)pow(x,2)) % N;    // generate a new location to check (using the formula provided in textbook -> (h1 + x^2)%N)
                        if (bucket[location] < 0){                  // if it's empty, add it to that bucket and leave for loop - otherwise, loop to next value for x
                            bucket[location] = randKey;
                            break;
                        }
                    }
                }
                else if (choice == 'c'){                    //chaining
                    bucket3[h1].push_back(randKey);      //put original key into corresponding hashvalue vector
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
    cout << "[";
    if (choice =! 'c'){
        for(int z = 0; z < N; z++){
            if (bucket[z] == -1){
                cout << " _, ";
            }
            else{
            cout << bucket[z] << ", ";
            }
        }
    }else{
        for(int z = 0; z < N; z++){
            if (bucket3[z].size() == 0){
                cout << " _; ";
            }else{
                for(int index = 0; index < bucket3[z].size(); index++){
                    cout << bucket3[z][index] << ", ";
                }
                cout << "; ";
            }
        }
    }
    cout << "]" << endl;

    cout << "Please enter a key to check if it is currently in the table: "; //Ask user for key to be added to table, if key is present, collision prevention will occur and it will be placed accordingly
    int testKey = -1;
    cin >> testKey;
    int h1 = testKey % N;                           // creates the hash value (h(k))
    bool uniqueTest = true;
    if(choice != 'c'){
        for (int i = 0; i < N; i++){
            if(bucket[h1] > -1){
                uniqueTest = false;
            }
        }
    }else{
        for(int i = 0; i < N; i++){
            for(int j = 0; j < bucket3[i].size(); j++){
                if(bucket3[i][j] == testKey){
                    uniqueTest = false;
                }
            }
        }
    }
    if (uniqueTest){
        cout << "It's NOT in the table." << endl;
    }else{
        cout << "It's in the table." << endl;
    }

    return 0;
    //end of main function
}
