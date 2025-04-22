#include <iostream> // queue follows last in last out . LILO
using namespace std;// or First in first out

struct Node{
    Node* next;
    int data;
    
    Node(int val):data(val),next(nullptr){}
};

class queue{
    public:
    Node* front;
    Node* rear;

    queue():front(nullptr),rear(nullptr){}
 
    void enqueue(int val){
        Node* newNode=new Node(val);
        if(!front && !rear){  // front == nullptr and rear== nullptr 
            front=newNode;
            rear=newNode;
            cout<<val<<" enqueued"<<endl;
        }else{
            rear->next=newNode;
            rear=newNode;
            cout<<val<<" enqueued"<<endl;
        }
    }

    void dequeue(){
        if(front==nullptr || rear==nullptr){
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
        return rear->data;

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