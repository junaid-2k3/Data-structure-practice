#include <iostream>
#include <algorithm>
using namespace std;

void selectionsort(int arr[],int n){    //time O(n^2)
    for(int i=0 ; i<n-1 ;i++){
        int smallestIndex=i; // unsorted part starting ,we assume i
        for (int j=i+1 ; j<n ; j++){
            if(arr[j]<arr[smallestIndex]){
                smallestIndex=j;
            }
        }
        swap(arr[i],arr[smallestIndex]);
    }
}
int main(){
    int n=5;
    int arr[]={2,3,1,6,4};
    selectionsort(arr,n);
    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
}