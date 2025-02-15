#include <iostream>


using namespace std;

int reverseArray(int array[], int size );   // prototype
  
int main(){
  
    int size=10;
    int array[size]={1,2,3,4,5,6,7,8,9,10};
    for (int i=0; i<size ;i++){
        cout<< array[i]<<"  " ;
    }
    
    reverseArray(array,size);
    cout<< endl<<"after reversing "<<endl;
    for (int i=0; i<size ;i++){
        cout<< array[i]<<"  " ;
    }
}
int reverseArray(int array[], int size ){
    int start=0;
    int end=size-1;
    while(start<end){
        swap(array[start],array[end]);
        start++;
        end--;
    }
}
