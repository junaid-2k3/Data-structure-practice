#include <string>
#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node *next;
};

class LinkedList
{
    Node *head;

public:
    LinkedList() : head(NULL) {}

    void insertAtBeginning(string value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(string value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (!head)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void insertAtPosition(string value, int position)
    {
        if (position < 1)
        {
            cout << "Position should be >= 1." << endl;
            return;
        }

        if (position == 1)
        {
            insertAtBeginning(value);
            return;
        }

        Node *newNode = new Node();
        newNode->data = value;

        Node *temp = head;
        for (int i = 1; i < position - 1 && temp; ++i)
        {
            temp = temp->next;
        }

        if (!temp)
        {
            cout << "Position out of range." << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFromBeginning()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void searchForSong(string val)
    {
        bool found = false;
        Node *curr = head;
        while (curr)
        {
            if (curr->data == val)
            {
                found = true;
                cout << "Song found\nName: " << curr->data << endl;
            }
            curr = curr->next;
        }
        if (!found)
        {
            cout << "Song not found" << endl;
        }
    }

    void deleteFromPosition(int position)
    {
        if (position < 1)
        {
            cout << "Position should be >= 1." << endl;
            return;
        }

        if (position == 1)
        {
            deleteFromBeginning();
            return;
        }

        Node *temp = head;
        for (int i = 1; i < position - 1 && temp; ++i)
        {
            temp = temp->next;
        }

        if (!temp || !temp->next)
        {
            cout << "Position out of range." << endl;
            return;
        }

        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    void updateSong(string oldName, string newName)
    {
        Node *curr = head;
        bool found = false;

        while (curr)
        {
            if (curr->data == oldName)
            {
                curr->data = newName;
                found = true;
                cout << "Song updated successfully." << endl;
                return;
            }
            curr = curr->next;
        }

        if (!found)
        {
            cout << "Song not found, update failed." << endl;
        }
    }

    void display()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = head;
        while (temp)
        {
            cout << temp->data <<"  ";
            temp = temp->next;
        }
        
    }
};

int main()
{
    LinkedList list;
    while (true)
    {
        cout << "\nWelcome to the Music Playlist:" << endl;
        cout << "Options:" << endl;
        cout << "1. Add a song\n2. Delete a song\n3. Search a song\n4. Update song name\n5. Print playlist\n6. Exit" << endl;
        int input;
        cin >> input;
        cin.ignore();

        switch (input)
        {
        case 1:
        {
            string song;
            cout << "Enter the song name: ";
            getline(cin, song);
            cout << "How much favorite is it?\n1--Most favorite\n2--Least favorite\n3--Specify your favorite level" << endl;
            int choice;
            cin >> choice;

            switch (choice)
            {
            case 1:
                list.insertAtBeginning(song);
                break;
            case 2:
                list.insertAtEnd(song);
                break;
            case 3:
            {
                int pos;
                cout << "Choose position between 2-5: ";
                cin >> pos;
                list.insertAtPosition(song, pos);
                break;
            }
            default:
                cout << "Invalid choice! Try again." << endl;
            }
            break;
        }

        case 2:
        {
            int position;
            cout << "Enter the position from which you want to delete the song: ";
            cin >> position;
            list.deleteFromPosition(position);
            break;
        }

        case 3:
        {
            string search;
            cout << "Enter the name of the song you want to search: ";
            getline(cin, search);
            list.searchForSong(search);
            break;
        }

        case 4:
        {
            string oldName, newName;
            cout << "Enter the name of the song you want to update: ";
            getline(cin, oldName);
            cout << "Enter the new song name: ";
            getline(cin, newName);
            list.updateSong(oldName, newName);
            break;
        }

        case 5:
            list.display();
            break;

        case 6:
            return 0;

        default:
            cout << "Invalid option! Please try again." << endl;
        }
    }
}
