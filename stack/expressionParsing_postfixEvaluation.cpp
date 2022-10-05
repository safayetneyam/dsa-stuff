/*
    Postfix Evaluation
    Only with Integers as Operand
*/

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

/*
    Enter Postfix Expression: 7 5 4 * + 9 2 * - 5 + 9 3 / + 2 -
    Answer is 15
*/
