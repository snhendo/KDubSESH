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

using namespace std;


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

//DECLARE TABLE SIZE
const int N = 23;

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
    cout << "Assignment #6" << endl << endl;
    cout << "Select your collision resolution scheme:\n(a) Double Hashing\n(b) Quadritic\n(c) Chaining within the Hash Table\n";
    char* collisionResolutionSelection;
    cin >> collisionResolutionSelection;
    if (*collisionResolutionSelection < 'a' || *collisionResolutionSelection > 'c') {
        return 0;
    }
    cout << "What load ratio would you like to use? Enter a value between 0 and 1.0" << endl;
    float loadRatio = 0.0;
    cin >> loadRatio;
    return 0;
}
