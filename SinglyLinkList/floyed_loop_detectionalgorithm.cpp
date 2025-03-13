#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to detect loop using Floyd's Cycle Detection Algorithm
bool detectLoop(Node* head) {
    Node* slow = head;  // Tortoise
    Node* fast = head;  // Hare

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;         // Move one step
        fast = fast->next->next;   // Move two steps

        if (slow == fast) {  // If they meet, a loop exists
            return true;
        }
    }

    return false; // No loop found
}

// Function to create a loop for testing
void createLoop(Node* head, int pos) {
    if (pos == 0) return;
    
    Node* temp = head;
    Node* loopNode = nullptr;
    int count = 1;

    while (temp->next != nullptr) {
        if (count == pos) {
            loopNode = temp;  // Mark the node where the loop should start
        }
        temp = temp->next;
        count++;
    }
    temp->next = loopNode;  // Creating the loop
}

// Example usage
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create a loop: 5 -> 3
    createLoop(head, 3);

    if (detectLoop(head)) {
        cout << "Loop detected in the linked list!\n";
    } else {
        cout << "No loop detected.\n";
    }

    return 0;
}
