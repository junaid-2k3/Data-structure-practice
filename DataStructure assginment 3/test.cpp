#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void splitList(Node* head,Node* first, Node* second){
    Node* slow=head;
    Node* fast=head->next;

    while(slow && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    first=head;
    second=slow->next;
    slow->next=nullptr;  // to prevent collision between the first and the second list 
}

void sortedInsert(Node* head,int value){  // sorted list , minimum value will be at first node
    Node* newNode=new Node(value);
    if(head==nullptr || value<=head->data){
        newNode->next=head;
        head=newNode;
    }else{
        Node* trNode=head;
        while(!trNode || value>=trNode->data){
            trNode=trNode->next;
        }
        newNode->next=trNode->next;
        trNode->next=newNode;
    }
}
int main(){
    return 0;
    Node* first;
    Node* second;

}