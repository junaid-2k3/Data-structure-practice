#include <iostream>
using namespace std;
 int power(int b,int e){
    if(e==0){
        return 1;
    }
    if(e>0){
        return b*power(b,e-1);
    }else{
        return 1/power(b,e-1);
    }
 }
 int main(){
    cout<<power(2,3);
 }