#include <iostream>
#include <string>
#include <stack>
#include <sstream>

std::string toPostFix(const std::string& exp) {
    std::string number;

    std::string post_fix;
    std::stack <char> operations;

    for (int i = 0; i != exp.length(); ++i) {
        while (i != exp.length() && '0' <= exp[i] && exp[i] <= '9') {
            number += exp[i];
            ++i;
        }
        if (!number.empty()) {
            post_fix += number + ' ';
            number = "";
        }
        if (i == exp.length()) {
            break;
        }
        if (exp[i] == '+' || exp[i] == '-') {
            while (!operations.empty() && (operations.top() == '*' || operations.top() == '/')) {
                post_fix += operations.top();
                post_fix += ' ';
                operations.pop();
            }
        }
        operations.push(exp[i]);
    }
    while (!operations.empty()) {
        post_fix += operations.top();
        post_fix += ' ';
        operations.pop();
    }
    return post_fix;
}

int eval(const std::string& post_fix) {
    std::stack <int> operands;
    std::stringstream sin(post_fix);
    std::string box;
    while(sin) {
        sin >> box;
        if (sin.tellg() == -1) {
            break;
        }
        if (!('0' <= box[0] && box[0] <= '9')) {
            int right = operands.top();
            operands.pop();
            int left = operands.top();
            operands.pop();
            if (box[0] == '+') {
                operands.push(left + right);
            } else if (box[0] == '-') {
                operands.push(left - right);
            } else if (box[0] == '*') {
                operands.push(left * right);
            } else if (box[0] == '/') {
                operands.push(left / right);
            }
        } else {
            operands.push(std::atoi(box.c_str()));
        }
    }
    return operands.top();
}

int main() {

    std::string line = "22*3+1*4+100+6/3";
    auto post_fix = toPostFix(line);
    std::cout << post_fix << std::endl;
    std::cout << eval(post_fix);

    return 0;
}