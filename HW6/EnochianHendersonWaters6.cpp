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
#include <cmath>
#include <ctime>

using namespace std;

//DECLARE TABLE SIZE
const int N = 23;

class HashEntry{
    private:
        int key;
        int value;
    public:
        HashEntry(int key, int value){
            this->key = key;
            this->value = value;
        }

        int getKey(){ return key; }
        int getValue(){ return value; }
};

class HashTable{
    private:
    HashEntry** table;

    public:
    HashTable(){
        table = new HashEntry*[N];
        for(int i = 0; i < N; i++){
            table[i] = NULL;
        }
    }

    int get(int key){
        int hash = (key %  N);
        while(table[hash] != NULL && table[hash]->getKey() != key){
            hash = (hash + 1) % N;
        }
        if(table[hash] == NULL){
            return -1;
        }
        else{
            return table[hash]->getValue();
        }
    }

    void put(int key, int value){
        int hash = (key % N);
        while(table[hash] != NULL && table[hash]->getKey() != key){
            hash = (hash + 1) % N;
        }
        if (table[hash] != NULL){
            delete table[hash];
        }
        table[hash] = new HashEntry(key, value);
    }

    ~HashTable(){
        for(int i = 0; i < N; i++){
            if(table[i] != NULL){
                delete table[i];
            }
        }
        delete[] table;
    }
};



int main () {
    srand(time(0)); //will move whenever we incorporate the for loop
    int bucket[N];
    for (int a = 0; a < N; a++){
        bucket[a] = -1; //initialize bucket array
    }
    cout << "Assignment #6" << endl << endl;
    cout << "Select your collision resolution scheme:\n(a) Double Hashing\n(b) Quadritic\n(c) Chaining within the Hash Table\n";
    char* choice;
    cin >> choice;
    cout << "What load ratio would you like to use? Enter a value between 0 and 1.0" << endl;
    float loadRatio = 0.0;
    cin >> loadRatio;
    const int keyListSize = ceil(loadRatio*N);
    int keyList[keyListSize];
    for (int i = 0; i < keyListSize; i++) {
        int value = rand() % 50;
        keyList[i] = value;
    }

    for(int j = 0; j < N; j++){
        int h1 = keyList[j] % N;
        if(bucket[h1] < 0){
            bucket[h1] = keyList[j];
        }
        else{
            if (*choice == 'a'){ //double hashing
                int q = 19;
                int h2 = q - (keyList[j] % q);
                for (int n = 0; n < N; n++){
                    int location = (h1 + (h2*n)) % N;
                    if (bucket[location] < 0){
                        bucket[location] = keyList[j];
                        break;
                    }
                }
                cout << "Bucket is full. Cannot add more keys." << endl;
            }
            else if (*choice == 'b'){//quadratic probing
                for(int x = 0; x < N; x++){
                    int location = (h1 + (int)pow(x,2)) % N;
                    if (bucket[location] < 0){
                        bucket[location] = keyList[j];
                        break;
                    }
                }
            }
            else if (*choice == 'c'){
                //chaining
            }
            else{
                cout << "Program ended." << endl;
                return 0;
            }
        }
    }


    return 0;
}
