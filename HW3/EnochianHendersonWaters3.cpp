/* **************************************************
NOTE: Professor Ralescu gave us permission to submit
a new copy of Homework 3 without being penalized for
turning it in late.
******************************************************/

/* 20CS2028 Data Structures Assignment #3 - Due June 17, 2015
Author: Stephen Enochian, Shannon Henderson, Kaitlyn Waters
Course title: Data Structures
Course number: CS2028
Instructor: Anca Ralescu
TA: Suryadip Chakraborty
Abstract: Assignment 3 main.cpp uses doubly-linked lists to imitate an email
inbox by using functions <insert function names here> to do <the following tasks>.
Preconditions: None
Postconditions: None
Credit: Referred to Dr. Talaga's examples from CS2
*/


#include <iostream>
#include <string>

using namespace std;


// emailNode class
class emailNode {
    public:
    // constructor
    emailNode(string to, string from, string message);
    // Getters
    string getTo();
    string getFrom();
    string getMessage();

    // pointers to the next and previous emails
    emailNode* next;
    emailNode* previous;

    private:
    string to;
    string from;
    string message;
};

// Conversation class
class Conversation {
    public:
    // pointers to next and previous communications
    Conversation* next;
    Conversation* previous;

    // constructor
    Conversation(string subject, emailNode* email);

    // copy constructor
    Conversation(Conversation& other);

    // This function adds an email at the head of the list
    void newEmail(emailNode* email);

    // Getters
    string getSub();
    int getSize();

     // Destructor
    ~Conversation();

    private:
    string subject;
    int size;

    // pointer to head of linked list of emails
    emailNode* emailHead;
};

// Inbox class
class Inbox {
    public:
    // constructor
    Inbox();

    // copy constructor
    Inbox(Inbox& other);

    // This function adds a new email to its corresponding communication,
    // or creates a new communication if one does not exist.
    // Most recently updated communications are moved to the top of the inbox.
    void insertEmail(emailNode* email, string subject);

    // this function deletes a communication and returns true if successful, false otherwise
    bool deleteConversation(string subject);

    // this function displays the inbox in order and lists the number of emails
    void displayInbox();

    ~Inbox();

    private:
    // this function returns a pointer to the communication with the given subject
    Conversation* searchConvo(string subject);

    // pointers to the head and tail of the list of communications
    Conversation* inboxHead;
    Conversation* inboxTail;
};

Inbox::Inbox() {
    inboxHead = NULL;
    inboxTail = NULL;
}

emailNode::emailNode(string to, string from, string message) {
        this->to = to;
        this->from = from;
        this->message = message;
        this->next = NULL;
        this->previous = NULL;
}

string emailNode::getTo() { return to; }

string emailNode::getFrom() { return from; }

string emailNode::getMessage() { return message; }

Conversation::Conversation(string subject, emailNode* email){
        this->subject = subject;
        emailHead = email;
        emailHead->next = NULL;
        emailHead->previous = NULL;
        size = 1;
}

Conversation::Conversation(Conversation& other) {
        this->next = other.next;
        this->previous = other.previous;
        this->subject = other.subject;
        this->size = other.size;
        this->emailHead = other.emailHead;
}

void Conversation::newEmail(emailNode* email) {
        email->previous = emailHead;
        emailHead = email;
        emailHead->next = NULL;
        size++;
}

string Conversation::getSub() { return subject; }

int Conversation::getSize() { return size; }

Conversation::~Conversation() {
    emailNode* temp = emailHead;
    emailNode* temp2 = emailHead;
    while (temp != NULL) {
        temp2 = temp;
        temp = temp->previous;
        delete temp2;
    }
}

Conversation* Inbox::searchConvo(string subject) {
    Conversation* temp = inboxHead;
    while (temp != NULL) {
        if (temp->getSub() == subject) {
            return temp;
        }
        temp = temp->previous;
    }
    // if no such communication exists, return NULL
    return NULL;
}

Inbox::Inbox(Inbox& other) {
    inboxHead = other.inboxHead;
    inboxTail = other.inboxTail;
}

void Inbox::insertEmail(emailNode* email, string subject) {
    // search for a communication with the given subject to place the email in
    Conversation* temp = searchConvo(subject);
    if (temp != NULL) { // if a communication already exists
        temp->newEmail(email);
        if (temp->next != NULL) {// if not already there, move the communication to the top of the inbox
            if (temp->previous != NULL) {
                (temp->previous)->next = temp->next;
            }
            else {
                this->inboxTail = temp->next;
            }
            (temp->next)->previous = temp->previous;
            temp->previous = this->inboxHead;
            temp->next = NULL;
            (this->inboxHead)->next = temp;
            this->inboxHead = temp;
        }
    }
    else {
        // create a new communication if one does not exist
        temp = new Conversation(subject, email);

        // place the new communication at the top of the inbox
        if (this->inboxHead != NULL) {
            (this->inboxHead)->next = temp;
        }
        temp->previous = this->inboxHead;
        temp->next = NULL;
        this->inboxHead = temp;
        if (this->inboxTail == NULL) {
            this->inboxTail = temp;
        }
    }
}

bool Inbox::deleteConversation(string subject) {
    Conversation* temp = searchConvo(subject);
    if (temp != NULL) {
        Conversation* next = temp->next;
        Conversation* previous = temp->previous;

        next->previous = previous;
        previous->next = next;

        delete temp;

        return true;
    }
    // return false if no such communication was found
    return false;
}

void Inbox::displayInbox() {
    if (inboxHead != NULL) {
        Conversation* current = inboxHead;

        // get total number of emails
        int size = 0;
        while (current != NULL) {
            size += current->getSize();
            current = current->previous;
        }

        cout << "Total number of emails in inbox: " << size << endl;

        // list communications and the number of emails in each one
        current = inboxHead;
        while (current != NULL) {
            cout << current->getSub() << " - " << current->getSize() << endl;
            current = current->previous;
        }
        cout << endl;
    }
}

Inbox::~Inbox() {
    Conversation* temp = inboxHead;
    Conversation* temp2 = inboxHead;
    while (temp != NULL) {
        temp2 = temp;
        temp = temp->previous;
        delete temp2;
    }
}

int main() {
    string subject = "";
    Inbox inbox;
    cout << endl << "Welcome to your inbox!" << endl;
    cout << "Enter an email subject, then hit enter after each one. " << endl;
    cout << "To terminate, enter 'done' followed by another enter." << endl << endl;

    // get subjects from user
    while (getline(cin, subject) && subject != "done") {
        inbox.insertEmail(new emailNode("to", "from", "message"), subject);

    }
    //display inbox
    inbox.displayInbox();

    return 0;
}









/*
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class emailNode{ // create email node that contains the to/from/message and also contains the next and previous pointers (doubly-linked)
    private:
    string to;
    string from;
    string message;

    public:
    emailNode(string newTo, string newFrom, string newMessage); //constructor
    string getTo(); //get newTo
    string getFrom(); //get newFrom
    string getMessage(); //get newMessage
    emailNode* next;
    emailNode* previous;

};

class Conversation{ // this will be the Conversation Node, changed to Conversation to make it easier to follow
    public:
    Conversation(string subject, emailNode* email); //constructor
    Conversation(Conversation& otherConvo); //copy constructor
    ~Conversation(); // destructor
    void addEmail(emailNode* email); // add email function (to push to linked list)
    string getSub(); //get subject
    int getSize(); //get size of list
    Conversation* next; //pointer to next in list
    Conversation* previous; //pointer to previous in list

    private:
    string sub; //subject of emails
    int size; //size of email list
    emailNode* convoHead; //declare head pointer
};

class Inbox{ // initialize inbox class
    public:
    Inbox(); // constructor
    Inbox(Inbox& otherInbox); //copy constructor
    ~Inbox(); // destructor
    void insertEmail(string newSubject, emailNode* newEmail); // initialize functions needed with this class
    void deleteConversation(string deleteSubject);
    void displayInbox();

    private:
    Conversation* searchConvo(string newSubject); //searches list for given subject
    Conversation* inboxHead; //pointer to front of list
    Conversation* inboxTail; //pointer to end of list
};

emailNode::emailNode(string newTo, string newFrom, string newMessage){
    to = newTo;
    from = newFrom;
    message = newMessage;
    next = NULL;
    previous = NULL;
}

Conversation::Conversation(string subject, emailNode* email){ //Conversation constructor
    sub = subject;
    convoHead = email;
    convoHead->next = NULL;
    convoHead->previous = NULL;
    size = 1;
}

Conversation::Conversation(Conversation& otherConvo){//Conversation Copy constructor
    this->next = otherConvo.next;
    this->previous = otherConvo.previous;
    this->sub = otherConvo.sub;
    this->size = otherConvo.size;
    this->convoHead = otherConvo.convoHead;
}

Conversation::~Conversation(){ //Conversation destructor
    emailNode* temp = convoHead;
    emailNode* temp2 = convoHead;
    while(temp != NULL){
        temp2 = temp;
        temp = temp->previous;
        delete temp2;
    }
}

void Conversation::addEmail(emailNode* email){ // definition of add emailNode
    email->previous = convoHead; //adds email to front of list
    convoHead = email;
    convoHead->next = NULL;
    size++;
}

Inbox::Inbox(){ // constructor initializes head/size
    inboxHead = NULL;
    inboxTail = NULL;
}

Inbox::Inbox(Inbox& otherInbox){ //inbox copy constructor
    inboxHead = otherInbox.inboxHead;
    inboxTail = otherInbox.inboxTail;
}

Inbox::~Inbox(){ //inbox destructor
    Conversation* temp = inboxHead;
    Conversation* temp2 = inboxHead;
    while(temp != NULL){
        temp2 = temp;
        temp = temp->previous;
        delete temp2;
    }
}

Conversation* Inbox::searchConvo(string newSubject){ // takes in subject and returns a pointer to conversation (or null if subject not found)
    Conversation* temp = inboxHead;
    while(temp != NULL){
        if(temp->getSub() == newSubject){
            return temp; //return subject if it already exists
        }
    }
    return NULL; //return null if subject does not exist
}

void Inbox::displayInbox(){ // prints the Inbox info
    if(inboxHead != NULL){
        Conversation* current = inboxHead;
        int listsize = 0;
        while(current != NULL){
            listsize += current->getSize();
            current = current->previous;
        }
        cout << "Total number of emails in Inbox: " << listsize << endl;
        current = inboxHead;
        while(current != NULL){
            cout << current->getSub() << ": " << current->getSize() << endl;
            current = current->previous;
        }
    }
}

void Inbox::insertemailNode(string newSubject, emailNode* newEmail){ // inserts email
    Conversation* temp = searchConvo(newSubject); //finds if subject already exists
    if(temp != NULL){
        temp->addEmail(newEmail);
        if(temp->next != NULL){
            if(temp->previous != NULL){
                (temp->previous)->next = temp->next;
            }
            else{
                this->inboxTail = temp->previous;
            }
            (temp->next)->previous = temp->previous;
            temp->previous = this->inboxHead;
            temp->next = NULL;
            (this->inboxHead)->next = temp;
            this->inboxHead = temp;
        }
    }
    else{
        temp = new Conversation(newSubject, newEmail);
        if(this->inboxHead != NULL){
            (this->inboxHead)->next = temp;
        }
        temp->previous = this->inboxHead;
        temp->next = NULL;
        this->inboxHead = temp;
        if(this->inboxTail == NULL){
            this->inboxTail = temp;
        }
    }
}

void Inbox::deleteConversation(string deleteSubject){ // deletes a conversation (after checking if one exists)
    Conversation* temp = searchConvo(deleteSubject);
    if(temp != NULL){
        Conversation* next = temp->next;
        Conversation* previous = temp->previous;
        next->previous = previous;
        previous->next = next;
        delete temp;
    }
}

string Conversation::getSub(){return sub;}
int Conversation::getSize(){return size;}
//string emailNode::getTo(){return to;}
//string emailNode::getFrom(){return from;}
//string emailNode::getMessage(){return message;}

int main() { // prompts user for input and calls the appropriate functions based on user response
    string subj = "";
    Inbox inbox; //create new Inbox object
    cout << endl << "Welcome to your inbox!" << endl;
    cout << "Enter each email subject, pressing enter after each one." << endl;
    cout << "To terminate, enter 'done', and your inbox will be displayed." << endl;
    while(getline(cin, subj) && subj != "done"){
        cout << "The subject is: " << subj << endl;
        inbox.insertEmail(subj, new emailNode("to", "from", "message"));
    }
    inbox.displayInbox();

    return 0;
} // end program*/
