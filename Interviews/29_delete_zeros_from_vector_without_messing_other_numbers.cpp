#include <iostream>
#include <vector>

using namespace std;

void cutZeros(vector<int>& data) {
    if (data.empty()) {
        return;
    }

    auto zeroIt = data.begin();
    auto numberIt = zeroIt;

    while (zeroIt != data.end()) {
        while (zeroIt != data.end() && *zeroIt != 0) {
            ++zeroIt;
        }
        numberIt = max(zeroIt, numberIt);
        while (numberIt != data.end() && *numberIt == 0) {
            ++numberIt;
        }
        if (numberIt == data.end()) {
            break;
        } else {
            swap(*zeroIt, *numberIt);
        }
    }
    data.resize(zeroIt - data.begin());
}

bool test() {
    {
        vector <int> data = {1, 0, 4, 0, 1, 1};
        cutZeros(data);
        if (data != vector<int>{1, 4, 1, 1}) {
            return false;
        }
    }
    {
        vector <int> data = {};
        cutZeros(data);
        if (data != vector<int>{}) {
            return false;
        }
    }
    {
        vector <int> data = {0, 0};
        cutZeros(data);
        if (data != vector<int>{}) {
            return false;
        }
    }
    {
        vector <int> data = {1, 0, 0};
        cutZeros(data);
        if (data != vector<int>{1}) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << test();
}