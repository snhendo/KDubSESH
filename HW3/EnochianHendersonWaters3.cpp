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
    inbox by using the functions insertEmail, deleteConversation, and displayInbox
    to add emails to the inbox, add emails to communications of the same subject,
    and print the inbox to the user.
Preconditions: None
Postconditions: None
Credit: Referred to Dr. Talaga's examples from CS2
*/


#include <iostream>
#include <string>

using namespace std;


class emailNode {
    public:
    emailNode(string to, string from, string message);//constructor
    string getTo(); //returns to
    string getFrom(); //returns from
    string getMessage(); //returns message
    emailNode* next; //pointer to next email
    emailNode* previous; //pointer to previous email

    private:
    string to;
    string from;
    string message;
};

class Conversation {
    public:
    Conversation* next; //pointer to next conversation
    Conversation* previous; //pointer to previous conversation
    Conversation(string subject, emailNode* email);//constructor
    Conversation(Conversation& other); //copy constructor
    void addEmail(emailNode* email);  //adds new email to front of list
    string getSub(); //returns subject
    int getSize(); //returns list size
    ~Conversation(); //destructor

    private:
    string subject; //inputted subject of new email
    int size; //number of emails in list
    emailNode* emailHead; //pointer to front of email list
};

class Inbox {
    public:
    Inbox(); //constructor
    Inbox(Inbox& other);//copy constructor
    void insertEmail(emailNode* email, string subject);// inserts email into email list
    void deleteConversation(string subject); //deletes conversation with a given subject
    void displayInbox(); //prints current inbox to user
    ~Inbox();//destructor

    private:
    Conversation* searchConvo(string subject); //searches list for given subject
    Conversation* inboxHead; //pointer to head of list
    Conversation* inboxTail; //pointer to tail of list
};

Inbox::Inbox() { // inbox constructor
    inboxHead = NULL;
    inboxTail = NULL;
}

emailNode::emailNode(string to, string from, string message) { // define an emailNode and initialize details (to, from, message, what the next element is and what the previous element is
        this->to = to;
        this->from = from;
        this->message = message;
        this->next = NULL;
        this->previous = NULL;
}

//Getters for the emailNode class
string emailNode::getTo() { return to; }
string emailNode::getFrom() { return from; }
string emailNode::getMessage() { return message; }

Conversation::Conversation(string subject, emailNode* email){ // constructor for Conversation class (Communication nodes); initializes the subject, emailHead, emailHead's next/previous pointers (where they are pointing to), and size of the Conversation
        this->subject = subject;
        emailHead = email;
        emailHead->next = NULL;
        emailHead->previous = NULL;
        size = 1;
}

Conversation::Conversation(Conversation& other) { // copy constructor for Conversation class (Communication nodes), simply copies the conversation and it's details
        this->next = other.next;
        this->previous = other.previous;
        this->subject = other.subject;
        this->size = other.size;
        this->emailHead = other.emailHead;
}

void Conversation::addEmail(emailNode* email) { // new email function takes in a pointer to an email and adds it to the Inbox
        email->previous = emailHead;
        emailHead = email;
        emailHead->next = NULL;
        size++;
}

//Getter functions for the Conversation class (Communication nodes)
string Conversation::getSub() { return subject; }
int Conversation::getSize() { return size; }

Conversation::~Conversation() { // Conversation destructor (for Communication nodes), deletes pointers when no longer needed
    emailNode* temp = emailHead;
    emailNode* temp2 = emailHead;
    while (temp != NULL) {
        temp2 = temp;
        temp = temp->previous;
        delete temp2;
    }
}

Conversation* Inbox::searchConvo(string subject) { // takes in a subject and looks through the Inbox for that subject, returns the pointer and what it points to
    Conversation* temp = inboxHead;
    while (temp != NULL) {
        if (temp->getSub() == subject) { // if the subject is found, we return the temp variable and the value it points to
            return temp;
        }
        temp = temp->previous;
    }
    // if no such communication exists, return NULL (will be added to the inbox in another function
    return NULL;
}

Inbox::Inbox(Inbox& other) { // Inbox copy constructor, copies the inboxHead and inboxTail
    inboxHead = other.inboxHead;
    inboxTail = other.inboxTail;
}

void Inbox::insertEmail(emailNode* email, string subject) { // takes in an email (pointer) and subject and inserts it into the Inbox
    // search for a communication with the given subject to place the email in
    Conversation* temp = searchConvo(subject); // look for the subject that is already in the inbox
    if (temp != NULL) { // if a communication already exists, add the email to the communication
        temp->addEmail(email);
        if (temp->next != NULL) {// if not already there, move the communication to the top of the inbox
            if (temp->previous != NULL) {
                (temp->previous)->next = temp->next;
            }
            else { // "move" the end of the Inbox
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
        // create a new conversation if one does not exist
        temp = new Conversation(subject, email);

        // place the new conversation at the top of the inbox
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

void Inbox::deleteConversation(string subject) { // attempts to remove a conversation by subject, returns true if successful and false if not
    Conversation* temp = searchConvo(subject); // look through inbox for desired subject
    if (temp != NULL) { // if subject is found, delete the conversation and return true
        Conversation* next = temp->next;
        Conversation* previous = temp->previous;
        next->previous = previous;
        previous->next = next;
        delete temp;;
    }
}

void Inbox::displayInbox() { // print function that displays the inbox to the user
    if (inboxHead != NULL) { // as long as the list isn't empty, start at the top of the inbox
        Conversation* current = inboxHead;
        // get total number of emails
        int size = 0;
        while (current != NULL) {
            size += current->getSize();
            current = current->previous;
        }
        cout << "Total number of emails in inbox: " << size << endl; // prints number of emails in the inbox to the user
        // list communications and the number of emails in each one
        current = inboxHead;
        while (current != NULL) {
            cout << current->getSub() << " - " << current->getSize() << endl; // prints subjects and how many emails exist with that same subject
            current = current->previous;
        }
    }
}

Inbox::~Inbox() { // Inbox destructor to delete pointers that are no longer needed
    Conversation* temp = inboxHead;
    Conversation* temp2 = inboxHead;
    while (temp != NULL) {
        temp2 = temp;
        temp = temp->previous;
        delete temp2;
    }
}

int main() {
    string subject = ""; // initialize subject, inbox, and inform the user how to use the program
    Inbox inbox;
    cout << endl << "Welcome to your inbox!" << endl;
    cout << "Enter an email subject, then hit enter after each one. " << endl;
    cout << "To terminate, enter 'done' followed by another enter." << endl << endl;
    // get subjects from user
    while (getline(cin, subject) && subject != "done") { // as long as user doesn't enter done and keeps entering subjects, we will add the emails to the inbox
        inbox.insertEmail(new emailNode("to", "from", "message"), subject);
    }
    inbox.displayInbox(); // when user is done, we will display the inbox
    return 0;
}

// end of program
