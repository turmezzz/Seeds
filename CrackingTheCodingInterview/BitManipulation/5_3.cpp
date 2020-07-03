//
// You have a number. Return next smallest and next largest number
// with same amount of 1 bits in binary representation
//

#include <iostream>
#include <tuple>

using namespace std;

pair <int , int> GetNext(int n) {
    // 10110001010100
    // 11111100000000
    // 10110001011000

    // first - smallest
    // second - largest
    pair <int, int> ret = {0, 0};
    if (n == 0) {
        return ret;
    }

    int size = 0;
    int trueAmount = 0;
    int falseAmount = 0;
    for (int i = n; i != 0; (++size, i >>= 1)) {
        if (i % 2 == 0) {
            ++falseAmount;
        } else {
            ++trueAmount;
        }
    }
    ret.first = 1;
    for (int i = 0; i < trueAmount - 1; ++i) {
        ret.first <<= 1;
        ret.first += 1;
    }
    ret.first <<= falseAmount;

    int firstTrueIndex = 0;
    int box = 1;
    while (((box << firstTrueIndex) & n) == 0) {
        ++firstTrueIndex;
    }
    int falseIndex = firstTrueIndex;
    while (((box << falseIndex) & n) != 0) {
        ++falseIndex;
    }

    ret.second = n;

    box = 1;
    box <<= firstTrueIndex;
    ret.second = ret.second & ~box;

    box = 1;
    box <<= falseIndex;
    ret.second = ret.second | box;


    return ret;
}

bool Test() {
    {
        auto box = GetNext(42);
        if (box.first != 56 and box.second != 44) {
            return false;
        }
    }
    {
        auto box = GetNext(5);
        if (box.first != 6 and box.second != 6) {
            return false;
        }
    }
    {
        auto box = GetNext(10);
        if (box.first != 12 and box.second != 12) {
            return false;
        }
    }
    {
        auto box = GetNext(0);
        if (box.first != 0 and box.second != 0) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test();

    return 0;
}

