#include <bits/stdc++.h>

using namespace std;

bool isOperator(const string& op) {
    return op == "*" || op == "/" || op == "+" || op == "-";
}

function<int(string, int, int)> op = [](string op, int operand1, int operand2){
    if (op == "/") return operand1 / operand2;
    if (op == "*") return operand1 * operand2;
    if (op == "+") return operand1 + operand2;
    if (op == "-") return operand1 - operand2;
    else return 0;
};

int evalRPN(vector<string>& tokens) {
    stack<int> rpn;

    for(int i = 0; i < tokens.size(); ++i) {
        if(!isOperator(tokens[i])) {
            rpn.push(stoi(tokens[i]));
        } else {
            int operand2 = rpn.top();
            rpn.pop();
            int operand1 = rpn.top();
            rpn.pop();

            rpn.push(op(tokens[i], operand1, operand2));
        }
    }

    return rpn.top();
}

int main() {
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout<<evalRPN(tokens);

    return 0;
}