# Infix, Prefix & Postfix
Related to Operator Precedence.

## Infix to Postfix
This Program Evaluates Any Expression (Both Integers & Variables) from Infix to Postfix.

> `main.cpp`
```cpp=
#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char ch) {
    if (ch == '^') return 3;
    else if (ch == '*' || ch == '/') return 2;
    else if (ch == '+' || ch == '-') return 1;
    else return -1;
}

bool isOperand(char ch) {
    if (ch >= 'a' && ch <= 'z') return true;
    else if (ch >= 'A' && ch <= 'Z') return true;
    else if (ch >= '0' && ch <= '9') return true;
    else return false;
}

string infixToPostFix(string infix) {
    stack <char> stk;
    string postfix = "";
    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] == ' ') continue;
        if (isOperand(infix[i])) {
            postfix += infix[i];
            postfix += ' ';
        }
        else if (infix[i] == '(') stk.push(infix[i]);
        else if (infix[i] == ')') {
            while (stk.top() != '(' && !stk.empty()) {
                postfix += stk.top();
                postfix += ' ';
                stk.pop();
            }
            if (stk.top() == '(') stk.pop();
        } else if (isOperator(infix[i])) {
            if (stk.empty()) stk.push(infix[i]);
            else {
                if (precedence(infix[i]) > precedence(stk.top())) stk.push(infix[i]);
                else if (precedence(infix[i]) == precedence(stk.top()) && infix[i] == '^') stk.push(infix[i]);
                else {
                    while (!stk.empty() && precedence(infix[i]) <= precedence(stk.top())) {
                        postfix += stk.top();
                        postfix += ' ';
                        stk.pop();
                    }
                    stk.push(infix[i]);
                }
            }
        }
    }
    while (!stk.empty()) {
        postfix += stk.top();
        postfix += ' ';
        stk.pop();
    }
    return postfix;
}

int main() {
    string infix, postfix;
    cout << "Enter Infix Expression: ";
    getline(cin, infix);
    postfix = infixToPostFix(infix);
    cout << "Converted Postfix Expression: " << postfix << endl;
    return 0;
}
```

> `output.txt`
```txt
Enter Infix Expression: ((a + b - c) * d ^ e ^ f) / g
Converted Postfix Expression: a b + c - d e f ^ ^ * g /
```

## Postfix Evaluation
Note: Only with Integers as Operand.

This Program Evaluates Any Integer Based Postfix Expression into A Final Solution.

> `main.cpp`
```cpp=
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

bool isInteger(char ch) {
    return (ch >= '0' && ch <= '9');
}

int operation(char sign, int firstOperand, int secondOperand) {
    if (sign == '+') return firstOperand + secondOperand;
    else if (sign == '-') return firstOperand - secondOperand;
    else if (sign == '*') return firstOperand * secondOperand;
    else if (sign == '/') return firstOperand / secondOperand;
    else if (sign == '^') return (pow(firstOperand, secondOperand));
    else return -1;
}

int evaluatePostFix(string postfix) {
    stack <int> stk;
    for (int i = 0; i < postfix.size(); i++) {
        if (postfix[i] == ' ' || postfix[i] == ',') continue;

        if (isInteger(postfix[i])) {
            int operand = 0;
            while (i < postfix.length() && isInteger(postfix[i])) {
                operand = (operand * 10) + (postfix[i] - '0');
                i++;
            }
            i--;
            stk.push(operand);
        } else if (isOperator(postfix[i])) {
            int operand02 = stk.top();
            stk.pop();
            int operand01 = stk.top();
            stk.pop();
            int outcome = operation(postfix[i], operand01, operand02);
            stk.push(outcome);
        }
    }
    return stk.top();
}

int main () {
    string postfix;
    cout << "Enter Postfix Expression: ";
    getline(cin, postfix);
    int answer = evaluatePostFix(postfix);
    cout << "Answer is " << answer << endl;
}
```

> `output.txt`
```txt
Enter Postfix Expression: 7 5 4 * + 9 2 * - 5 + 9 3 / + 2 -
Answer is 15
```
