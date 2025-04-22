#include <iostream>
#include <vector>
using namespace std;

class queue{
    int front;
    int rear;
    int size;
    int *arr;

    public:
    queue(int val):front(-1),rear(-1),size(val){
        arr=new int[val];
    }
    
    bool is_empty(){
        if(front==-1 && rear==-1){
            return true;
        }else 
            return false;

    }
    bool is_full(){
        if((rear+1)%size==front){
            return 1;
        }else  
            return false;
    }

    int getFront() {
        int f = arr[front];
        // cout<<"front: "<<f<<endl;
        return f;
        }

        int getRear() {
        int r = arr[rear];
        // cout<<"rear: "<<r<<endl;
        return r;
        }
        
    void enqueue(int val){
        if(is_full()){
            cout<<"the queue is full"<<endl;
            return ;
        }
        else if(is_empty()){
            front=0;
            rear=0;
        }else{
            rear=(++rear)%size;
        }
        arr[rear]=val;
        // cout<<val<<"enqueued"<<endl;
        }
    
    void dequeue(){
        if(!is_empty()){
            int val=arr[front];
            if(front=rear){
                front=-1;
                rear=-1;
            }else{
                front=(front+1)%size;
            }
            // cout<<"Dequeued :"<<val<<endl;
        }else{
            cout<<"queue is empty"<<endl;
        }
    }
    
    void display(){
        if(is_empty()){
            cout<<"queue is empty "<<endl;
            return ;
        }
        cout<<"queue elements "<<endl;
        //alternative way of writing the same thing 
        // for (int i = front; i != (rear + 1) % size; i = (i + 1) % size) {
        // cout << arr[i] << " ";
    // }
        int i=front;
        while(true){
            cout<<arr[i]<<"";
            if(i==rear)break;
            i=(i+1)%size;
        }
        cout<<endl;
    }
//15.Write a function that rotates a queue by k positions (e.g., front elements move to
// the rear).

    void rotateQueue(int k){
        if(k<=0){
            return;
        }else{
            k=k%size;
            int temp;
            for(int i=0 ; i<k ;i++){
                temp=getFront();
                dequeue();
                enqueue(temp);
            }
        }
    }
};
int main(){
    queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout<<" queue display"<<endl;
    q.display();
    cout<<"now with rotaion "<<endl;
    q.rotateQueue(2);
    q.display();

}
