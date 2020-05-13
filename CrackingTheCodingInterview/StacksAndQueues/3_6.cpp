//
// Sort stack
//
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

void Show(stack <int> data) {
    while (not data.empty()) {
        cout << data.top() << ' ';
        data.pop();
    }
    cout << endl;
}

void SortStack(stack <int>& data) {
    if (data.empty()) {
        return;
    }
    stack <int> buffer;
    while (not data.empty()) {
        while (not data.empty() and (buffer.empty() or data.top() <= buffer.top())) {
            buffer.push(data.top());
            data.pop();
        }
        if (data.empty()) {
            break;
        }
        int box = data.top();
        data.pop();
        do {
            data.push(buffer.top());
            buffer.pop();
        } while (not buffer.empty() and buffer.top() <= box);
        buffer.push(box);
    }
    while (not buffer.empty()) {
        data.push(buffer.top());
        buffer.pop();
    }
}

bool Test() {
    {
        vector <int> data = {1, 2, 3, 4, 5};
        stack <int> s;
        for (int v : data) {
            s.push(v);
        }
        sort(data.begin(), data.end(), greater<>());
        SortStack(s);
        for (int v : data) {
            if (v != s.top()) {
                return false;
            }
            s.pop();
        }
    }
    {
        vector <int> data = {5, 2, 3, 4, 1};
        stack <int> s;
        for (int v : data) {
            s.push(v);
        }
        sort(data.begin(), data.end(), greater<>());
        SortStack(s);
        for (int v : data) {
            if (v != s.top()) {
                return false;
            }
            s.pop();
        }
    }
    {
        vector <int> data = {};
        stack <int> s;
        for (int v : data) {
            s.push(v);
        }
        sort(data.begin(), data.end(), greater<>());
        SortStack(s);
        for (int v : data) {
            if (v != s.top()) {
                return false;
            }
            s.pop();
        }
    }
    {
        vector <int> data = {-1, 123, 234234, -123123, 555, 1231, -123123, 0};
        stack <int> s;
        for (int v : data) {
            s.push(v);
        }
        sort(data.begin(), data.end(), greater<>());
        SortStack(s);
        for (int v : data) {
            if (v != s.top()) {
                return false;
            }
            s.pop();
        }
    }
    return true;
}

int main() {

    cout << Test();

    return 0;
}
