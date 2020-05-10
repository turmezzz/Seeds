//
// Find max sequence of ones if you need to delete one element
// 11011 -> 4
// 1110 -> 3
// 11 -> 1
//

#include <iostream>
#include <vector>

using namespace std;

int GetMaxOnesLength(const vector <int>& data) {
    if (data.empty()) {
        return 0;
    }
    bool haveZero = false;
    int prevOnesLength = 0;
    int currOnesLength = 0;
    int prevNumber = (data[0] + 1) % 2;
    int ret = 0;
    for (int i = 0; i < data.size(); ++i) {
        if (data[i] == 0) {
            haveZero = true;
            if (prevNumber == 0) {
                prevOnesLength = 0;
            } else if (prevNumber == 1) {
                ret = max(ret, prevOnesLength + currOnesLength);
                prevOnesLength = currOnesLength;
                currOnesLength = 0;
            }
        } else if (data[i] == 1) {
            ++currOnesLength;
        }
        prevNumber = data[i];
    }
    ret = max(ret, prevOnesLength + currOnesLength);

    if (not haveZero) {
        --ret;
    }
    return ret;
}

bool Test() {
    {
        vector <int> data = {1, 1};
        if (GetMaxOnesLength(data) != 1) {
            return false;
        }
    }
    {
        vector <int> data = {1, 1, 0};
        if (GetMaxOnesLength(data) != 2) {
            return false;
        }
    }
    {
        vector <int> data = {1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1};
        if (GetMaxOnesLength(data) != 5) {
            return false;
        }
    }
    {
        vector <int> data = {1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0};
        if (GetMaxOnesLength(data) != 5) {
            return false;
        }
    }
    {
        vector <int> data = {0, 0, 0};
        if (GetMaxOnesLength(data) != 0) {
            return false;
        }
    }
    {
        vector <int> data = {1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1};
        if (GetMaxOnesLength(data) != 8) {
            return false;
        }
    }
    {
        vector <int> data = {};
        if (GetMaxOnesLength(data) != 0) {
            return false;
        }
    }
    {
        vector <int> data = {0, 1, 0, 0};
        if (GetMaxOnesLength(data) != 1) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test();

    return 0;
}
