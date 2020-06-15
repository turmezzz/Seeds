//
// Insert M from i to j into N
//

#include <iostream>

using namespace std;

int InsertMToN(int n, int m, int first, int last) {
    int box = 1;
    box <<= (last - first + 1);
    --box;
    box <<= first;
    m &= box;
    n |= m;
    return n;
}

bool Test() {
    {
        if (InsertMToN(64, 16 + 8 + 2 + 1, 1, 3) != 74) {
            return false;
        }
    }
    {
        if (InsertMToN(0, 16 + 8 + 2 + 1, 1, 3) != 10) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test();

    return 0;
}

