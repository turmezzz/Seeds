#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lower_bound(vector <int>& data, int x) {
        int l = 0;
        int r = data.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (data[m] < x) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (data[l] == x) {
            return l;
        }
        int prev = max(l - 1, 0);
        return (abs(x - data[prev]) <= abs(x - data[l])) ? prev : l;
    }

    vector<int> findClosestElements(vector<int>& data, int k, int x) {
        int closest = lower_bound(data, x);
        int l = max(0, closest - k + 1);
        int r = min <int>(data.size() - 1, closest + k - 1);

        while (r - l + 1 > k) {
            if (abs(data[l] - x) <= abs(data[r] - x)) {
                --r;
            } else {
                ++l;
            }
        }
        vector <int> ret(r - l + 1);
        for (int i = l; i <= r; (ret[i - l] = data[i], ++i));
        return ret;
    }
};

int main() {
    Solution sol;

    vector <int> data = {1, 2, 3, 4, 5};
    int x = 3;
    int k = 4;

    for (int i : sol.findClosestElements(data, k, x)) {
        cout << i << ' ';
    }

    return 0;
}