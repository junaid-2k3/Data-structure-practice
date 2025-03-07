#include <iostream>
using namespace std;

struct Node
{
    Node *next;
    int val;

    Node(int val = 0) : next(nullptr), val(val) {}
};

class stack
{
public:
    Node *top;
    stack() : top(nullptr) {}
    void push(int val)
    {
        Node *newNode = new Node(val);
        if (top == nullptr)
        {
            top = newNode;
            return;
        }
        newNode = top;
        top = newNode;
    }
    void Pop()
    {
        if (top == nullptr)
        {
            cout << "the stack is empty" << endl;
            return;
        }
        Node *curr = top;
        top = top->next;
        delete curr;
    }
    int peek()
    {
        return top ? top->val : -1;
    }

    void display()
    {

        Node *curr = top;

        while (curr!=nullptr)
        {

            cout << curr->val << " ";

            curr = curr->next;
        }

        cout << endl;
    }
};
int main(){
    stack k;
    k.push(1);
    k.push(2);
    k.push(3);
    k.push(4);
    k.display();
}