//
// We have array of n elements with numbers from 0 to n] without only one value from [0, n].
// We can only fetch jth bit of A[i]
// Need to return missing number
// {0, 2} -> 1
//

#include <iostream>
#include <vector>

using namespace std;

int GetDelta(int n, int k) {
    if ((n + 1) % (2 * k) >= k) {
        return k - (n + 1) % k;
    } else {
        return (n + 1) % (2 * k);
    }
}

int GetMissingNumber(const vector <int>& data) {

    vector <int> zeroBits(32, 0);
    for (int value : data) {
        for (int i = 0; i < 30; ++i) {
            zeroBits[31 - i] += (((1 << i) & value) != 0 ? -1 : 1);
        }
    }

    int ret = 0;
    int k = 1;
    int n = data.size();
    for (int i = 0; i < 30; ++i) {
        if (zeroBits[31 - i] >= GetDelta(n, k)) {
            ret |= (1 << i);
        }
        k <<= 1;
    }
    return ret;
}

bool Test() {
    {
        vector <int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
        if (GetMissingNumber(data) != 0) {
            return false;
        }
    }
    {
        vector <int> data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12};
        if (GetMissingNumber(data) != 10) {
            return false;
        }
    }
    {
        vector <int> data = {0, 1, 2, 3, 5, 6, 7, 8, 9, 10, 11, 12};
        if (GetMissingNumber(data) != 4) {
            return false;
        }
    }
    {
        vector <int> data = {0, 2};
        if (GetMissingNumber(data) != 1) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test();

    return 0;
}