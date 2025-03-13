#include <iostream>
using namespace std;

void fun(int x){
    if(x>0){
        
        fun(x-1);
        cout<< x;cout<<endl;
    }
}
int main(){
int x=5;
fun(x);

}