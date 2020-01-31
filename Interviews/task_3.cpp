#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
    int amount;
    vector<int> data;

    void Update(int node_ind, int cur_left, int cur_right,
                int query_left, int query_right, int value) {
        if (query_left > query_right) {
            return;
        }
        if (cur_left == cur_right) {
            data[node_ind] += value;
            return;
        }
        int left_child_end = cur_left + (cur_right - cur_left) / 2; // mid
        Update(node_ind * 2 + 1, cur_left, left_child_end,
               query_left, min(left_child_end, query_right), value);
        Update(node_ind * 2 + 2, left_child_end + 1, cur_right,
               max(left_child_end + 1, query_left), query_right, value);
        data[node_ind] = data[node_ind * 2 + 1] + data[node_ind * 2 + 2];
    }

    int Sum(int node_ind, int cur_left, int cur_right,
            int query_left, int query_right) const {
        if (query_left > query_right) {
            return 0;
        }
        if (cur_left == query_left and cur_right == query_right) {
            return data[node_ind];
        }
        int left_child_end = cur_left + (cur_right - cur_left) / 2; // mid
        int box = 0;
        box += Sum(node_ind * 2 + 1, cur_left, left_child_end,
                      query_left, min(left_child_end, query_right));
        box += Sum(node_ind * 2 + 2, left_child_end + 1, cur_right,
               max(left_child_end + 1, query_left), query_right);
        return box;
    }

public:
    explicit SegmentTree(int n) : amount(n), data(4 * n) {
    }

    void Show() const {
        for (int i : data) {
            cout << i << ' ';
        }
        cout << std::endl;
    }

    void Add(int query_left, int query_right, int value) {
        Update(0, 0, 2 * amount - 1, query_left, query_right, value);
    }

    int GetSum(int query_left, int query_right) const {
        return Sum(0, 0, 2 * amount - 1, query_left, query_right);
    }

};

// Main idea is to use intervals tree.

int main() {
    auto box = SegmentTree(4);
    box.Add(0, 1, 3);
    box.Add(2, 3, 2);
    box.Add(1, 2, 5);
    box.Add(1, -1, 5); // wrong input
    box.Add(0, 123, 1); // right index after end
    box.Add(100, 123, 1); // both index after end
    cout << box.GetSum(0, 0) << endl;
    cout << box.GetSum(0, 3) << endl;
    return 0;
}