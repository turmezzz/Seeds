//
// Swap odd and even bits of number
//

#include <iostream>

using namespace std;

int SwapBits(int n) {
    int oddBits = -1431655766; // ...1010
    int evenBits = 1431655765; // ...0101
    return ((n & oddBits) >> 1) | ((n & evenBits) << 1);
}

bool Test() {
    {
        if (SwapBits(13) != 14) {
            return false;
        }
    }
    {
        if (SwapBits(0) != 0) {
            return false;
        }
    }
    {
        if (SwapBits(1) != 2) {
            return false;
        }
    }
    {
        if (SwapBits(1431655765) != -1431655766) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test();


    return 0;
}

