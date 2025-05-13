#include <iostream>
#include <stack>
using namespace std;

// Helper function to insert an element in sorted order
void insertSorted(stack<int>& s, int val) {
    // Base case: stack is empty or top is smaller/equal
    if (s.empty() || s.top() <= val) {
        s.push(val);
        return;
    }

    // Otherwise pop and recurse
    int temp = s.top();
    s.pop();
    insertSorted(s, val);
    s.push(temp);
}

// Recursive function to sort the stack
void sortStack(stack<int>& s) {
    if (s.empty()) return;

    int temp = s.top();
    s.pop();
    sortStack(s);
    insertSorted(s, temp);
}

// Utility to print a stack
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(30);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);

    cout << "Original Stack:\n";
    printStack(s);

    sortStack(s);

    cout << "Sorted Stack (Ascending):\n";
    printStack(s);

    return 0;
}
