#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
  /// the iterative method 
void reverseString(string &strr){
    int start=0;
    int end=strr.length()-1;
    while(start!=end && start<end){
        swap(strr[start],strr[end]);
        start++;
        end--;
    }
}

int main(){
string name="junadi";
reverseString(name);cout<<endl;
cout<<name<<endl;
return 0;
}