//
// Implement queue with two stacks
//
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Queue {
public:
    void PushBack(int value) {
        in_d.push(value);
    }

    void PopFront() {
        Balance();
        out_d.pop();
    }

    int Front() {
        Balance();
        return out_d.top();
    }

private:
    void Balance() {
        if (out_d.empty()) {
            while (not in_d.empty()) {
                out_d.push(in_d.top());
                in_d.pop();
            }
        }
    }

    stack <int> in_d;
    stack <int> out_d;
};

bool Test() {
    {
        vector <int> data = {1, 2, 3};
        Queue q;
        for (int v : data) {
            q.PushBack(v);
        }
        for (int i = 0; i < data.size(); ++i) {
            if (q.Front() != data[i]) {
                return false;
            }
            q.PopFront();
        }
    }
    {
        vector <int> data = {1, 2, 3, 4, 5};
        Queue q;
        for (int v : data) {
            q.PushBack(v);
        }
        q.PopFront();
        q.PopFront();
        if (q.Front() != 3) {
            return false;
        }
        q.PopFront();
        if (q.Front() != 4) {
            return false;
        }
        q.PopFront();
        if (q.Front() != 5) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test();

    return 0;
}

