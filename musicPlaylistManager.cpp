// C++ Program for Implementation of linked list
#include <iostream>
using namespace std;

// Structure for a node in the linked list
struct Node {
    string data;  
    Node* next; 
};

// Define the linked list class
class LinkedList {
     // Pointer to the first node in the list
    Node* head;

public:
    // Constructor initializes head to NULL
    LinkedList() : head(NULL) {}

    // Function to Insert a new node at the beginning of the list
    void insertAtBeginning(string value) {
        Node* newNode = new Node(); 
        newNode->data = value;      
        newNode->next = head;      
        head = newNode;            
    }

    // Function Insert a new node at the end of the list
    void insertAtEnd(string value) {
        Node* newNode = new Node(); 
        newNode->data = value;      
        newNode->next = NULL;       

        // If the list is empty, update the head to the new node
        if (!head) {
            head = newNode;
            return;
        }

        // Traverse to the last node
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }

        // Update the last node's next to the new node
        temp->next = newNode;
    }

    // Function to Insert a new node at a specific position in the list
    void insertAtPosition(string value, int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }

        if (position == 1) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node(); 
        newNode->data = value;     

        // Traverse to the node before the desired position
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        // If the position is out of range, print an error message
        if (!temp) {
            cout << "Position out of range." << endl;
            delete newNode;
            return;
        }

        // Insert the new node at the desired position
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to Delete the first node of the list
    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head; 
        head = head->next; 
        delete temp;      
    }
    void searchForSong(string val){
        int flag=false;
        Node* curr=head;
        while(curr->next!=NULL){
            if(curr->data==val){
                flag=true;
                cout<<"song found \n name :"<< curr->data<<endl;
            }
            curr=curr->next;
        }
        if(flag==false){
            cout<<"song not found"<<endl;
        }

    }

    // Function to Delete the last node of the list
    // void deleteFromEnd() {
    //     if (!head) {
    //         cout << "List is empty." << endl;
    //         return;
    //     }

    //     if (!head->next) {
    //         delete head;   
    //         head = NULL;   
    //         return;
    //     }

    //     // Traverse to the second-to-last node
    //     Node* temp = head;
    //     while (temp->next->next) {
    //         temp = temp->next;
    //     }
        
    //     //  Delete the last node
    //     delete temp->next; 
    //     // Set the second-to-last node's next to NULL
    //     temp->next = NULL; 
    // }

    // Function to Delete a node at a specific position in the list
    void deleteFromPosition(int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }

        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            cout << "Position out of range." << endl;
            return;
        }
        // Save the node to be deleted
        Node* nodeToDelete = temp->next; 
        // Update the next pointer
        temp->next = temp->next->next;   
         // Delete the node
        delete nodeToDelete;            
    }

    // Function to print the nodes of  the linked list
    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> "; 
            temp = temp->next;
        }
        cout << "NULL" << endl; 
    }
};

int main() {
    LinkedList list;
    while (true) {
        cout << "welcome to the music playlist :" << endl;
        cout << "options " << endl;
        int input;
        cout << "add a song --1 \n delete a song ---2 \n search a song ---3 \n update song name ---4 \n print playlist ---5 \n play song \n exit ---6" << endl;
        cin >> input;

        switch (input) {
            case 1: {
                string song;
                cout << "enter the song name :" << endl;
                cin.ignore();
                getline(cin, song);
                cout << "how much favourit it is " << endl;
                int choice;
                cout << "1--most favourit \n 2--least favourit \n 3--specify your favourit level \n ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        list.insertAtBeginning(song);
                        break;
                    case 2:
                        list.insertAtEnd(song);
                        break;
                    case 3: {
                        int choice;
                        cout << "choose between 2-5" << endl;
                        cin >> choice;
                        list.insertAtPosition(song, choice);
                        break;
                    }
                    default:
                        cout << "Invalid choice! Try again." << endl;
                }
                break;
            }

            case 2: {
                int position;
                cout << "enter the position from which you want to delete the song :" << endl;
                cin >> position;
                list.deleteFromPosition(position);
                break;
            }

            case 3: {
                string search;
                cout << "enter name of the song you want to search :" << endl;
                cin >> search;
                list.searchForSong(search);
                break;
            }

            case 4:
                // update a song 
                break;

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


// int main() {
//     LinkedList list;
//     while(true){
//  cout<<"welcome to the music playlist :"<<endl;
//  cout<<"options "<<endl;
//  int input;
//  cout<<"add a song --1 \n delete a song ---2 \n search a song ---3 \n update song name ---4 \n print playlist ---5 \n play song \n exit ---6"<<endl;
//  cin>>input;
//  if(input==1){
//     string song;
//     cout<<"enter the song name :"<<endl;
//     cin.ignore();
//     getline(cin,song);
//     cout<<"how much favourit it is "<<endl; int choice;
//     cout<<"1--most favourit \n 2--least favourit \n 3--specify your favourit level \n ";
//     cin>>choice;
//     if(choice==1){
//         list.insertAtBeginning(song);
//     }
//     else if(choice==2){
//         list.insertAtEnd(song);
//     }
//     else if(choice==3){
//         int choice;
//         cout<<"choose between 2-5"<<endl;
//         cin>>choice;
//         list.insertAtPosition(song,choice);
//     }
//  }
//  else if(input==2){
//     int position;
//     cout<<"enter the position form which you want to delete the song :"<<endl;
//     cin>>position;
//      list.deleteFromPosition(position);
//  }
//  else if(input==3){
//     string search;
//     cout<<"enter name of the song you want to search :"<<endl;
//     cin>>search;
//    list.searchForSong(search); 
//  }
// else if( input==4){
// // update a song 
// }

// else if( input==5){
//     list.display();
// }
// else if(input==6){
//     return 0;
// }
    
// }
// }