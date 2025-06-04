#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
//1. Array-Based Stack Implementation
class ArrayStack {
private:
    int arr[MAX_SIZE];
    int top;
    int size;

public:
    ArrayStack(int s) {
        size = s;
        top = -1;
    }

    bool isFull() {
        return top == size - 1;
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
};

// Array-based Queue Implementation (Pointer-based)
class ArrayQueue {
private:
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    ArrayQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = rear = -1;
        size = 0;
    }

    ~ArrayQueue() {
        delete[] arr;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        *(arr + rear) = value;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int value = *(arr + front);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        return value;
    }
};

// Function to delete element from array using pointers
void deleteElement(int* arr, int& size, int element) {
    int* ptr = arr;
    int* end = arr + size;
    
    while (ptr < end) {
        if (*ptr == element) {
            int* temp = ptr;
            while (temp < end - 1) {
                *temp = *(temp + 1);
                temp++;
            }
            size--;
            return;
        }
        ptr++;
    }
    cout << "Element not found!" << endl;
}

// Function to find third minimum using pointers
int findThirdMin(int* arr, int size) {
    if (size < 3) {
        cout << "Array too small!" << endl;
        return -1;
    }
    
    int first = INT_MAX, second = INT_MAX, third = INT_MAX;
    int* ptr = arr;
    
    for (int i = 0; i < size; i++) {
        if (*(ptr + i) < first) {
            third = second;
            second = first;
            first = *(ptr + i);
        } else if (*(ptr + i) < second && *(ptr + i) != first) {
            third = second;
            second = *(ptr + i);
        } else if (*(ptr + i) < third && *(ptr + i) != second && *(ptr + i) != first) {
            third = *(ptr + i);
        }
    }
    
    return third;
}

// Function to eliminate duplicates using pointers
void eliminateDuplicates(int* arr, int& size) {
    if (size <= 1) return;
    
    int* ptr1 = arr;
    int* ptr2 = arr + 1;
    int* end = arr + size;
    
    while (ptr2 < end) {
        if (*ptr1 != *ptr2) {
            ptr1++;
            *ptr1 = *ptr2;
        }
        ptr2++;
    }
    
    size = ptr1 - arr + 1;
}

// Function to display array
void displayArray(int* arr, int size) {
    cout << "Array: [";
    for (int i = 0; i < size; i++) {
        cout << *(arr + i);
        if (i < size - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    int choice;
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    
    int* arr = new int[size];
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> *(arr + i);
    }
    
    ArrayStack stack(size);
    ArrayQueue queue(size);
    
    do {
        cout << "\n===== ARRAY OPERATIONS MENU =====" << endl;
        cout << "1. Push to Stack" << endl;
        cout << "2. Pop from Stack" << endl;
        cout << "3. Peek Stack" << endl;
        cout << "4. Enqueue to Queue" << endl;
        cout << "5. Dequeue from Queue" << endl;
        cout << "6. Display Array" << endl;
        cout << "7. Delete Element (Pointer-Based)" << endl;
        cout << "8. Find Third Minimum Value" << endl;
        cout << "9. Eliminate Duplicates" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                int value;
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            }
            case 2: {
                int value = stack.pop();
                if (value != -1) {
                    cout << "Popped value: " << value << endl;
                }
                break;
            }
            case 3: {
                int value = stack.peek();
                if (value != -1) {
                    cout << "Top value: " << value << endl;
                }
                break;
            }
            case 4: {
                int value;
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            }
            case 5: {
                int value = queue.dequeue();
                if (value != -1) {
                    cout << "Dequeued value: " << value << endl;
                }
                break;
            }
            case 6: {
                displayArray(arr, size);
                break;
            }
            case 7: {
                int element;
                cout << "Enter element to delete: ";
                cin >> element;
                deleteElement(arr, size, element);
                break;
            }
            case 8: {
                int thirdMin = findThirdMin(arr, size);
                if (thirdMin != -1) {
                    cout << "Third minimum value: " << thirdMin << endl;
                }
                break;
            }
            case 9: {
                eliminateDuplicates(arr, size);
                cout << "Duplicates eliminated!" << endl;
                break;
            }
            case 10: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice!" << endl;
            }
        }
    } while (choice != 10);
    
    delete[] arr;
    return 0;
} 