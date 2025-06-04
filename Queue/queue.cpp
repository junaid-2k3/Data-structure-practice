// queue using linked list 
#include <iostream> // queue follows last in last out . LILO
using namespace std;// or First in first out

struct Node{ // node for queue element 
    Node* next;    // pointer to point to  the next node
    int data;
    
    Node(int val):data(val),next(nullptr){}
};

class queue{
    public:
    Node* front;  // node element 
    Node* rear;  // node element inserted at rear

    queue():front(nullptr),rear(nullptr){}
 
    void enqueue(int val){
        Node* newNode=new Node(val);
        if(!front && !rear){  // front == nullptr and rear== nullptr , which mean queue is empty 
            front=newNode;
            rear=newNode;
            cout<<val<<" enqueued"<<endl;
        }else{// queue is not empty then this condition 
            rear->next=newNode; 
            rear=newNode;
            cout<<val<<" enqueued"<<endl;
        }
    }

    void dequeue(){
        if(front==nullptr || rear==nullptr){ // if queue is empty , so nothing ,return 
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