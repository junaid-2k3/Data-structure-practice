// Pop one element (temp) from the original stack.

// While the temporary stack is not empty and its top is greater than temp, pop from the temporary stack and push back to the original stack.

// Push temp into the correct position in the temporary stack.

// Repeat until the original stack is empty.

// At the end, the temporary stack contains elements in sorted order (ascending) (smallest on bottom, largest on top).
#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int>& input) {
    stack<int> tempStack;

    while (!input.empty()) {
        int temp = input.top();
        input.pop();

        // Move elements from tempStack back to input if they're greater than temp
        while (!tempStack.empty() && tempStack.top() > temp) {
            input.push(tempStack.top());
            tempStack.pop();
        }

        // Insert temp in sorted order
        tempStack.push(temp);
    }

    // Copy sorted stack back to input (optional, if you want sorted input stack)
    while (!tempStack.empty()) {
        input.push(tempStack.top());
        tempStack.pop();
    }
}

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(34);
    s.push(3);
    s.push(31);
    s.push(98);
    s.push(92);
    s.push(23);

    cout << "Original stack:\n";
    printStack(s);

    sortStack(s);

    cout << "Sorted stack (ascending):\n";
    printStack(s);

    return 0;
}
