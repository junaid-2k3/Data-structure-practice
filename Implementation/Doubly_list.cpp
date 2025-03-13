#include <iostream>
using namespace std;

struct Node
{
    Node *next;
    Node *prev;
    int data;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class doubly_list
{
public:
    Node *head;
    Node *tail;
    int val;
    int afterval;

    doubly_list() : val(0), afterval(0), head(nullptr), tail(nullptr) {}

    // operations for doubly lint list
    // insertion
    bool is_empty()
    {
        if (!head && !tail)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool is_circular()
    {
        if (head->prev == tail && tail->next == head)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void insertion_at_the_begining(int v)
    {
        // three checks --
        Node *newNode = new Node(v);
        if (is_empty())
        {
            head = newNode;
            tail = newNode;
            cout << "first node" << endl;
            return;
        }
        else if (is_circular())
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            head->prev = tail;
            tail->next = head;
            return;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            cout << "node inserted" << endl;
        }
    }

    void insertion_at_end(int v)
    {
        Node *newNode = new Node(v);
        if (is_empty())
        {
            head = newNode;
            tail = newNode;
            cout << "first node" << endl;
            return;
        }
        else if (is_circular())
        {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = tail->next;
            return;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            cout << "node inserted at the end" << endl;
        }
    }
    void insertion_afterVal(int tar, int val)
    {
        Node *newNode = new Node((val));
        Node *temp = head;
        while (temp->data != tar)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }
    void display_list()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << "list item : " << temp->data << endl;
            temp = temp->next;
        }
    }
    bool search_value(int tar)
    {
        Node *temp = head;
        while (temp->data != tar || temp->next != nullptr)
        {
            temp = temp->next;
        }
        if (temp->data == tar)
        {
            cout << "value found" << endl;
            return true;
        }
        else
        {
            cout << "value not found " << endl;
            return false;
        }
    }
    void delete_by_value()
    {
        if (!head)
        {
            cout << "\n List is empty.\n";
            return;
        }
        int val;
        cout << "enter the value of node you want to delete" << endl;
        cin >> val;

        Node *trNo = head;
        bool isFound = false, circular = is_circular();

        do
        {

            if (trNo->data == val)
            {
                isFound = true;
                break;
            }

            trNo = trNo->next;

        } while ((trNo != nullptr) && (circular ? trNo != head : true)); // If we have a circular structure, check if trNo is different from head
        // If it's not a circular structure, just return true unconditionally

        if (!isFound)
        {
            cout << "Value not present";
            return;
        }

        // Case 1: Single Node in List

        if (head == tail && head->data == val)
        {

            delete head;

            head = tail = nullptr;
            return;
        }

        // Case 2: Deleting Head Node:
        if (trNo == head)
        { // deletion if not circular
            head = head->next;
            head->prev = circular ? tail : nullptr;
            if (circular)
                tail->next = head;
        }

        // Case 3: Deleting Tail Node :
        else if (trNo == tail)
        {
            tail = tail->prev;
            tail->next = circular ? head : nullptr;
            if (circular)
                head->prev = tail;
        }

        // Case 4: Deleting Intermediate Node :
        else
        {

            trNo->prev->next = trNo->next;
            trNo->next->prev = trNo->prev;
        }
        delete trNo;
    }

    int countNodes()
    {

        if (!head)
            return 0;

        int count = 0;
        bool circular = is_circular();

        Node *trNo = head;

        do
        {

            count++;

            trNo = trNo->next;

        }

        while (circular ? (trNo != head) : (trNo != nullptr));

        return count;
    }
};

int main()
{
    doubly_list list;
    list.insertion_at_the_begining(3);
    list.insertion_at_the_begining(2);
    list.insertion_at_the_begining(1);
    list.display_list();
    if (list.search_value(2))
    {
        cout << "value found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}