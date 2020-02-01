#include <iostream>

using namespace std;

bool IsPow3(uint64_t n) {
    uint64_t prev = 0;
    uint64_t curr = 1;

    while (curr < n) {
        prev = curr;
        curr *= 3;
        if (prev > curr) {
            return false;
        }
    }
    return curr == n;
}

int main() {
    cout << (IsPow3(0)) << endl;
    cout << (IsPow3(1)) << endl;
    cout << (IsPow3(2)) << endl;
    cout << (IsPow3(3)) << endl;
    cout << (IsPow3(18446744073709551615U)) << endl;
    cout << (IsPow3(9)) << endl;
    cout << (IsPow3(12)) << endl;
    cout << (IsPow3(81)) << endl;
    return 0;
}