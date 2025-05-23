#include <iostream>
#include <list>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
class LinkedList {
    // Pointer to the first node in the list
   Node* head;

public:
   // Constructor initializes head to NULL
   LinkedList() : head(NULL) {}

   Node* return_head(){
    return head;
   }
   // Function to Insert a new node at the beginning of the list
   void insertAtBeginning(int value) {
       Node* newNode = new Node(value); 
       newNode->data = value;      
       newNode->next = head;      
       head = newNode;            
   }

   // Function Insert a new node at the end of the list
   void insertAtEnd(int value) {
       Node* newNode = new Node(value); 
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
   void insertAtPosition(int value, int position) {
       if (position < 1) {
           cout << "Position should be >= 1." << endl;
           return;
       }

       if (position == 1) {
           insertAtBeginning(value);
           return;
       }

       Node* newNode = new Node(value); 
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

   // Function to Delete the last node of the list
   void deleteFromEnd() {
       if (!head) {
           cout << "List is empty." << endl;
           return;
       }

       if (!head->next) {
           delete head;   
           head = NULL;   
           return;
       }

       // Traverse to the second-to-last node
       Node* temp = head;
       while (temp->next->next) {
           temp = temp->next;
       }
       
       //  Delete the last node
       delete temp->next; 
       // Set the second-to-last node's next to NULL
       temp->next = NULL; 
   }

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

   void loop_creation(int pos){
        Node* temp=head;
        Node* loopNode=nullptr;
        int count=1;
        while(temp->next!=nullptr){
            if(count==pos){
                loopNode=temp;
            }
            temp=temp->next;
            count++;
        }
        temp->next=loopNode;
   }

   bool loop_detection(){
    Node* fast=head;
    Node* slow=head;
     while(fast!=nullptr && fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
     }
     return false;
}
   
};



int main(){
   LinkedList li;
   li.insertAtBeginning(2);
   li.insertAtBeginning(4);
   li.insertAtBeginning(6);
   li.insertAtBeginning(6);
   li.insertAtBeginning(8);
   li.insertAtBeginning(10);
   li.insertAtBeginning(12);cout<<endl;
   cout<<" >>> " <<li.loop_detection()<<" <<<";cout<<endl;
   li.loop_creation(2);
   cout<<" >>> " <<li.loop_detection()<<" <<<";

}