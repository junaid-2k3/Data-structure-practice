#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool isPalindrome(queue<char> q) {
    stack<char> s;
    queue<char> temp = q;  // Make a copy

    // Push all elements into stack to reverse them
    while (!temp.empty()) {
        s.push(temp.front());
        temp.pop();
    }

    // Compare original queue and reversed stack
    while (!q.empty()) {
        if (q.front() != s.top()) return false;
        q.pop();
        s.pop();
    }

    return true;
}

int main() {
    queue<char> q;

    // Example input
    string input = "madam";
    for (char ch : input)
        q.push(ch);

    if (isPalindrome(q))
        cout << "Queue is a palindrome!" << endl;
    else
        cout << "Queue is NOT a palindrome." << endl;

    return 0;
}
