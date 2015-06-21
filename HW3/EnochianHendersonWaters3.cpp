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
#include <string>

using namespace std;

class Conversation{ // this will be the Communication Node, changed to Conversation to make it easier to follow
    public:

    Conversation(); // constructor
    ~Conversation(); // destructor
    void addEmail(string newTo, string newFrom, string newMessage); // add email function (to push to linked list)

    private:

    class emailNode{ // create email node that contains the to/from/message and also contains the next and previous pointers (doubly-linked)
        public:
        string to;
        string from;
        string message;
        emailNode* next;
        emailNode* previous;
    };
    emailNode* head; // create head pointer
    int count; // initialize counter
};

Conversation::Conversation(){ // constructor initializes head and count
    head = NULL;
    count = 0;
}

Conversation::~Conversation(){} // destructor

void Conversation::addEmail(string newTo, string newFrom, string newMessage){ // definition of add Email
    if(true){ // are there items already in the list (if not, make new one)
        emailNode* newEmailNode = new emailNode; // create new Email node
        head = newEmailNode; // have head point to the new node
        head->to = newTo; // put user-entered value in the To of the node
        head->from = newFrom; // put user-entered value in the From of the node
        head->message = newMessage; // put user-entered message into the Message of the node
        head->next = NULL; // next points to NULL
        head->previous = NULL; // previous points to NULL
        //count++; // increment count (number of emails per conversation)
    }else{ // at least one item in the list
        emailNode* temp = new emailNode; // create temp pointer that points to the same location as head
        temp = head;
        emailNode* newHead = new emailNode; // initialize newHead
        temp->previous = head; // temp previous points to the original beginning of the list
        head = newHead; // newHead points to new Node at the beginning of list
        head->to = newTo; // newTwo/newFrom/newMessage are all components of the new node
        head->from = newFrom;
        head->message = newMessage;
        head->next = temp; // head next points to where temp was pointing
        head->previous = NULL; // just verify that there's no previous
        count++; // increment count (number of emails per conversation)
    }
}

class Inbox{ // initialize inbox class
    public:

    Inbox(); // constructor
    ~Inbox(); // destructor
    void insertEmail(string newSubject, string newTo, string newFrom, string newMessage); // initialize functions needed with this class
    void deleteCommunication(string deleteSubject);
    void displayInbox() const;

    private:

    class commNode{ // initialize communication Node
        public:
        string subject; // contains subject
        int emailCount; // number of emails with that subject
        commNode* next; // next and previous variables (doubly-linked list)
        commNode* previous;
        Conversation* emailNode; // points to the conversation chain
    };
    commNode* head; // head pointer
    int size; // initialize size (number of emails period)
    commNode* searchCommunication(string newSubject) const; // initialize a function to allow it to return a pointer
};

Inbox::Inbox(){ // constructor initializes head/size
    head = NULL;
    size = 0;
}

Inbox::~Inbox(){} // destructor

Inbox::commNode* Inbox::searchCommunication(string newSubject) const{ // takes in subject and returns a pointer to conversation (or null if subject not found)
    commNode* temp = new commNode; // temp points to same location as head
    temp = head;
    while (temp != NULL){ // if temp is not null (list not empty)
        if(temp->subject == newSubject){ // search for subject
            return temp; // when found, return temp
        }
        if(temp->next != NULL){ // if temp->next is not null, "increment" temp to step through
            temp = temp->next;
        }else{
            return NULL; // otherwise return a null pointer
        }
    }
    return NULL;
}

void Inbox::displayInbox() const{ // prints the Inbox info
    cout << "Inbox: total number of emails is " << size << endl;
    commNode* temp = new commNode;
    temp = head;
    while(temp != NULL){
        cout << temp->subject << " - " << temp->emailCount << endl;
        if(temp->next != NULL){
            temp = temp->next;
        }else{
            temp = NULL;
        }
    }
}

void Inbox::insertEmail(string newSubject, string newTo, string newFrom, string newMessage){ // inserts email
    if(head == NULL){
      commNode* newCommNode = new commNode; //create a new commNode
      head = newCommNode; // head points to it
      head->previous = NULL; // head previous points to NULL
      head->next = NULL; // head next points to NULL
      head->emailCount = 1;
      head->subject = newSubject; // assign subject of email to subject element of node
      Conversation* newConversation; // create a new Conversation pointer
      head->emailNode = newConversation;
      newConversation->addEmail(newTo, newFrom, newMessage); // add email to conversation pointer
      newCommNode->next = NULL; // next and previous are set to NULL
      newCommNode->previous = NULL;
      cout << "Email added to new conversation." << endl;
      return;
    }
    commNode* temp = searchCommunication(newSubject); //checks for subject
    if(temp == NULL){ // no subject found == insert the email at the beginning of list as new conversation
        temp = head;
        commNode* newCommNode = new commNode;
        head = newCommNode;
      head->next = temp;
        head->previous = NULL;
        temp->previous = head;
        head->emailCount = 1;
        head->subject = newSubject;
        Conversation* newConversation = new Conversation;
        head->emailNode = newConversation;
        newConversation->addEmail(newTo, newFrom, newMessage);
        newCommNode->next = NULL;
        newCommNode->previous = NULL;
        cout << "Email added to new conversation." << endl;
    }else{ // subject found = attach to existing list of conversations with that subject and move to beginning of list
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
        commNode* tempHead = head;
        head = temp;
        head->previous = NULL;
        head->next = tempHead;
        tempHead->previous = head;
        head->emailCount++;
        head->emailNode->addEmail(newTo, newFrom, newMessage);
        cout << "Email added to existing conversation." << endl;
    }
    size++; // increment size
}

void Inbox::deleteCommunication(string deleteSubject){ // deletes a conversation (after checking if one exists)
    commNode* temp = new commNode;
    temp = searchCommunication(deleteSubject);
    if(temp == NULL){
        cout << "Conversation does not exist." << endl;
    }else{
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
        size--;
        cout << "Conversation deleted." << endl;
    }
}

int main() { // prompts user for input and calls the appropriate functions based on user response
    cout << "Welcome to your Inbox!" << endl;
    Inbox inbox;
    string command = ""; // initialize empty string
    while(command != "done"){ // until user terminates program, we want to run through the following
        command = ""; // initialize to empty string again (for more than one loop)
        cout << "To terminate, enter 'done'." << endl
            << "To insert an email, enter 'insert'." << endl
            << "To delete a conversation, enter 'delete'."
            << endl << "To display your inbox, enter 'display'." << endl;
        cin >> command;
        if(command == "insert"){ // calls necessary functions for insert
            string newSubject, newTo, newFrom, newMessage;
            cout << "Subject?" << endl;
            cin >> newSubject;
            cout << "To?" << endl;
            cin >> newTo;
            cout << "From?" << endl;
            cin >> newFrom;
            cout << "Message?" << endl;
            cin >> newMessage;
            inbox.insertEmail(newSubject, newTo, newFrom, newMessage);
        }else if(command == "delete"){ // calls necessary functions for delete
            string deleteSubject;
            cout << "Subject?" << endl;
            cin >> deleteSubject;
            inbox.deleteCommunication(deleteSubject);
        }else if(command == "display"){ // calls necessary functions for display
            inbox.displayInbox();
        }else if(command == "done"){ // terminates program
            return 0;
        }else{
            cout << "That command was not recognized." << endl; // for invalid entries
        }
    }
    return 0;
} // end program
