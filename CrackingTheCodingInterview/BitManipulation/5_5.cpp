//
// How many bits you need to change in A to turn it into B
//

#include <iostream>

using namespace std;

int CountBitDiff(int a, int b) {
    int ret = 0;
    int box = a ^ b;
    while (box != 0) {
        ret += box & 1;
        box >>= 1;
    }
    return ret;
}

bool Test() {
    {
        if (CountBitDiff(31, 14) != 2) {
            return false;
        }
    }
    {
        if (CountBitDiff(31, 1) != 4) {
            return false;
        }
    }
    {
        if (CountBitDiff(31, 31) != 0) {
            return false;
        }
    }
    {
        if (CountBitDiff(0, 1) != 1) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test();

    return 0;
}

