#include <iostream>
#include <vector>;
using namespace std;
 // implementing a Max heap 
class Heap{
    private:
    int* heap;
    int capacity;
    int size;

    //private methods 
    int get_parent(int i){
        return i/2-1;
    }
    int get_leftchild(int i){
        return i*2+1;
    }
    int get_rightchild(int i){
        return i*2+2;
    }
    int swap(int& a ,int& b){
        int temp=a;
        a=b;
        b=temp;
    }
    void heapify_up(int nodeindex){  // used in insert function , this is the recursive approach this can also be done using a while loop 
        int parentIndex=get_parent(nodeindex);
        if(nodeindex>=0 && parentIndex>=0 && heap[parentIndex]<heap[nodeindex]){
            swap(heap[parentIndex],heap[nodeindex]);
            heapify_up(nodeindex);
    }
}
    void heapify_down(int nodeindex ){
        int largest=nodeindex;// because we know that in a max heap root is the larget 
        int leftchild=get_leftchild(nodeindex);
        int rightchild=get_rightchild(nodeindex);
        if(leftchild<size && largest<heap[leftchild]){
            largest=leftchild;
        }
        if(rightchild<size && largest<heap[rightchild]){
            largest=rightchild;
        }
        if(heap[nodeindex]!=heap[largest]){
                swap(heap[nodeindex],heap[largest]);
                heapify_down(largest);
            }
        }
        bool heapIsFull(){
            if (size == capacity) cout<<"\n\t Heap Overflow ";
            return (size == capacity);
        }
        bool heapIsEmpty(){
            if (!size) cout<<"\n\t Heap Underflow ";
            return !size;
        }
    
public:
    Heap(int cap, int s):capacity(cap),size(s){
        heap=new int[s];
    }
    void insert(int value){
        if(heapIsFull){
            cout<<"heap is full " <<endl; return;
        }
        heap[size]=value;
        heapify_up(size);
        size++;
    }
    

};