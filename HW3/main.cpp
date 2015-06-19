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

class Conversation(){
    public:

    Conversation();
    ~Conversation();
    void addEmail();

    private:

    class emailNode{
        public:
        string to;
        string from;
        string message;
    }
    emailNode* head;
    int count;
}

Conversation::Conversation(){
    head = NULL;
    count = 0;
}

Conversation::~Conversation();

Conversation::addEmail(string newTo, string newFrom, string newMessage){
    if(count == 0){
        head = new emailNode* newEmailNode;
        newEmailNode->to = newTo;
        newEmailNode->from = newFrom;
        newEmailNode->message = newMessage;
        newEmailNode->next = NULL;
        newEmailNode->previous = NULL;
        count++;
    }else{
        emailNode temp = head;
        head = new emailNode* newHead;
        temp->previous = head;
        head->to = newTo;
        head->from = newFrom;
        head->message = newMessage;
        head->next = temp;
        head->previous = NULL;
        count++;
    }
}

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
        commNode* emailNode;
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

void Inbox::insertEmail(string newSubject, string newTo, string newFrom, string newMessage) const{
    commNode* temp = searchCommunication(newSubject);
    if(temp == NULL){
        temp = head;
        head = new commNode* newCommNode;
        newCommNode->next = temp;
        newCommNode->emailCount = 1;
        newCommNode->subject = newSubject;
        newCommNode->emailNode = new Conversation newConversation;
        newConversation.addEmail(newTo, newFrom, newMessage);
        newCommNode->next = NULL;
        newCommNode->previous = NULL;
        cout << "Email added to new conversation." << endl;
    }else{
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
        commNode* tempHead = head;
        head = temp;
        head->previous = NULL;
        head->next = tempHead;
        tempHead->previous = head;
        head->emailCount++;
        head->emailNode.addEmail(newTo, newFrom, newMessage);
        cout << "Email added to existing conversation." << endl;
    }
}

void Inbox::deleteConversation(string deleteSubject){
    commNode* temp = searchCommunication(deleteSubject);
    if(temp == NULL){
        cout << "Conversation does not exist." << endl;
    }else{
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
        emailCount--;
        cout << "Conversation deleted." << endl;
    }
}

int main() {
    cout << "Welcome to your Inbox!" << endl;
    Inbox inbox;
    string command = "";
    while(command != "done"){
        cout << "To terminate the program, enter 'done'." << endl << "To insert an email, enter 'insert'." << endl << "To delete a conversation, enter 'delete'." << endl << "To display your inbox, enter 'display'." << endl;
        cin >> command;
        if(command == "insert"){
            cout << "Subject?" << endl;
            cin >> string newSubject;
            cout << "To?" << endl;
            cin >> string newTo;
            cout << "From?" << endl;
            cin >> string newFrom;
            cout << "Message?" << endl;
            cin >> string newMessage;
            inbox.insertEmail(newSubject, newTo, newFrom, newMessage);
        }else if(command == "delete"){
            cout << "Subject?" << endl;
            cin >> string deleteSubject;
            inbox.deleteConversation(deleteSubject);
        }else if(command == "display"){
            inbox.displayInbox();
        }else{
            cout << "That command was not recognized." << endl;
        }
    }

    return 0;

}
