#include <iostream>
using namespace std;
class student {
    public:
    string name;
    int age;
};

int main(){
    student junaid;
    cout<<"enter the name :"<<endl;
    // cin.getline(junaid.name); // syntax 1
    getline(cin,junaid.name);  // syntax 2 
}