//implementation of stact using vectors
#include <iostream>          
#include <vector>
// #define stack_size 5
using namespace std;

class stack{
    public:
    vector<int> stvec;
    int max_size;

    stack(int n):max_size(n){}

    bool is_full(){
        return stvec.size()==max_size;
    }
    
    void pop(){
        if(stvec.empty()){
            cout<<"the stack is empty"<<endl;
            return ;
        }
        // stvec.erase(stvec.begin()+top);
        stvec.pop_back();
    }
    void push(int val){
        if(is_full()){
            cout<<"the stack is full :"<<endl;
            return;
        }
        stvec.push_back(val);
    }
    void display(){
        for(int c : stvec){
            cout<<c<<" ";
        }
    }
    void display_and_pop(){
        for(int c : stvec){
            cout<<c<<" ";
            pop();
            
        }
    }
    void seek(){
        
    }
};
int main(){
stack stack1(3);
stack1.push(23);
stack1.push(24);
stack1.push(25);
// stack1.push(26);
// stack1.push(27);

stack1.display();
cout<<endl;
// cout<<"pop function :"<<endl;
// stack1.pop();
// stack1.display();
}
