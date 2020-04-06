//
// If one element of mtx is zero entire col and row are set to 0
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void Solve(vector <vector <int>>& data, int n, int m) {
    vector <bool> rowsForCleaning(n, false);
    vector <bool> colsForCleaning(m, false);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (data[i][j] == 0) {
                rowsForCleaning[i] = true;
                colsForCleaning[j] = true;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (rowsForCleaning[i] or colsForCleaning[j]) {
                data[i][j] = 0;
            }
        }
    }
}

bool Test() {
    {
        vector <vector <int>> a = {{},
                                   {},
                                   {}};
        vector <vector <int>> b = {{},
                                   {},
                                   {}};
        Solve(a, 3, 0);
        if (a != b) {
            return false;
        }
    }
    {
        vector <vector <int>> a = {{1, 2, 3},
                                   {4, 0, 6},
                                   {7, 8, 0}};
        vector <vector <int>> b = {{1, 0, 0},
                                   {0, 0, 0},
                                   {0, 0, 0}};
        Solve(a, 3, 3);
        if (a != b) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test() << endl;

    return 0;
}

