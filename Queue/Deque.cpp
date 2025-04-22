//Deque are double ended queues allowing for insertion and deletion from both ends 
//Deque can be implemented using doubly linked list 

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int val=0):data(val),next(nullptr),prev(nullptr){}
};

class Deque{
    public:
    Node* front;
    Node* rear;
    Deque():front(nullptr),rear(nullptr){}
    ~Deque(){
        while(!is_empty())
        dequeueFront();
    }
    bool is_empty(){
        return (front==nullptr && rear==nullptr);
    }
    bool is_full(){

    }
    void enqueueFront(int val){
        Node* newNode= new Node(val);
        newNode->next=front;
        if(is_empty()){
            front=rear=newNode;
        }else{
            front->prev=newNode;
            front=newNode;
        }
        cout<<"enqueed at front "<<endl;
    }
    void enqueueRear(int val){
        Node* newNode= new Node(val);
        newNode->prev=rear;
        if(is_empty()){
            front=rear=newNode;
        }else{
            rear->next=newNode;
            rear=newNode;
        }
        cout<<"enqueued at rear"<<endl;
    }
    void dequeueFront(){
        if(is_empty()){
            return;
        }
            Node* temp=front;
            if(front==rear){
                front=rear=nullptr;
            }else{
                front=front->next;
                front->prev=nullptr;
            }
            delete temp;
        
    }
    void dequeueRear(){
        if(is_empty()){
            return;
        }
            Node* temp=rear;
            if(front==rear){
                front=rear=nullptr;
            }else{
                rear=rear->prev;
                rear->next=nullptr;
            }
            delete temp;
        
    }

    void display(){
        if(is_empty())
        return ;
        Node* curr=front;
        cout<<"displaying queue "<<endl;
        while(curr!=nullptr){
            cout<<curr->data<<"";
            curr=curr->next;
        }
    }
    
};
int main(){
    Deque queue;
    queue.enqueueFront(1);
    queue.enqueueFront(2);
    queue.enqueueFront(3);
    queue.enqueueRear(4);
    queue.enqueueRear(5);
    queue.enqueueRear(6);
    queue.display();
    queue.dequeueFront();
    queue.dequeueFront();
    queue.display();
}