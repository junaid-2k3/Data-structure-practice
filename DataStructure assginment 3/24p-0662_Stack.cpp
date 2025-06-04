#include <iostream>
#include <stack>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << "Stack: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
//1. Sort a Stack Using Only Stack Operations
// Function to sort stack using recursion
void sortedInsert(Stack& s, int value) {
    if (s.isEmpty() || value > s.peek()) {
        s.push(value);
        return;
    }
    int temp = s.pop();
    sortedInsert(s, value);
    s.push(temp);
}

void sortStack(Stack& s) {
    if (!s.isEmpty()) {
        int value = s.pop();
        sortStack(s);
        sortedInsert(s, value);
    }
}
//2. Reverse Stack Using Recursion
// Function to reverse stack using recursion
void insertAtBottom(Stack& s, int value) {
    if (s.isEmpty()) {
        s.push(value);
        return;
    }
    int temp = s.pop();
    insertAtBottom(s, value);
    s.push(temp);
}

void reverseStack(Stack& s) {
    if (!s.isEmpty()) {
        int value = s.pop();
        reverseStack(s);
        insertAtBottom(s, value);
    }
}

//4) Function to check balanced brackets
bool isBalanced(string expression) {
    stack<char> s;
    for (char c : expression) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else {
            if (s.empty()) return false;
            char top = s.top();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

// Class for two stacks in one array // implementing two stacks in one array 
class TwoStacks {
private:
    int* arr;
    int size;
    int top1;
    int top2;

public:
    TwoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    ~TwoStacks() {
        delete[] arr;
    }

    void push1(int value) {
        if (top1 < top2 - 1) {
            arr[++top1] = value;
        } else {
            cout << "Stack Overflow!" << endl;
        }
    }

    void push2(int value) {
        if (top1 < top2 - 1) {
            arr[--top2] = value;
        } else {
            cout << "Stack Overflow!" << endl;
        }
    }

    int pop1() {
        if (top1 >= 0) {
            return arr[top1--];
        } else {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
    }

    int pop2() {
        if (top2 < size) {
            return arr[top2++];
        } else {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
    }

    void display() {
        cout << "Stack 1: ";
        for (int i = top1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\nStack 2: ";
        for (int i = top2; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int choice, size, value;
    cout << "Enter size of stack: ";
    cin >> size;
    
    Stack s(size);
    TwoStacks ts(size * 2);
    string expression;
    
    do {
        cout << "\n===== STACK OPERATIONS MENU =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display Stack" << endl;
        cout << "5. Sort Stack" << endl;
        cout << "6. Reverse Stack" << endl;
        cout << "7. Check Balanced Brackets" << endl;
        cout << "8. Two Stacks in One Array" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            }
            case 2: {
                value = s.pop();
                if (value != -1) {
                    cout << "Popped value: " << value << endl;
                }
                break;
            }
            case 3: {
                value = s.peek();
                if (value != -1) {
                    cout << "Top value: " << value << endl;
                }
                break;
            }
            case 4: {
                s.display();
                break;
            }
            case 5: {
                sortStack(s);
                cout << "Stack sorted!" << endl;
                break;
            }
            case 6: {
                reverseStack(s);
                cout << "Stack reversed!" << endl;
                break;
            }
            case 7: {
                cout << "Enter expression: ";
                cin >> expression;
                if (isBalanced(expression)) {
                    cout << "Expression is balanced!" << endl;
                } else {
                    cout << "Expression is not balanced!" << endl;
                }
                break;
            }
            case 8: {
                int subChoice;
                do {
                    cout << "\n===== TWO STACKS MENU =====" << endl;
                    cout << "1. Push to Stack 1" << endl;
                    cout << "2. Push to Stack 2" << endl;
                    cout << "3. Pop from Stack 1" << endl;
                    cout << "4. Pop from Stack 2" << endl;
                    cout << "5. Display Both Stacks" << endl;
                    cout << "6. Back to Main Menu" << endl;
                    cout << "Enter your choice: ";
                    cin >> subChoice;
                    
                    switch (subChoice) {
                        case 1: {
                            cout << "Enter value to push to Stack 1: ";
                            cin >> value;
                            ts.push1(value);
                            break;
                        }
                        case 2: {
                            cout << "Enter value to push to Stack 2: ";
                            cin >> value;
                            ts.push2(value);
                            break;
                        }
                        case 3: {
                            value = ts.pop1();
                            if (value != -1) {
                                cout << "Popped from Stack 1: " << value << endl;
                            }
                            break;
                        }
                        case 4: {
                            value = ts.pop2();
                            if (value != -1) {
                                cout << "Popped from Stack 2: " << value << endl;
                            }
                            break;
                        }
                        case 5: {
                            ts.display();
                            break;
                        }
                        case 6: {
                            break;
                        }
                        default: {
                            cout << "Invalid choice!" << endl;
                        }
                    }
                } while (subChoice != 6);
                break;
            }
            case 9: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice!" << endl;
            }
        }
    } while (choice != 9);
    
    return 0;
} 