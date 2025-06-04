// queue can be implemented using both array and linked list 
// creating queue(circular) using array 
#include <iostream>
#include <vector>
using namespace std;

class queue{
    int front;   //used as pointer , though not actual pointers but to point to index 
    int rear;
    int capacity ;   // capacity  of queue ==> number of elements in queue 
    int *arr; //pointer to the queue array 
    int size;  

    public:
    queue(int val):front(-1),rear(-1),capacity (val),size(0){
        arr=new int[val=6];
    }
    int getsize (){
        return size ;
    }
    bool is_empty(){
        if(front==-1 && rear==-1){   // condition for the array to know if its empty or not 
            return true;
        }else 
            return false;

    }
    bool is_full(){
        if((rear+1)%capacity ==front){ // since queue is circular so 
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
        else if(is_empty()){ // agr queue empty hai to front or rear ko zeroth index pe point karo 
            front=0;
            rear=0;
        }else{
            rear=(++rear)%capacity ; // nhi to rear ko aik index aage leke jao
        }
        arr[rear]=val; // or usmai nai aane wali value daal do 
        // cout<<val<<"enqueued"<<endl;
        size++;
        }
    
    void dequeue(){
        if(!is_empty()){  // agar empty no ho 
            int val=arr[front];
            if(front==rear){// it means the queue has only one element 
                front=-1;
                rear=-1;
                size--;
            }else{
                front=(front+1)%capacity ;
                size--;
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
        // for (int i = front; i != (rear + 1) % capacity ; i = (i + 1) % capacity ) {
        // cout << arr[i] << " ";
    // }
        int i=front;
        while(true){
            cout<<arr[i]<<"";
            if(i==rear)break;
            i=(i+1)%capacity ;
        }
        cout<<endl;
    }
//15.Write a function that rotates a queue by k positions (e.g., front elements move to
// the rear).

    void rotateQueue(int k){
        if(k<=0){
            return;
        }else{
            k=k%capacity ;   // to bring the rotation into limits
            int temp;
            for(int i=0 ; i<k ;i++){
                temp=getFront();// front se nikal ke rear pe wapis insert kro k times 
                dequeue();
                enqueue(temp);
            }
        }
    }
    // void swapEven(queue q){
    //     int f=q.getFront();
    //     int r=q.getRear();
    //     while()
    // }
    // interleave the first and second half of the queue 
   
};  
// explanation of this funcition 
// inteleaving first half with second half mean taking one value from the first half and one value form the second one , and writing them in a sequence for example 1234 would be 1324 when interleaved 
vector<int> interleave(queue& q){
    int n=q.getsize();
    queue qtemp(6);
    vector<int>ans;
    for(int i=0 ; i<n/2 ; i++){
        qtemp.enqueue(q.getFront());
        q.dequeue();
    }
    for(int i=0 ; i<n/2 ; i++){
        ans.push_back(qtemp.getFront());
        ans.push_back(q.getFront());
        q.dequeue();
        qtemp.dequeue();
    }
    return ans;
}
int main(){
    queue q(10);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.display();
    cout<<endl;
    vector<int> tem=interleave(q);
    for(int c : tem){
        cout<<c<<" ";
    }
    // cout<<" queue display"<<endl;
    // cout<<" size of q : "<<q.getsize();
    // q.display();
    // cout<<"now with rotaion "<<endl;
    // q.rotateQueue(2);
    // q.display();
    

}
