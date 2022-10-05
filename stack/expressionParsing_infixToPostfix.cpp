/*
    Parsing Expression 
    both from Interger and Variables
*/

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


/*
    Enter Infix Expression: ((a + b - c) * d ^ e ^ f) / g
    Converted Postfix Expression: a b + c - d e f ^ ^ * g /
*/
