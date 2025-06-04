//you might be thinking we can split an array into two parts ,one half for one queue and other half for the other queue 
// the problem with this approach is that it doesnot allow use of elements beyond the limits of the queue 
#include <iostream>
using namespace std;

class TwoQueues {
    int* arr;
    int size;
    int front1, rear1, front2, rear2;

public:
    TwoQueues(int n) {
        size = n;
        arr = new int[n];
        front1 = rear1 = -1;
        front2 = rear2 = n;
    }

    void enqueue1(int x) {
        if (rear1 < rear2 - 1) {
            if (front1 == -1) front1 = 0;
            arr[++rear1] = x;
        } else {
            cout << "Queue1 Overflow\n";
        }
    }

    void enqueue2(int x) {
        if (rear1 < rear2 - 1) {
            if (front2 == size) front2 = size - 1;
            arr[--rear2] = x;
        } else {
            cout << "Queue2 Overflow\n";
        }
    }

    int dequeue1() {
        if (front1 == -1 || front1 > rear1) {
            cout << "Queue1 Underflow\n";
            return -1;
        }
        return arr[front1++];
    }

    int dequeue2() {
        if (front2 == size || front2 < rear2) {
            cout << "Queue2 Underflow\n";
            return -1;
        }
        return arr[front2--];
    }
};
