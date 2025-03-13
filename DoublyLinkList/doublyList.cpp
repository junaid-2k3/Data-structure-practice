#include <iostream>
using namespace std;

struct Node{
    string task;
    Node* next;
    Node* prev;
    int flag;
    Node(string x="-"):task(x),next(nullptr),prev(nullptr),flag(0){}
};

class doublyList{
public:
Node* head;

doublyList():head(nullptr){
}

void insertionAtBegining(string data){
    Node* newNode=new Node(data);
    if(head==nullptr){
        head=newNode;
    }
    else{
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
}
void insertion_at_end(string data){
    Node* newNode=new Node(data);
    if(head==nullptr){
    head=newNode;
   return;
    }

   Node* tail=head;
    while(tail->next!=nullptr){
        tail=tail->next;
    }
    tail->next=newNode;
    newNode->prev=tail;
}

void insert_at_position(int position,string data){
    if(position<1){
        cout<<"position must be greater than 1 "<<endl;
        return;
    }
    if(position==1){
        insertionAtBegining(data);
        return;
    }
    Node* newNode=new Node(data);
    Node* curr=head;
    for(int i=1 ; curr !=nullptr && i<position -1 ; i++){
        curr=curr->next;
    }
    if(curr== nullptr){
        cout<<"position greater than number of nodes "<<endl;
        return;
    }
    newNode->next = curr->next;
    newNode->prev = curr;
    if (curr->next != nullptr) {
        curr->next->prev = newNode;
    }
    curr->next = newNode;

}
void deleteAtbegining(){
    if (head == nullptr) {
        cout << "The list is already empty." << endl;
        return;
    }
    Node* curr=head;
    head=head->next;
    if(head!=nullptr){
        head->prev=nullptr;
    }
    delete curr;
}
void deleteAtEnd(){
    if (head == nullptr) {
        cout << "The list is already empty." << endl;
        return;
    }

    Node* curr = head;
    // If there is only one node in the list.
    if (curr->next == nullptr) {
        head = nullptr;
        delete curr;
        return;
    }
    while (curr->next != nullptr) {
            curr = curr->next;
    }

    // Update the previous pointer of the second last node
    // and delete the last node.
    curr->prev->next = nullptr;
    delete curr;
}

void deleteAtPosition(int position)
{
    // Check if the doubly linked list is empty.
    if (head == nullptr) {
        cout << "The list is already empty." << endl;
        return;
    }
    if (position == 1) {
        deleteAtbegining();
        return;
    }
    Node* curr = head;
    // Traverse to the node at the specified position.
    for (int i = 1; curr != nullptr && i < position; i++) {
        curr = curr->next;
    }

    // Check if the position is greater than the number of
    // nodes.
    if (curr == nullptr) {
        cout << "Position is greater than the number of "
                "nodes."
             << endl;
        return;
    }
    curr->next->prev = curr->prev;
    curr->prev->next = curr->next;
    // if (curr->next != nullptr) {
        
    // }
    // if (curr->prev != nullptr) {
        
    // }
    delete curr;

}

void displayList(){
    Node* curr=head;
    while(curr!=nullptr){
        cout<<curr->task <<"  ";
        curr=curr->next;
    }
}
void printListReverse(){
    Node* tail=head;
    while(tail->next!=nullptr){
        tail=tail->next;
    }
    while(tail!=nullptr){
        cout<<tail->task;cout<< " ";
        tail=tail->prev;
    }
}
};
int main(){
   doublyList list;
   list.insertionAtBegining("junaid");
   list.insert_at_position(2,"sudais");
   list.insertion_at_end("usman");
   list.deleteAtPosition(2);

   list.displayList();
   cout<<endl;
   list.printListReverse();
  

}