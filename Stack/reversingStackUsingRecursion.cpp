#include <iostream>
#include <stack>
using namespace std;

// Helper function to insert element at bottom of stack
void insertAtBottom(stack<int>& s, int value) {
    if (s.empty()) {
        s.push(value);
        return;
    }

    int temp = s.top();
    s.pop();
    insertAtBottom(s, value);
    s.push(temp);
}

// Main recursive function to reverse the stack
void reverseStack(stack<int>& s) {
    if (s.empty()) return;

    int temp = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, temp);
}

// Utility function to print stack
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "Original Stack:\n";
    printStack(s);

    reverseStack(s);

    cout << "Reversed Stack:\n";
    printStack(s);

    return 0;
}
