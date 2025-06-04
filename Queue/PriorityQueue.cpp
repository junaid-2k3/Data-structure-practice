#include <iostream>
using namespace std;

struct Node{
    int data;
    int priority;
    Node* next;
    Node(int v,int p):data(v),priority(p),next(nullptr){}
};

class PrioQueue {
    public:
    Node* front;
    Node* rear;
    PrioQueue():front(nullptr),rear(nullptr){}
    ~PrioQueue(){
        while(front)
        dequeue();
    }
    bool isEmpty(){
        return front? false:true;   // if front is not null it will return true 
    }
    void enqueue(int value,int priority ){
        Node* newNode=new Node(value ,priority);
        if(front==nullptr || priority<front->priority){
            newNode->next=front;
            front=newNode;
        }else{
            Node* trNode=front;
            while(trNode->next!=nullptr && priority>=trNode->priority){
               trNode=trNode->next;
            }
            newNode->next=trNode->next;
            trNode->next=newNode;
        }
        cout<<"enqueued"<<endl;
    }
  // dequeue funciton will always pop the minimum element because the elements are 
  //inserted on the base of priority 
    // void enqueue(int value,int priority){
    //     Node* newNode=new Node(value,priority);
    //     if(front==nullptr || priority <front->priority){
    //         newNode->next=front;
    //         front=newNode;
    //     }else {
    //         Node* curr=front;
    //         while(curr->next!=nullptr && curr->next->priority<=priority){
    //            curr=curr->next;
    //         }
    //         newNode->next=curr->next;
    //         curr->next=newNode;
    //         cout<<"inserted value "<<newNode->data <<"at priority :"<<newNode->priority<<endl;
    //     }
    // }
    

    void dequeue(){
        if(front==nullptr){
            cout<<"priority queue is empty";
            return;
        }
        Node* curr=front;
        cout<<"removed "<<curr->data<<"with a priority of :"<<curr->priority<<endl;
        front=front->next;
        delete curr;
    }
    void display(){
        if(front==nullptr){
            return;
        }else{
            Node* curr=front;
            while(curr){
                cout<<"node :"<<curr->data<<","<<curr->priority<<endl;
                curr=curr->next;
            }
        }
    }

};
int main(){
    PrioQueue queue;
    queue.enqueue(10,1);
    queue.enqueue(1,0);
    queue.enqueue(30,2);
    queue.enqueue(50,5);
    queue.enqueue(600,4);
    queue.enqueue(20,3);
    queue.display();
}