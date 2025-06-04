#include <iostream>
using namespace std;

// Node structure for Singly Linked List
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};


// Singly Linked List Class
class SinglyLinkedList {
private:
    Node* head;
    int size;

public:
    SinglyLinkedList() : head(nullptr), size(0) {}

    // Insert at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    // Insert at position
    void insertAtPosition(int val, int pos) {
        if (pos < 0 || pos > size) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 0) {
            insertAtBeginning(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }

    // Delete from beginning
    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    // Delete from end
    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
        size--;
    }

    // Delete from position
    void deleteFromPosition(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 0) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        size--;
    }

    // 1)Split list into two halves
    void splitList(SinglyLinkedList& first, SinglyLinkedList& second) {
        if (!head) return;
        
        Node* slow = head;
        Node* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // First half
        first.head = head;
        first.size = (size + 1) / 2;
        
        // Second half
        second.head = slow->next;
        second.size = size / 2;
        
        slow->next = nullptr;
        head = nullptr;
        size = 0;
    }

    // 2) Sorted insert
    void sortedInsert(int val) {
        Node* newNode = new Node(val);
        if (!head || head->data <= val) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && current->next->data > val) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        size++;
    }

    // 3) Reverse alternate k nodes
    Node* reverseAlternateKNodes(Node* head, int k, bool reverse) {
        if (!head) return nullptr;
        
        Node* current = head;
        Node* next = nullptr;
        Node* prev = nullptr;
        int count = 0;
        
        if (reverse) {
            while (current && count < k) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
                count++;
            }
            if (next) {
                head->next = reverseAlternateKNodes(next, k, !reverse);
            }
            return prev;
        } else {
            while (current && count < k) {
                prev = current;
                current = current->next;
                count++;
            }
            if (current) {
                prev->next = reverseAlternateKNodes(current, k, !reverse);
            }
            return head;
        }
    }

    void reverseAlternateK(int k) {
        head = reverseAlternateKNodes(head, k, true);
    }

    // 5) Find middle node
    Node* findMiddle() {
        if (!head) return nullptr;
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }

    // 6) Find nth node from end
    Node* findNthFromEnd(int n) {
        if (n <= 0 || !head) return nullptr;
        
        Node* first = head;
        Node* second = head;
        
        for (int i = 0; i < n; i++) {
            if (!first) return nullptr;
            first = first->next;
        }
        
        while (first) {
            first = first->next;
            second = second->next;
        }
        
        return second;
    }

    // Display list
    void display() {
        Node* temp = head;
        cout << "List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

//****************************end of singlylist operations  **********************/
// Node structure for Doubly Linked List
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};
// Doubly Linked List Class
class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Insert at beginning
    void insertAtBeginning(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    // Insert at end
    void insertAtEnd(int val) {
        DNode* newNode = new DNode(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    // Insert at position
    void insertAtPosition(int val, int pos) {
        if (pos < 0 || pos > size) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 0) {
            insertAtBeginning(val);
            return;
        }
        if (pos == size) {
            insertAtEnd(val);
            return;
        }
        
        DNode* newNode = new DNode(val);
        DNode* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        size++;
    }

    // Delete from beginning
    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        DNode* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        size--;
    }

    // Delete from end
    void deleteFromEnd() {
        if (!tail) {
            cout << "List is empty!" << endl;
            return;
        }
        DNode* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        size--;
    }

    // Delete from position
    void deleteFromPosition(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 0) {
            deleteFromBeginning();
            return;
        }
        if (pos == size - 1) {
            deleteFromEnd();
            return;
        }
        
        DNode* temp = head;
        for (int i = 0; i < pos; i++) {
            temp = temp->next;
        }
        
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        size--;
    }

    // Display list
    void display() {
        DNode* temp = head;
        cout << "List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Display list in reverse
    void displayReverse() {
        DNode* temp = tail;
        cout << "List (Reverse): ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList sll;
    DoublyLinkedList dll;
    int choice, subChoice, value, position, k;
    
    do {
        cout << "\n===== LINKED LIST OPERATIONS MENU =====" << endl;
        cout << "1. Singly Linked List Operations" << endl;
        cout << "2. Doubly Linked List Operations" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                do {
                    cout << "\n===== SINGLY LINKED LIST OPERATIONS =====" << endl;
                    cout << "1. Insert at Beginning" << endl;
                    cout << "2. Insert at End" << endl;
                    cout << "3. Insert at Position" << endl;
                    cout << "4. Delete from Beginning" << endl;
                    cout << "5. Delete from End" << endl;
                    cout << "6. Delete from Position" << endl;
                    cout << "7. Split List into Two Halves" << endl;
                    cout << "8. Sorted Insert" << endl;
                    cout << "9. Reverse Alternate K Nodes" << endl;
                    cout << "10. Find Middle Node" << endl;
                    cout << "11. Find Nth Node from End" << endl;
                    cout << "12. Display List" << endl;
                    cout << "13. Back to Main Menu" << endl;
                    cout << "Enter your choice: ";
                    cin >> subChoice;
                    
                    switch (subChoice) {
                        case 1: {
                            cout << "Enter value to insert: ";
                            cin >> value;
                            sll.insertAtBeginning(value);
                            break;
                        }
                        case 2: {
                            cout << "Enter value to insert: ";
                            cin >> value;
                            sll.insertAtEnd(value);
                            break;
                        }
                        case 3: {
                            cout << "Enter value and position: ";
                            cin >> value >> position;
                            sll.insertAtPosition(value, position);
                            break;
                        }
                        case 4: {
                            sll.deleteFromBeginning();
                            break;
                        }
                        case 5: {
                            sll.deleteFromEnd();
                            break;
                        }
                        case 6: {
                            cout << "Enter position to delete: ";
                            cin >> position;
                            sll.deleteFromPosition(position);
                            break;
                        }
                        case 7: {
                            SinglyLinkedList first, second;
                            sll.splitList(first, second);
                            cout << "First half: ";
                            first.display();
                            cout << "Second half: ";
                            second.display();
                            break;
                        }
                        case 8: {
                            cout << "Enter value to insert: ";
                            cin >> value;
                            sll.sortedInsert(value);
                            break;
                        }
                        case 9: {
                            cout << "Enter k value: ";
                            cin >> k;
                            sll.reverseAlternateK(k);
                            break;
                        }
                        case 10: {
                            Node* middle = sll.findMiddle();
                            if (middle) {
                                cout << "Middle node value: " << middle->data << endl;
                            }
                            break;
                        }
                        case 11: {
                            cout << "Enter n value: ";
                            cin >> position;
                            Node* nth = sll.findNthFromEnd(position);
                            if (nth) {
                                cout << "Nth node from end: " << nth->data << endl;
                            }
                            break;
                        }
                        case 12: {
                            sll.display();
                            break;
                        }
                        case 13: {
                            break;
                        }
                        default: {
                            cout << "Invalid choice!" << endl;
                        }
                    }
                } while (subChoice != 13);
                break;
            }
            case 2: {
                do {
                    cout << "\n===== DOUBLY LINKED LIST OPERATIONS =====" << endl;
                    cout << "1. Insert at Beginning" << endl;
                    cout << "2. Insert at End" << endl;
                    cout << "3. Insert at Position" << endl;
                    cout << "4. Delete from Beginning" << endl;
                    cout << "5. Delete from End" << endl;
                    cout << "6. Delete from Position" << endl;
                    cout << "7. Display List" << endl;
                    cout << "8. Display List in Reverse" << endl;
                    cout << "9. Back to Main Menu" << endl;
                    cout << "Enter your choice: ";
                    cin >> subChoice;
                    
                    switch (subChoice) {
                        case 1: {
                            cout << "Enter value to insert: ";
                            cin >> value;
                            dll.insertAtBeginning(value);
                            break;
                        }
                        case 2: {
                            cout << "Enter value to insert: ";
                            cin >> value;
                            dll.insertAtEnd(value);
                            break;
                        }
                        case 3: {
                            cout << "Enter value and position: ";
                            cin >> value >> position;
                            dll.insertAtPosition(value, position);
                            break;
                        }
                        case 4: {
                            dll.deleteFromBeginning();
                            break;
                        }
                        case 5: {
                            dll.deleteFromEnd();
                            break;
                        }
                        case 6: {
                            cout << "Enter position to delete: ";
                            cin >> position;
                            dll.deleteFromPosition(position);
                            break;
                        }
                        case 7: {
                            dll.display();
                            break;
                        }
                        case 8: {
                            dll.displayReverse();
                            break;
                        }
                        case 9: {
                            break;
                        }
                        default: {
                            cout << "Invalid choice!" << endl;
                        }
                    }
                } while (subChoice != 9);
                break;
            }
            case 3: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice!" << endl;
            }
        }
    } while (choice != 3);
    
    return 0;
} 