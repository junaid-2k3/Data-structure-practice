// parenthesis matching 
// => when a parenthesis or bracket is encountered it is pushed into the stack ,and it is only poped when its counterpart is encountered in the input. If the function goes through the whole of input and the stack came out empty it means the input is balanced but if the stack has a bracket or parenthesis it means the input is unbalanced 
// what if the counter part comes first then it is considered as an extra bracket and still the input is unbalanced 

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool areParenthesesBalanced(const string& expr) {
    stack<char> s;

    for (char ch : expr) {   // traversal of expression form left to right\

        // If it's an opening bracket, push to stack
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }
        // If it's a closing bracket, check for matching
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.empty()) return false; // No matching opening
            if (!isMatchingPair(s.top(), ch)) return false;
            s.pop(); // Matched pair , the pop the opening bracket from the stack
        }
    }

    // Stack should be empty if balanced
    return s.empty();
}

int main() {
    string expr;
    cout << "Enter expression with (), {}, []: ";
    getline(cin, expr);

    if (areParenthesesBalanced(expr)) {
        cout << "The parentheses are balanced.\n";
    } else {
        cout << "The parentheses are NOT balanced.\n";
    }

    return 0;
}
