#include <iostream>
#include <vector>

using std::cerr;
using std::vector;

struct MatrixForFib {
    int a11, a12;
    int a21, a22;

    MatrixForFib() : a11(1), a12(1),
                     a21(1), a22(0) {
    }
};

MatrixForFib operator*(const MatrixForFib &a,
                       const MatrixForFib &b) {
    MatrixForFib box;
    box.a11 = a.a11 * b.a11 + a.a12 * b.a21;
    box.a12 = a.a11 * b.a12 + a.a12 * b.a22;
    box.a21 = a.a21 * b.a11 + a.a22 * b.a21;
    box.a22 = a.a21 * b.a12 + a.a22 * b.a22;
    return box;
}

MatrixForFib LogPow(MatrixForFib a, int n) {
    if (n == 0) {
        return MatrixForFib();
    } else if (n == 1){
        return a;
    }
    auto box = LogPow(a, n / 2);
    box = box * box;
    if (n % 2 == 1) {
        box = box * a;
    }
    return box;
}

int NthFib(int n) {
    MatrixForFib mtx;
    return LogPow(mtx, n).a11;
}

// Main idea is din pow of mtx
// 1 1
// 1 0

int main() {
    vector<int> in = {0, 1, 2, 3, 4, 5, 6, 7};
    vector<int> out = {1, 1, 2, 3, 5, 8, 13, 21};

    for (int i = 0; i < in.size(); ++i) {
        auto box = NthFib(in[i]);
        if (out[i] != box) {
            std::cerr << "Have: " << box
                      << " Expected: " << out[i]
                      << std::endl;
        }
    }
    return 0;
}