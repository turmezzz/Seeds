#include <algorithm>
#include <array>
#include <iostream>

using namespace std;

namespace Tools_NS {
    constexpr array <int, 32> Init() {
        array <int, 32> data = {};
        int value = 1;
        for (int i = 0; i < 32; ++i) {
            data[i] = value;
            value <<= 1;
        }
        return data;
    }

    static constexpr auto sym_2_bits = Init();

}

int main() {
    return 0;
}

