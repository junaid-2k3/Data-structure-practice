// Use a single array of size n.

// Stack 1 starts from index 0 and grows to the right.

// Stack 2 starts from index n-1 and grows to the left.

// Prevent overflow by checking if they overlap.



#include <iostream>
using namespace std;

class TwoStacks {
private:
    int* arr;
    int size;
    int top1, top2;

public:
    TwoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }

    // Push to Stack 1
    void push1(int x) {
        if (top1 < top2 - 1) {
            arr[++top1] = x;
        } else {
            cout << "Stack Overflow in Stack 1\n";
        }
    }

    // Push to Stack 2
    void push2(int x) {
        if (top1 < top2 - 1) {
            arr[--top2] = x;
        } else {
            cout << "Stack Overflow in Stack 2\n";
        }
    }

    // Pop from Stack 1
    int pop1() {
        if (top1 >= 0) {
            return arr[top1--];
        } else {
            cout << "Stack Underflow in Stack 1\n";
            return -1;
        }
    }

    // Pop from Stack 2
    int pop2() {
        if (top2 < size) {
            return arr[top2++];
        } else {
            cout << "Stack Underflow in Stack 2\n";
            return -1;
        }
    }

    // Optional: Display both stacks
    void display() {
        cout << "Stack 1: ";
        for (int i = 0; i <= top1; ++i)
            cout << arr[i] << " ";
        cout << "\nStack 2: ";
        for (int i = size - 1; i >= top2; --i)
            cout << arr[i] << " ";
        cout << endl;
    }

    ~TwoStacks() {
        delete[] arr;
    }
};

int main() {
    TwoStacks ts(10);

    ts.push1(5);
    ts.push1(10);
    ts.push2(100);
    ts.push2(200);

    ts.display();

    cout << "Popped from Stack 1: " << ts.pop1() << endl;
    cout << "Popped from Stack 2: " << ts.pop2() << endl;

    ts.display();

    return 0;
}
