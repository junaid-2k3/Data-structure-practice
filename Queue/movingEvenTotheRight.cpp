//To move all even numbers to the rear of a queue of integers while maintaining the relative order of both odd and even numbers

// Approach : make two / queues of arrays and store even and odd in sequence then build the original queue placing the even at the right 
#include <iostream>
#include <queue>
using namespace std;

void moveEvensToRear(queue<int>& q) {
    int size = q.size();
    queue<int> odds, evens;

    // Separate odds and evens
    for (int i = 0; i < size; ++i) {
        int val = q.front();
        q.pop();
        if (val % 2 == 0)
            evens.push(val);  // Even numbers
        else
            odds.push(val);   // Odd numbers
    }

    // Rebuild original queue: first odds, then evens
    while (!odds.empty()) {
        q.push(odds.front());
        odds.pop();
    }
    while (!evens.empty()) {
        q.push(evens.front());
        evens.pop();
    }
}

int main() {
    queue<int> q;
    q.push(5);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(6);
    q.push(7);

    moveEvensToRear(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
