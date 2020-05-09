#include <iostream>
#include <vector>

using namespace std;

class MinStack {
public:

    void Push(int val) {
        int prevMin = data.size() > 0 ? data.back().second : val;
        data.emplace_back(val, min(val, prevMin));
    }

    void Pop() {
        data.pop_back();
    }

    int Top() {
        if (data.empty()) {
            throw out_of_range("empty");
        }
        return data.back().first;
    }

    int GetMin() {
        if (data.empty()) {
            throw out_of_range("empty");
        }
        return data.back().second;
    }

private:
    vector <pair <int, int>> data; // value, min
};

bool Test() {
    {
        vector <int> data = {1, 2, -1, 3};
        MinStack mnStack;
        for (int v : data) {
            mnStack.Push(v);
        }
        vector <int> mins = {1, 1, -1, -1};
        for (int i = 0; i < mins.size(); ++i) {
            if (mins[mins.size() - 1- i] != mnStack.GetMin()) {
                return false;
            }
            if (data[data.size() - 1 - i] != mnStack.Top()) {
                return false;
            }
            mnStack.Pop();
        }
    }
    return true;
}

int main() {

    cout << Test();

    return 0;
}