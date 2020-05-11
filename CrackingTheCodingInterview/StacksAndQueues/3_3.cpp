//
// Implement set of stacks
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class SetOfStacks {
public:
    explicit SetOfStacks(size_t maxStackSize_i = 1) : maxStackSize_d(maxStackSize_i) {

    }

    void Push(int value) {
        if (data_d.empty() or data_d.back().size() >= maxStackSize_d) {
            data_d.emplace_back();
        }
        data_d.back().push(value);
    }

    void Pop() {
        if (data_d.empty()) {
            throw out_of_range("empty");
        }
        while (data_d.back().empty()) {
            data_d.pop_back();
        }
        if (data_d.empty()) {
            throw out_of_range("empty");
        }
        data_d.back().pop();
    }

    int Top() {
        if (data_d.empty()) {
            throw out_of_range("empty");
        }
        while (data_d.back().empty()) {
            data_d.pop_back();
        }
        if (data_d.empty()) {
            throw out_of_range("empty");
        }
        return data_d.back().top();
    }

    void Pop(size_t stackId_i) {
        if (stackId_i >= data_d.size()) {
            throw out_of_range("no such stack");
        }
        if (data_d[stackId_i].empty()) {
            throw out_of_range("empty");
        }
        data_d[stackId_i].pop();
    }

private:
    size_t maxStackSize_d;
    vector <stack <int>> data_d;
};

bool Test() {
    {
        vector <int> data = {1, 2, 3};
        SetOfStacks ss;
        for (int v : data) {
            ss.Push(v);
        }
        for (int i = 0; i < data.size(); ++i) {
            if (ss.Top() != data[data.size() - 1 - i]) {
                return false;
            }
            ss.Pop();
        }
    }
    {
        vector <int> data = {1, 2, 3};
        SetOfStacks ss(3);
        for (int v : data) {
            ss.Push(v);
        }
        for (int i = 0; i < data.size(); ++i) {
            if (ss.Top() != data[data.size() - 1 - i]) {
                return false;
            }
            ss.Pop();
        }
    }
    {
        vector <int> data = {1, 2, 3, 4, 5};
        SetOfStacks ss(3);
        for (int v : data) {
            ss.Push(v);
        }
        for (int i = 0; i < data.size(); ++i) {
            if (ss.Top() != data[data.size() - 1 - i]) {
                return false;
            }
            ss.Pop();
        }
    }
    {
        vector <int> data = {1, 2, 3, 4, 5};
        SetOfStacks ss(2);
        for (int v : data) {
            ss.Push(v);
        }
        ss.Pop(1);
        ss.Pop(1);
        if (ss.Top() != 5) {
            return false;
        }
        ss.Pop();
        if (ss.Top() != 2) {
            return false;
        }
        if (ss.Top() != 2) {
            return false;
        }
        ss.Pop();
        if (ss.Top() != 1) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test();

    return 0;
}