#include <iostream>
#include <stdexcept> //For out_of_range
using namespace std;

//Node structure for the linked list
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

//Linked List class
class LinkedList {
protected:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    //Added getter for Iterator access
    Node* getHead() const { return head; }

    virtual void display() = 0; // Pure virtual function for display
    
    //Virtual destructor to prevent memory leaks in derived classes
    virtual ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

//Stack Implementation using Linked List
class Stack : public LinkedList {
public:
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        if (!tail) tail = newNode;
        cout << "Pushed: " << val << endl;
    }

    //Changed from void to int to return the removed value
    int pop() {
        if (!head) {
            cout << "Stack is empty!\n";
            return -1; 
        }
        Node* temp = head;
        int val = temp->data; //Capture data before deletion
        
        head = head->next;
        if (!head) tail = nullptr;
        
        delete temp;
        return val;
    }

    //Returns the top value without removing it
    int peek() {
        return (head) ? head->data : -1;
    }

    void display() override {
        Node* temp = head;
        cout << "Stack (Top to Bottom): ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

//Queue Implementation using Linked List
class Queue : public LinkedList {
public:
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Enqueued: " << val << endl;
    }

    //Changed from void to int to return the removed value
    int dequeue() {
        if (!head) {
            cout << "Queue is empty!\n";
            return -1;
        }
        Node* temp = head;
        int val = temp->data; //Capture data before deletion
        
        head = head->next;
        if (!head) tail = nullptr;
        
        delete temp;
        return val;
    }

    //Returns the front value without removing it
    int peek() {
        return (head) ? head->data : -1;
    }

    void display() override {
        Node* temp = head;
        cout << "Queue (Front to Back): ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

//Custom iterator to traverse the list
class Iterator {
private:
    Node* current;
public:
    Iterator(Node* start) : current(start) {}

    bool hasNext() {
        return current != nullptr;
    }

    int next() {
        if (!current) throw out_of_range("No more elements.");
        int value = current->data;
        current = current->next;
        return value;
    }
};