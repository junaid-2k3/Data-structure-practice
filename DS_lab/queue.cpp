#include <iostream>
using namespace std;

struct Node{
    Node* next;
    int data;
    
    Node(int val):data(val),next(nullptr){}

    
};

class queue{
    public:
    Node* front;
    Node* back;

    queue():front(nullptr),back(nullptr){}
 
    void enqueue(int val){
        Node* newNode=new Node(val);
        if(!front && !back){
            front=newNode;
            back=newNode;
            cout<<val<<" enqueued"<<endl;
        }else{
            back->next=newNode;
            back=newNode;
            cout<<val<<" enqueued"<<endl;
        }
    }

    void dequeue(){
        if(front==nullptr || back==nullptr){
            cout<<"the queue is empty "<<endl;
            return;
        }
        Node* temp=front;
        front=front->next;
        cout<<temp->data<<" dequeued"<<endl;
        delete temp;
    }
    int getfront(){
        return front->data;
    }
    int getback(){
        return back->data;

    }
    void display_queue(){
        Node* tn=front;
        while(tn){
            cout<<tn->data<<"  ";
            tn=tn->next;
        }
    }
};

int main(){
    queue q1;
    q1.enqueue(2);
    q1.enqueue(4);
    q1.enqueue(6);
    // q1.dequeue();
    // q1.dequeue();
    // q1.dequeue();
    // q1.dequeue();
    
    q1.display_queue();
    
}