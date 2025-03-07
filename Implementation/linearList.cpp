#include <iostream>
#include <stack>
const short INSERTION_AT_BEGINNING = 1;
const short DISPLAY = 2;
const short INSERTION_AT_END = 3;
const short INSERTION_AFTER_VALUE = 4;
const short DELETE_BY_VALUE = 5;
const short SEARCH_BY_VALUE = 6;
const short COUNT_NODES = 7;
const short REVERSE_LIST = 8;
const short DISPLAY_REVERSE = 9;
const short EXIT_PROGRAM = 10;

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val = 0) : data(val), next(nullptr) {}
    //   ~Node(){delete next;}
};
class LinkedList
{
private:
    Node *head;
    int val, afterVal;

public:
    LinkedList() : val(0), head(nullptr), afterVal(0) {}
    void insertionAtBeginning()
    {
        cout << "\n enter value for the node = ";
        cin >> val;
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    bool isListEmpty()
    {
        return (head == nullptr) ? true : false;
    }
    void display()
    {
        if (isListEmpty())
        {
            cout << "\n list is empty ";
            return;
        }
        Node *traversalNode = head;
        cout << "\n values in the linked list = ";
        while (traversalNode != nullptr)
        {
            cout << traversalNode->data << "    ";
            traversalNode = traversalNode->next;
        }
    }
    void insertionAtEnd()
    {
        cout << "\n enter value for the node = ";
        cin >> val;
        Node *newNode = new Node(val);
        if (isListEmpty())
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node *traversalNode;
        for (traversalNode = head; traversalNode->next != nullptr;
             traversalNode = traversalNode->next)
            ;
        traversalNode->next = newNode;
    }
    void insertionAfterValue()
    {
        cout << "\n enter value after which you wish to insert new node = ";
        cin >> afterVal;
        Node *traversalNode = head;
        while (traversalNode != nullptr && traversalNode->data != afterVal)
            traversalNode = traversalNode->next;
        if (traversalNode == nullptr)
        {
            cout << "\n value not present in the list. \n";
            return;
        }
        cout << "\n value found, enter data value for the new node = ";
        cin >> val;
        Node *newNode = new Node(val);
        newNode->next = traversalNode->next;
        traversalNode->next = newNode;
    }
    void deleteByValue()
    {
        if (isListEmpty())
        {
            cout << "\n list is empty. ";
            return;
        }
        cout << "\n enter the data value of node you wish to delete = ";
        cin >> val;
        if (head->data == val)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *traversalNode = head;
        Node *previous = nullptr;
        while (traversalNode != nullptr && traversalNode->data != val)
        {
            previous = traversalNode;
            traversalNode = traversalNode->next;
        }
        if (traversalNode == nullptr)
        {
            cout << "\n value not found in the list ";
            return;
        }
        previous->next = traversalNode->next;
        delete traversalNode;
    }
    bool searchByValue()
    {
        if (isListEmpty())
        {
            cout << "\n list is empty, nothing to search!";
            return false;
        }
        cout << "\n enter the data value of the node you wish to search = ";
        cin >> val;
        Node *traversalNode = head;
        while (traversalNode != nullptr && traversalNode->data != val)
        {
            traversalNode = traversalNode->next;
        }
        return (traversalNode == nullptr) ? false : true;
    }
    int countNodes()
    {
        int counter = 0;
        if (isListEmpty())
        {
            cout << "\n List is empty. ";
            return counter;
        }
        for (Node *traversalNode = head; traversalNode != nullptr;
             ++counter, traversalNode = traversalNode->next)
            ;
        return counter;
    }
    void reverseList()
    {
        Node *previousNode = nullptr;
        Node *currentNode = head;
        Node *nextNode = nullptr;
        while (currentNode != nullptr)
        {
            nextNode = currentNode->next;
            currentNode->next = previousNode;
            previousNode = currentNode;
            currentNode = nextNode;
        }
        head = previousNode;
        cout << "\n List successfully reversed. ";
    }
    void displayReverseUsingStack()
    {
        if (isListEmpty())
        {
            cout << "\n List is empty";
            return;
        }
        stack<int> NodeData;
        Node *traversalNode = head;
        while (traversalNode != nullptr)
        {
            NodeData.push(traversalNode->data);
            traversalNode = traversalNode->next;
        }
        cout << "\n showing list values in revers order = ";
        while (!NodeData.empty())
        {
            cout << NodeData.top() << "   ";
            NodeData.pop();
        }
    }
};

void dislayMenu()
{
    cout << "\n    *****Linked List ADT Menu****"
         << "\n 1 Insertion at beginning"
         << "\n 2 Display List"
         << "\n 3 Insertion at End"
         << "\n 4 Insertion after specific value"
         << "\n 5 Delete Node by Data value"
         << "\n 6 Search Node by Data value"
         << "\n 7 Count Nodes in the linked list"
         << "\n 8 Reverse List"
         << "\n 9 Display Reverse List using STACK"
         << "\n 10 Exit Program";
}

int main()
{
    LinkedList list1;
    int choice = 1, countedNodes = 0;
    bool found = false;
    while (choice != EXIT_PROGRAM)
    {
        system("cls");
        dislayMenu();
        cout << "\n enter you choice = "; 
        cin >> choice;
        switch (choice)
        {
        case INSERTION_AT_BEGINNING:
            list1.insertionAtBeginning();
            break;
        case DISPLAY:
            list1.display();
            break;
        case INSERTION_AT_END:
            list1.insertionAtEnd();
            break;
        case INSERTION_AFTER_VALUE:
            list1.insertionAfterValue();
            break;
        case DELETE_BY_VALUE:
            list1.deleteByValue();
            break;
        case SEARCH_BY_VALUE:
            found = list1.searchByValue();
            cout << "\n found = " << boolalpha << found;
            break;
        case COUNT_NODES:
            countedNodes = list1.countNodes();
            cout << "\n # of Nodes = " << countedNodes;
            break;
        case REVERSE_LIST:
            list1.reverseList();
            break;
        case DISPLAY_REVERSE:
            list1.displayReverseUsingStack();
            break;
        case EXIT_PROGRAM:
            break;
        default:
            cout << "\n wrong choice, try again ";
        }
        if (choice != EXIT_PROGRAM)
        {
            cin.ignore();
            cout << "\n\n press enter key to continue ";
            cin.get();
        }
    }

    return 0;
}

