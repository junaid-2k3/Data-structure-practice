#include <iostream>
#include <queue>
using namespace std;

// Node structure for Linked List based Queue
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Linked List based Queue
class LinkedListQueue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    LinkedListQueue() : front(nullptr), rear(nullptr), size(0) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        Node* temp = front;
        int value = temp->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        size--;
        return value;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// 1) Function to swap even positions in queue
void swapEvenPositions(queue<int>& q) {
    if (q.size() < 4) return;
    
    int size = q.size();
    queue<int> temp;
    
    // Store first half
    for (int i = 0; i < size / 2; i++) {
        temp.push(q.front());
        q.pop();
    }
    
    // Swap even positions
    for (int i = 0; i < size / 2; i++) {
        if (i % 2 == 1) {
            int val1 = temp.front();
            temp.pop();
            int val2 = q.front();
            q.pop();
            q.push(val2);
            temp.push(val1);
        } else {
            q.push(temp.front());
            temp.pop();
        }
    }
}

// 3)Function to interleave first and second halves
void interleaveHalves(queue<int>& q) {
    if (q.size() % 2 != 0) {
        cout << "Queue size must be even!" << endl;
        return;
    }
    
    int size = q.size();
    queue<int> temp;
    
    // Store first half
    for (int i = 0; i < size / 2; i++) {
        temp.push(q.front());
        q.pop();
    }
    
    // Interleave
    while (!temp.empty()) {
        q.push(temp.front());
        temp.pop();
        q.push(q.front());
        q.pop();
    }
}

// 4)Function to check if queue is palindrome
bool isPalindrome(queue<int> q) {
    if (q.empty()) return true;
    
    int size = q.size();
    int* arr = new int[size];
    
    // Store queue elements in array
    for (int i = 0; i < size; i++) {
        arr[i] = q.front();
        q.pop();
    }
    
    // Check palindrome
    bool result = true;
    for (int i = 0; i < size / 2; i++) {
        if (arr[i] != arr[size - 1 - i]) {
            result = false;
            break;
        }
    }
    
    delete[] arr;
    return result;
}

int main() {
    int choice, value;
    queue<int> q;
    LinkedListQueue llq;
    
    do {
        cout << "\n===== QUEUE OPERATIONS MENU =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Swap Even Positions" << endl;
        cout << "5. Interleave Halves" << endl;
        cout << "6. Check Palindrome" << endl;
        cout << "7. Linked List Queue Operations" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.push(value);
                break;
            }
            case 2: {
                if (!q.empty()) {
                    cout << "Dequeued value: " << q.front() << endl;
                    q.pop();
                } else {
                    cout << "Queue is Empty!" << endl;
                }
                break;
            }
            case 3: {
                if (q.empty()) {
                    cout << "Queue is Empty!" << endl;
                } else {
                    cout << "Queue: ";
                    queue<int> temp = q;
                    while (!temp.empty()) {
                        cout << temp.front() << " ";
                        temp.pop();
                    }
                    cout << endl;
                }
                break;
            }
            case 4: {
                swapEvenPositions(q);
                cout << "Even positions swapped!" << endl;
                break;
            }
            case 5: {
                interleaveHalves(q);
                cout << "Halves interleaved!" << endl;
                break;
            }
            case 6: {
                if (isPalindrome(q)) {
                    cout << "Queue is a palindrome!" << endl;
                } else {
                    cout << "Queue is not a palindrome!" << endl;
                }
                break;
            }
            case 7: {
                int subChoice;
                do {
                    cout << "\n===== LINKED LIST QUEUE OPERATIONS =====" << endl;
                    cout << "1. Enqueue" << endl;
                    cout << "2. Dequeue" << endl;
                    cout << "3. Display Queue" << endl;
                    cout << "4. Back to Main Menu" << endl;
                    cout << "Enter your choice: ";
                    cin >> subChoice;
                    
                    switch (subChoice) {
                        case 1: {
                            cout << "Enter value to enqueue: ";
                            cin >> value;
                            llq.enqueue(value);
                            break;
                        }
                        case 2: {
                            value = llq.dequeue();
                            if (value != -1) {
                                cout << "Dequeued value: " << value << endl;
                            }
                            break;
                        }
                        case 3: {
                            llq.display();
                            break;
                        }
                        case 4: {
                            break;
                        }
                        default: {
                            cout << "Invalid choice!" << endl;
                        }
                    }
                } while (subChoice != 4);
                break;
            }
            case 8: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice!" << endl;
            }
        }
    } while (choice != 8);
    
    return 0;
} 