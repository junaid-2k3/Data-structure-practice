#include<iostream> 
using namespace std;

int product( int n ,int m ){
    if(m==0){
        return 0;

    }
    return n+product(n,m-1);
}
int main(){
    
int n,m;cin>>n>>m;
cout<<"product :"<<product(n,m);
}