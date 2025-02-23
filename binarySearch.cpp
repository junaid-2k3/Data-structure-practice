#include <iostream>
#include <vector>
using namespace std;
 // binary search algorithm iterative code 
int binary_search_iterative(vector<int> n ,int tar){
    int str=0;
    int end=n.size()-1;

    while(str<=end){
        int mid=(str+end)/2;       //-------> optimized formula for mid
                                //// mid= str +(end-str)/2
        if(tar< n[mid]){
            end=mid-1;
        }
        else if(tar>n[mid]){/// comparison of target with the middle value of the array/vector 
            str=mid+1;
        }
        else{
            return mid;
        }

    }
    return -1;
}
// binary search algorithm using recursion 
int binary_search_recursive(vector<int> n,int tar, int start ,int end){
    if(start<=end){
        int mid= start+(end-start)/2;
        if(tar>n[mid]){
            return binary_search_recursive(n,tar,mid+1,end);
        }
        else if(tar<n[mid]){
            return binary_search_recursive(n,tar,start,mid-1);
        }
        else{
            return mid;
        }
    }
    return -1;
}
int main(){
    vector<int> num={1,2,3,4,5,6,7,8,9};
    int start=0;
   int end=num.size()-1;
    cout<<binary_search_recursive(num,30,start,end);
   
}