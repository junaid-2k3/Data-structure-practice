#include <iostream>
using namespace std;

struct Node{
    Node* next;
    int val;
    Node(int val=0):next(nullptr){}
};

class linkedList{
    private:
    Node*  head;
    Node* tail;
    int val;
    int afterVal;

    public:
    linkedList():head(nullptr),tail(nullptr){}

    void insertion_at_start(){
            cout<<"enter value "<<endl;
            cin>>val;
            Node* newNode=new Node(val);
        if(!head){
            head=newNode;
            tail=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }
    void insertion_at_end(){
        cout<<"enter value "<<endl;
            cin>>val;
            Node* newNode=new Node(val);
        if(!head){
            head=newNode;
            tail=newNode;
        }
        


    }
    void display_list(){
        if(head==nullptr){
            cout<<"the list is empty"<<endl;
            return;
        }
        else{
            Node* curr=head;
            while(curr){
                cout<<curr->val<<endl;
                curr=curr->next;
            }
        }
    }
};
int main(){
    linkedList list;
    list.insertion_at_start();
    list.insertion_at_start();
    list.insertion_at_start();
    list.display_list();

}