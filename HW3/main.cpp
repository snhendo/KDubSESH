/* 20CS2028 Data Structures Assignment #3 - Due June 17, 2015
Author: Stephen Enochian, Shannon Henderson, Kaitlyn Waters
Course title: Data Structures
Course number: CS2028
Instructor: Anca Ralescu
TA: Suryadip Chakraborty
Abstract: Assignment 3 main.cpp uses doubly-linked lists to imitate an email inbox by using functions <insert function names here> to do <the following tasks>.
Preconditions: None
Postconditions: None
Credit: Referred to Dr. Talaga's examples from CS2
*/

#include <iostream>

using namespace std;

class Email(){
    public:

    Email();
    ~Email();

    private:

    class emailNode{
        public:
        string to;
        string from;
        string message;
    }
    emailNode* head;
}

Email::Email(){
    head = NULL;
}

Email::~Email();

class Inbox(){
    public:

    Inbox();
    ~Inbox();
    void insertEmail();
    void deleteCommunication();
    void displayInbox();

    private:

    class commNode{
        public:
        string subject;
        int emailCount;
        commNode* next;
        commNode* previous;
    }
    commNode* head;
    int size;
    commNode* searchCommunication();
}

Inbox::Inbox(){
    head = NULL;
    size = 0;
}

Inbox::~Inbox();

commNode* Inbox::searchCommunication(string newSubject) const{
    commNode* temp = head;
    while (temp != NULL){
        if(temp->subject == newSubject){
            return temp;
        }
        if(temp->next != NULL){
            temp = temp->next;
        }else{
            return NULL;
        }
    }
}

void Inbox::displayInbox() const{
    commNode* temp = head;
    while(temp != NULL){
        cout << temp->subject << " - " << temp->emailCount << endl;
        if(temp->next != NULL){
            temp = temp->next;
        }else{
            temp = NULL;
        }
    }
}

void Inbox::insertEmail(string newSubject; string to; string from; string message) const{
    commNode* temp = searchCommunication(newSubject);
    if(temp != NULL){

    }
}

int main() {

return 0;

}
