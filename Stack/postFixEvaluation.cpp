// post fix equation evaluation 
// =>you would start reading the equation from left to right , push to the stack if its an operand and pop if its an operator.
// for example the equation (3+5)*2 is in infix form and can be written in postfix form as 35+2* ,if its evaluated using stack , first 3 would be pushed into the stack ,then 5 ,then + operator as soon as the operator comes its gonna do the operation on the top most two element and pop them , and there answer will be pushed into the stack ,so now in the stack only 8 remains(3+5=8) then 2 is pushed into the stack ,then the operator (*), when this operator is pushed the last two elements are poped and evaluated according to the operator and their answer is pushed into the stack , so (8*2=14) so 14 is pushed into the stack .there should only remain one element in the stack which will be the answer of the whole equation . 
#include <iostream>
#include <stack>
#include <string>
#include <cctype>  // for isdigit
using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(const string& expression) { // expression passed by reference 
    stack<int> s;                             // step 1 , stack banao

    for (char ch : expression) {        // step2 , expression ko traverse kro 
        if (ch == ' ') continue; // skip spaces 

        // If the character is a digit (operand) agr to digit hai to stack mai push karo
        if (isdigit(ch)) {// check if the input is a digit between 1-9
            s.push(ch - '0'); // convert char to int
        } 
        // If the character is an operator
        else {  // means an operator 
            int operand1 = s.top(); s.pop();
            int operand2 = s.top(); s.pop();
            int result;

            switch (ch) {
                case '+': result = operand2 + operand1; break;
                case '-': result = operand2 - operand1; break;
                case '*': result = operand2 * operand1; break;
                case '/': result = operand2 / operand1; break;
                default:
                    cout << "Invalid operator: " << ch << endl; // in postfix order there  are no brackets , so if bracket comes in it will output "invalid op.."
                    return -1;
            }

            s.push(result);
        }
    }

    return s.top(); // final result
}

// Example usage
int main() {
    string postfix = "23*54*+9-";  // (2*3) + (5*4) - 9 = 6 + 20 - 9 = 17
    int result = evaluatePostfix(postfix);
    cout << "Result of postfix expression '" << postfix << "' is: " << result << endl;
    return 0;
}
