#include <iostream>
using namespace std;
void swap(int *x , int *y){
    int temp = *x;
    *x = *y;
    *y =temp;

}
int main(){
  int a,b;
     cout<<" enter values for a and b"<<endl;
     cin>>a;
     cin>>b;
     swap(&a ,&b);

    cout<<"value of a after swaping  :"<<a <<endl;
    cout<<"value of b after swaping  :"<<b <<endl;

     
}