
#include <iostream>
#include <conio.h>
#include <limits>
using namespace std;
const short int EXIT = 0, INSERT_KEY = 1, DELETE_KEY=2, INCREASE_KEY=3,DECREASE_KEY=4, FIND_VALUE = 5,
MAX_VALUE = 6, DISPLAY_HEAP = 7, EXTRACT_MAX=8,HEAP_SORT=9, INCREASE_CAPACITY=10;
class maxHeap{
private:
    int *HeapArray, maxHeapSize, maxHeapCapacity, value;
    int parent(int i) { return (i-1)/2;}
    int getLeftChild(int i) { return 2*i+1; }
    int getRightChild(int i) { return 2*i+2; }

    void swapValues(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }
    void heapifyUp(int index){
        while ( index!=0 && HeapArray[index] > HeapArray[parent(index)]){
            swapValues(HeapArray[index], HeapArray[parent(index)]);
            index = parent(index);// to end the loop after swaping ,,
        }
    }
    void heapifyDown(int index){
        int leftChild = getLeftChild(index);
        int rightChild = getRightChild(index);
        int largest = index;
        if ( leftChild < maxHeapSize && HeapArray[largest] < HeapArray[leftChild] )
            largest = leftChild;
        if ( rightChild < maxHeapSize && HeapArray[largest] < HeapArray[rightChild] )
            largest = rightChild;
        if ( index != largest ){ // if tue means largest has any value from the childrens
            swapValues(HeapArray[index],HeapArray[largest]);
            heapifyDown(largest);
        }
    }
    bool heapIsFull(){
        if (maxHeapSize == maxHeapCapacity) cout<<"\n\t Heap Overflow ";
        return (maxHeapSize == maxHeapCapacity);
    }
    bool heapIsEmpty(){
        if (!maxHeapSize) cout<<"\n\t Heap Underflow ";
        return !maxHeapSize;
    }
    bool insertKey(int key){
        HeapArray[maxHeapSize++] = key;
        heapifyUp(maxHeapSize-1);
        return true;
    }
    void increaseKey(int index,int key){
        HeapArray[index] = key;
        heapifyUp(index);//When you increase the value at a given index:
        //It might now be larger than one of its parent.
        //This violates the max-heap property because the parent must be greater than or equal to both children.
        //So we need to push this node up the heap until it finds the correct position.
    }
    void decreaseKey(int index,int key){   
        HeapArray[index] = key;
        heapifyDown(index);//When you decrease the value at a given index:
                            //It might now be smaller than one of its children.
                            //This violates the max-heap property because the parent must be greater than or equal to both children.
                            //So we need to push this node down the heap until it finds the correct position.
    }
    int extractMax(int i){
        if (maxHeapSize == 1) return HeapArray[--maxHeapSize];// if there is only one element in the heap array,decrease it size and return the element 

        int root = HeapArray[0]; // extract the value of the root 
        HeapArray[0] = HeapArray[--maxHeapSize]; // store the last value at root , and decrease the heap size because we have extracted one element from the heap that is root 
        heapifyDown(0); // heapify down to maintain heap property
        return root;
    }
    void buildMaxHeap(){
        for (int i=maxHeapSize/2-1; i>=0; i--)  // start from the last parent node and go all the way up to the root 
            heapifyDown(i);
    }

    int findValue(int key){
        if (heapIsEmpty()) return -1;
        for (int i=0; i<maxHeapSize; i++)
            if (HeapArray[i] == key) return i; // value found
        return -1; // value not found.
    }
    void increaseCapacity(int cap){
        int *newMaxHeapArray = new int[cap];
        for (int i=0; i<maxHeapSize;i++)
            newMaxHeapArray[i] = HeapArray[i];
        delete[] HeapArray;
        HeapArray = newMaxHeapArray; // HeapArray is a pointer that was pointing to the previous array now pointing to the new array
        maxHeapCapacity = cap;
    }
public:
    int choice;
    maxHeap(int cap):maxHeapCapacity(cap),maxHeapSize(0){
        HeapArray = new int[maxHeapCapacity];
    }
    void insertKey(){
        if (heapIsFull()) return;
        cout<<"\n enter value for insertion in heap "; cin>>value;
        if (insertKey(value))
            cout<<"\n value inserted successfully ";
    }
    void increaseKey(){
        cout<<"\n enter value you want to increase = "; cin>>value;
        int index = findValue(value);
        if (index != -1){
            int increasedValue = 0;
            cout<<"\n enter increased value for insertion = ";
            cin>>increasedValue;
            if (increasedValue < value ){
                cout<<"\n value is smaller, use decrease key option ";
                return;
            }
            else if (increasedValue > value)
                        increaseKey(index,increasedValue);
                 else
                    cout<<" \n value is equal, no change in heap required";
        }
        else
            cout<<"\n value not found ";
    }
    void extractMax(){
        if (heapIsEmpty()) return;
        cout<<"\n maximum value deleted in heap = "<<extractMax(0);
    }
    void getMax(){
        if (heapIsEmpty()) return;
        cout<<"\n displaying largest value in heap = "<<HeapArray[0];
    }
    void deleteKey(){
        if (heapIsEmpty()) return;
        cout<<"\n enter value for deletion in heap "; cin>>value;
        int index = findValue(value);// find value function calculates the index of the value in the array 
        if ( index != -1 ){
            increaseKey(index,INT_MAX);  // INT_MAX => highest integer 
            extractMax(0);
            cout<<"\n value deleted successfully ";
        }
        else
            cout<<"\n value not present in heap";
    }
    void decreaseKey( ){
        if (heapIsEmpty()) return;
        cout<<"\n enter value you want to decrease = "; cin>>value;
        int index = findValue(value);
        if (index != -1){
            int decreasedValue = 0;
            cout<<"\n enter decreased value for insertion = ";
            cin>>decreasedValue;
            if (decreasedValue > value ){
                cout<<"\n value is greater, use increase key option ";
                return;
            }
            else if (decreasedValue < value)
                        decreaseKey(index,decreasedValue);
                 else
                    cout<<" \n value is equal, no change in heap required";
        }
        else
            cout<<"\n value not found ";
    }
    void displayHeap(){
        if (heapIsEmpty()) return;
        cout<<" \ndisplaying heap values: ";
        for (int i=0; i<maxHeapSize; i++)
            cout<<HeapArray[i]<<", ";
    }
    void findValue(){
        cout<<"\n enter value to search = "; cin>>value;
        int index = findValue(value);
        if ( index != -1)
            cout<<"\n value found at index: "<<index;
        else
            cout<<"\n value not found ";
    }
    void heapSort(){
        buildMaxHeap(); // it does heapify down on all the parent nodes 
        // once we make a valid heap out of the non sorted array ,now we will store that in an array
        int *temp = new int[maxHeapCapacity];
        for (int i=0; i<maxHeapSize; i++)
            temp[i] = HeapArray[i];
        int originalSize = maxHeapSize;
        for (int i= originalSize - 1; i >=0; i--)
            HeapArray[i] = extractMax(0);
        cout<<"\n sorted values = ";
        for (int i=0; i < originalSize; i++)
            cout<<HeapArray[i]<<", ";
        maxHeapSize = originalSize;

        for (int i=0; i<maxHeapSize; i++)
            HeapArray[i] = temp[i];

        buildMaxHeap();
        delete[] temp;
    }
    void increaseCapacity(){
        int cap = maxHeapCapacity;
        cout<<"\n enter new capacity for the heap = "; cin>>cap;
        if (cap<=maxHeapCapacity){
            cout<<"\n new capacity must be greater then the current capacity ";
            return;
        }
        increaseCapacity(cap);
        cout<<" \n capacity increased successfully ";
    }
    void displayMenu(){
    cout<<"\n *************** MAX HEAP ***************\n\t"
    <<EXIT<<" for exiting program\n\t"
    <<INSERT_KEY<<" for insertion\n\t"
    <<DELETE_KEY<<" for deletion\n\t"
    <<INCREASE_KEY<<" for increasing an existing value\n\t"
    <<DECREASE_KEY<<" for decreasing an existing value \n\t"
    <<FIND_VALUE<<" for searching value\n\t"
    <<MAX_VALUE<<" for displaying maximum value \n\t"
    <<DISPLAY_HEAP<<" for displaying heap \n\t"
    <<EXTRACT_MAX<<" for deleting maximum value \n\t"
    <<HEAP_SORT<<" for performing heap sort on the values \n\t"
    <<INCREASE_CAPACITY<<"for increasing the capacity of the HEAP \n\t"
    <<" Please Enter Choice = ";
    cin>>choice;
    }
    void clearMenu(){
        if (choice){
            cout<<"\n\t press any key to continue ";
            _getch();                                     // ?
            system("CLS");
        }
    }
};

int main()
{
    int capacity=5; cout<<"\n enter capacity of the HEAP = "; cin>>capacity;
    maxHeap tree(capacity);
    do{
        tree.displayMenu();
        switch(tree.choice){
            case INSERT_KEY: tree.insertKey();
                break;
            case DELETE_KEY: tree.deleteKey();
                break;
            case INCREASE_KEY: tree.increaseKey();
                break;
            case DECREASE_KEY: tree.decreaseKey();
                break;
            case FIND_VALUE: tree.findValue();
                break;
            case MAX_VALUE: tree.getMax();
                break;
            case DISPLAY_HEAP: tree.displayHeap();
                break;
            case EXTRACT_MAX: tree.extractMax();
                break;
            case HEAP_SORT: tree.heapSort();
                break;
            case INCREASE_CAPACITY: tree.increaseCapacity();
                break;
            case EXIT: break;
            default: cout<<"\n please enter valid choice ";
        }
        tree.clearMenu();
    }while(tree.choice);
    cout << "\n" << endl;
    return 0;
}
