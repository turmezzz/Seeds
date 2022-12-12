#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:

    bool isValid(const string& line) {
        stack<char> box;
        for (auto l : line) {
            if (l == '(' or l == '{' or l == '[') {
                box.push(l);
            } else {
                if (!box.empty() and check(box.top(), l)) {
                    box.pop();
                } else {
                    return false;
                }
            }
        }
        return box.empty();
    }

private:

    bool check(char fromStack, char fromLine) {
        if (fromStack == '(' and fromLine == ')') {
            return true;
        } else if (fromStack == '{' and fromLine == '}') {
            return true;
        } else if (fromStack == '[' and fromLine == ']') {
            return true;
        }
        return false;
    }
};

bool Test() {
    Solution sol;
    {
        string line = "()";
        if (!sol.isValid(line)) {
            return false;
        }
    }
    {
        string line = "()[]{}";
        if (!sol.isValid(line)) {
            return false;
        }
    }
    {
        string line = "(]";
        if (sol.isValid(line)) {
            return false;
        }
    }
    {
        string line = "((";
        if (sol.isValid(line)) {
            return false;
        }
    }
    {
        string line = "))";
        if (sol.isValid(line)) {
            return false;
        }
    }
    {
        string line = "(()))";
        if (sol.isValid(line)) {
            return false;
        }
    }
    {
        string line = "((())";
        if (sol.isValid(line)) {
            return false;
        }
    }
    {
        string line = "(({{}}(([[]]()))))";
        if (!sol.isValid(line)) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test();

    return 0;
}