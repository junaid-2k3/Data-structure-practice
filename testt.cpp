#include <iostream>
using namespace std;
int main(){
int arr[]={10,20,30,40,50};
int *a=arr;
a+=2;
cout<<*a<<endl;
*a=*a*2-13;
cout<<*a<<endl;
int *b=a--;
cout<<*a;
cout<<endl;
cout<<*b;
// cout<<endl;
// cout<<*(a+2)<<endl;
// *(a+3)=100;
// cout<<*a;cout<<endl;
// int *c=a+1;
// cout<<*(c-1)<<endl;
// cout<<*(c)<<endl;
// cout<<arr[2];
// cout<<endl;
// cout<<arr[4];

}
