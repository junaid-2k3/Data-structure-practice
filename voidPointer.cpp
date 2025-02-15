#include <iostream>
using namespace std;
int main(){
char ch='a';
void* ptr=&ch;
cout<<(static_cast<void*>(&ch));
cout<<endl;
cout<<(static_cast<void*>(ptr));
}