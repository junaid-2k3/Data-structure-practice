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
    string Kth_element(int k){ // using two pointer or fast and slow pointer 
        Node* ptr1,*ptr2;
        ptr1=head;
        ptr2=head;
        for(int i=1 ;i<=k ; i++){
            ptr2=ptr2->next;
        }
        while(ptr2){
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return ptr1->task;
    }
};
int main(){
    doublyList list1;
    list1.insertionAtBegining("junadi");
    list1.insertionAtBegining("hamza");
    list1.insertionAtBegining("ramzan ");
    list1.insertionAtBegining("saad");
    cout<<list1.Kth_element(4);
}