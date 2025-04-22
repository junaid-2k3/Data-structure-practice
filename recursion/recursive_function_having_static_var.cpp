#include <iostream>
using namespace std;

int recur_ftn(int n){
    static int x=0; // using the =
    if(n>0){
        x++;
        return recur_ftn(n-1)+x;
    }
    else
    return 0;
}
int main(){
int n=5;
int result=recur_ftn(n);
cout<<result<<endl;
}