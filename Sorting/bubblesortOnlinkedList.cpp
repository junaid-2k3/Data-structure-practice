#include<iostream>
using namespace std;

struct Node{
    Node* next;
    int data;
    Node(int val):next(nullptr),data(val){ 
    }
};
class linkedList{
    private :
    Node* root;
    public:
    linkedList():root(nullptr){}

    bool isempty(){
        return root == nullptr;
    }

    void insert(int val){ //isert at the begining 
        Node* newNode=new Node(val);
        if (isempty()) {
            root = newNode;
        }
         else {
            newNode->next = root;
            root = newNode;
    }

    }
    void display(){
        Node* tn=root;
        while(tn){
            cout<<tn->data<< " "<<endl;
            tn=tn->next;
        }
    }
    void swapNode(Node* n1,Node* n2){
        int temp=n1->data;
        n1->data=n2->data;
        n2->data=temp;
    }
    void bubblesort(){
        bool swaped=false;
        Node* outer=root;
    while(outer){    // outer loop
        swaped=false;
        Node* tn=root;
        while(tn->next){   // inner loop
            if(tn->data > tn->next->data){// if data of node 1 is greater than node 2 
                swapNode(tn,tn->next);
                swaped=true;

            }
            tn=tn->next;
        }
        if(swaped==false){
                cout<<"linked list is sorted"<<endl;
                return;
            }


    }   
}

};
int main(){
    linkedList list;
    list.insert(2);
    list.insert(1);
    list.insert(3);
    list.insert(5);
    list.insert(4);
    list.insert(7);
    list.display();
    list.bubblesort();
    list.display();
}
