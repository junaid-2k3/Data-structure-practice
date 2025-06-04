#include <iostream>
using namespace std;

// Node structure for Linked List
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to create a new node
Node* createNode(int value) {
    return new Node(value);
}

// Function to insert a node in sorted order in linked list
void sortedInsert(Node** head, Node* newNode) {
    if (*head == nullptr || (*head)->data >= newNode->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != nullptr && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to perform bubble sort on linked list
void bubbleSortLinkedList(Node** head) {
    if (*head == nullptr || (*head)->next == nullptr) return;
    
    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;
    
    do {
        swapped = false;
        ptr1 = *head;
        
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1->data, ptr1->next->data);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Function to perform insertion sort on array
void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = *(arr + i);
        int j = i - 1;
        
        while (j >= 0 && *(arr + j) > key) {
            *(arr + j + 1) = *(arr + j);
            j--;
        }
        *(arr + j + 1) = key;
    }
}

// Function to perform selection sort on linked list
void selectionSortLinkedList(Node** head) {
    if (*head == nullptr || (*head)->next == nullptr) return;
    
    Node* current = *head;
    while (current != nullptr) {
        Node* min = current;
        Node* temp = current->next;
        
        while (temp != nullptr) {
            if (temp->data < min->data) {
                min = temp;
            }
            temp = temp->next;
        }
        
        swap(current->data, min->data);
        current = current->next;
    }
}

// Function to merge two sorted linked lists
Node* merge(Node* left, Node* right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;
    
    Node* result = nullptr;
    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

// Function to perform merge sort on linked list
void mergeSortLinkedList(Node** head) {
    if (*head == nullptr || (*head)->next == nullptr) return;
    
    // Split the list into two halves
    Node* slow = *head;
    Node* fast = (*head)->next;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    Node* left = *head;
    Node* right = slow->next;
    slow->next = nullptr;
    
    // Recursively sort both halves
    mergeSortLinkedList(&left);
    mergeSortLinkedList(&right);
    
    // Merge the sorted halves
    *head = merge(left, right);
}

// Function to display linked list
void displayLinkedList(Node* head) {
    cout << "Linked List: ";
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to display array
void displayArray(int* arr, int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int main() {
    int choice, size, value;
    Node* head = nullptr;
    int* arr = nullptr;
    
    do {
        cout << "\n===== SORTING ALGORITHMS MENU =====" << endl;
        cout << "1. Sorted Insert in Linked List" << endl;
        cout << "2. Bubble Sort Using Linked List" << endl;
        cout << "3. Insertion Sort for Array" << endl;
        cout << "4. Selection Sort for Linked List" << endl;
        cout << "5. Merge Sort Using Recursion" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                cout << "Enter value to insert: ";
                cin >> value;
                Node* newNode = createNode(value);
                sortedInsert(&head, newNode);
                displayLinkedList(head);
                break;
            }
            case 2: {
                bubbleSortLinkedList(&head);
                cout << "Linked List sorted using Bubble Sort!" << endl;
                displayLinkedList(head);
                break;
            }
            case 3: {
                cout << "Enter size of array: ";
                cin >> size;
                arr = new int[size];
                cout << "Enter " << size << " elements: ";
                for (int i = 0; i < size; i++) {
                    cin >> *(arr + i);
                }
                insertionSort(arr, size);
                cout << "Array sorted using Insertion Sort!" << endl;
                displayArray(arr, size);
                delete[] arr;
                break;
            }
            case 4: {
                selectionSortLinkedList(&head);
                cout << "Linked List sorted using Selection Sort!" << endl;
                displayLinkedList(head);
                break;
            }
            case 5: {
                mergeSortLinkedList(&head);
                cout << "Linked List sorted using Merge Sort!" << endl;
                displayLinkedList(head);
                break;
            }
            case 6: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice!" << endl;
            }
        }
    } while (choice != 6);
    
    // Clean up linked list
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
} 