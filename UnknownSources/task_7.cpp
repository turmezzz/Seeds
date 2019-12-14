#include <iostream>
#include <vector>

using namespace std;

pair <int, int> twoSumClosest(vector <int>& data, int k) {
    if (data.empty()) {
        return {-1, -1};
    }

    int l = 0;
    int r = data.size() - 1;

    int l_ans = l;
    int r_ans = r;

    while (l < r) {
        if (data[l] + data[r] < k) {
            ++l;
        } else {
            --r;
        }
        if (abs(data[l] + data[r] - k) < abs(data[l_ans] + data[r_ans] - k)) {
            l_ans = l;
            r_ans = r;
        }
    }
    return {l_ans, r_ans};
}

int main() {
    {
        vector <int> data = {2, 7, 11, 15};
        int k = 9;
        auto box = twoSumClosest(data, k);
        cout << data[box.first] << ' ' << data[box.second] << endl;
    }
    {
        vector <int> data = {2, 7, 11, 15, 20, 21, 21, 40};
        int k = 27;
        auto box = twoSumClosest(data, k);
        cout << data[box.first] << ' ' << data[box.second] << endl;
    }
    {
        vector <int> data = {1};
        int k = 9;
        auto box = twoSumClosest(data, k);
        cout << data[box.first] << ' ' << data[box.second] << endl;
    }
    {
        vector <int> data = {};
        int k = 9;
        auto box = twoSumClosest(data, k);
        if (box.first == -1) {
            cout << "wrong data" << endl;
        }
    }

    return 0;
}