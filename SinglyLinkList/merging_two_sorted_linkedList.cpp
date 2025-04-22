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

// Function to merge two sorted linked lists
Node* mergeSortedLists(Node* one, Node* two) {
    // If either list is empty, return the other
    if (!one) return two;
    if (!two) return one;

    // Dummy node to simplify handling the head of the result list
    Node* dummy = new Node(-1);
    Node* tail = dummy;

    while (one != nullptr && two != nullptr) {
        if (one->data <= two->data) {
            tail->next = one;
            one = one->next;
        } else {
            tail->next = two;
            two = two->next;
        }
        tail = tail->next;
    }

    // If any list still has nodes, attach them to the result
    if (one) tail->next = one;
    if (two) tail->next = two;

    Node* mergedHead = dummy->next;
    delete dummy; // Free the dummy node
    return mergedHead;
}

// Function to print a linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Example usage
int main() {
    Node* one = new Node(1);
    one->next = new Node(3);
    one->next->next = new Node(5);

    Node* two = new Node(2);
    two->next = new Node(4);
    two->next->next = new Node(6);

    cout << "List 1: ";
    printList(one);
    cout << "List 2: ";
    printList(two);

    Node* mergedHead = mergeSortedLists(one, two);
    cout << "Merged Sorted List: ";
    printList(mergedHead);

    return 0;
}


