#include <iostream>
using namespace std;
    void binarySearch(int arr[],int n,int val){
        int start=0;
        int end=n-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(val>arr[mid]){
                start=mid+1;
            }else if(val<arr[mid]){
                end=mid-1;
            }else{
                cout<< "value found "<<mid<<endl;
                return ;
            }
        }
        cout<<"value not found"<<endl;
    }
int main(){
    int n=12;
    int arr[]={1,2,3,4,5,6,7,8,9,12,29,50};
    binarySearch(arr,n,12);
}