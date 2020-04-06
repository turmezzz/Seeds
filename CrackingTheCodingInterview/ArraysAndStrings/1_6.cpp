//
// Rotate mtx by 90 degrees
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

pair <int, int> NormalizeCoord(int row_i, int col_i, int n_i) {
    int delta = n_i / 2;
    int shift = (n_i + 1) % 2;

    int row = row_i - delta;
    if (row_i >= delta) {
        row += shift;
    }
    row *= -1;

    int col = col_i - delta;
    if (col_i >= delta) {
        col += shift;
    }

    return {row, col};
}

pair <int, int> Translate(int row_i, int col_i) {
    int col = 0 * col_i + 1 * row_i;
    int row = -1 * col_i + 0 * row_i;
    return {row, col};
}

pair <int, int> DenormalizeCoord(int row_i, int col_i, int n_i) {
    int delta = n_i / 2;
    int shift = (n_i + 1) % 2;

    int row = -1 * row_i + delta;
    if (row >= delta) {
        row -= shift;
    }

    int col = col_i + delta;
    if (col >= delta) {
        col -= shift;
    }

    return {row, col};
}

void RotateSquareMtx(vector <vector <int>>& data, int n) {

    auto processCoords = [](int row, int col, int n) {
        auto box = NormalizeCoord(row, col, n);
        box = Translate(box.first, box.second);
        return DenormalizeCoord(box.first, box.second, n);
    };

    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n / 2 + n % 2; ++j) {
            pair <int, int> pairA = {i, j};
            pair <int, int> pairB = processCoords(pairA.first, pairA.second, n);
            pair <int, int> pairC = processCoords(pairB.first, pairB.second, n);
            pair <int, int> pairD = processCoords(pairC.first, pairC.second, n);

            vector <pair <int, int>> coords = {pairA, pairB, pairC, pairD};
            vector <int> values(4);
            for (int u = 0; u < 4; ++u) {
                values[u] = data[coords[u].first][coords[u].second];
            }
            for (int u = 0; u < 4; ++u) {
                int from = (u + 3) % 4;
                int toRow = coords[u].first;
                int toCol = coords[u].second;
                data[toRow][toCol] = values[from];
            }
        }
    }

}

bool Test() {
    {
        // norm

        int row = 1;
        int col = 1;
        int n = 4;

        auto box = NormalizeCoord(row, col, n);
        if (box.first != 1 or box.second != -1) {
            return false;
        }
    }
    {
        int row = 3;
        int col = 3;
        int n = 4;

        auto box = NormalizeCoord(row, col, n);
        if (box.first != -2 or box.second != 2) {
            return false;
        }
    }
    {
        // translate
        int row = 1;
        int col = -1;

        auto box = Translate(row, col);
        if (box.first != 1 or box.second != 1) {
            return false;
        }
    }
    {
        // translate
        int row = -1;
        int col = 1;

        auto box = Translate(row, col);
        if (box.first != -1 or box.second != -1) {
            return false;
        }
    }
    {
        // denorm

        int row = 1;
        int col = 1;
        int n = 4;

        auto box = DenormalizeCoord(row, col, n);
        if (box.first != 1 or box.second != 2) {
            return false;
        }
    }
    {
        // denorm

        int row = -1;
        int col = -1;
        int n = 4;

        auto box = DenormalizeCoord(row, col, n);
        if (box.first != 2 or box.second != 1) {
            return false;
        }
    }
    {
        vector <vector <int>> a = {{1, 2},
                                   {3, 4}};
        vector <vector <int>> b = {{3, 1},
                                   {4, 2}};
        RotateSquareMtx(a, a.size());
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

