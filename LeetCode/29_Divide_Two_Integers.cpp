#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    std::pair<int64_t, int64_t> f(int64_t dividend, int64_t divider) {
        int64_t res = 1;
        while (dividend >= divider) {
            divider <<= 1;
            res <<= 1;
        }
        res >>= 1;
        divider >>= 1;
        return {res, dividend - divider};
    }

    int64_t divide(int64_t dividend, int64_t divisor) {
        int dividend_sign = dividend < 0 ? -1 : 1;
        int divisor_sign = divisor < 0 ? -1 : 1;

        if (dividend_sign == -1) {
            dividend = -dividend;
        }
        if (divisor_sign == -1) {
            divisor = -divisor;
        }

        int64_t res = 0;
        while (dividend >= divisor) {
            auto [box, remainder] = f(dividend, divisor);
            dividend = remainder;
            res += box;
        }

        if ((int(dividend_sign == -1) + int(divisor_sign == -1)) == 1) {
            res = -res;
        }

        if (res > INT32_MAX) {
            res = INT32_MAX;
        }
        if (res < INT32_MIN) {
            res = INT32_MIN;
        }

        return res;
    }
};

int main() {

    Solution sol;
    cout << sol.divide(-2147483648, -1);

    return 0;
}