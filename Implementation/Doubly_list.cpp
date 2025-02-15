// internal implementation of doubly list (stl list )
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Doubly Linked List Class
class MyList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    MyList() : head(nullptr), tail(nullptr), size(0) {}

    // Add element to the front
    void push_front(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    // Add element to the back
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    // Remove the front element
    void pop_front() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;  // List is empty now
        delete temp;
        size--;
    }

    // Remove the back element
    void pop_back() {
        if (!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;  // List is empty now
        delete temp;
        size--;
    }

    // Print the list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Get size of the list
    int getSize() {
        return size;
    }
};

int main() {
    MyList myList;
    myList.push_front(10);
    myList.push_front(20);
    myList.push_back(30);
    myList.push_back(40);

    cout << "List: ";
    myList.display(); // Output: 20 10 30 40

    myList.pop_front();
    myList.pop_back();

    cout << "After popping front & back: ";
    myList.display(); // Output: 10 30

    return 0;
}
