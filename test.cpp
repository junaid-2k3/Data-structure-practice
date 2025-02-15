#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

void display(vector<int> v){
    for( int c : v){
        cout<<c<<" ";
    }

}
int main(){
   
   vector<int> num(20);
    srand(time(0));
   for(int i=0 ;i<20;i++){
    num[i]=rand()%5;;
   }
   for(int c : num){
    cout<<c<<" ";
   }
   cout<<"hello world"<<endl;
}