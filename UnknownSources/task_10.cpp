#include <iostream>
#include <vector>

using namespace std;

int DeleteZeros(vector <int>& data) {
    int zeros_amount = 0;
    for (int i = 0 ; i < data.size(); ++i) {
        if (data[i] == 0) {
            ++zeros_amount;
        } else {
            swap(data[i], data[i - zeros_amount]);
        }
    }
    return data.size() - zeros_amount;
}

void Show(vector <int>& data) {
    for (int i : data) {
        cout << i << ' ';
    }
    cout << endl;
}

int main() {
    {
        vector <int> data = {1, 2, 0, 3, 0, 0, 5};
        cout << DeleteZeros(data) << endl;
        Show(data);
    }
    {
        vector <int> data = {1, 2, 3, 5};
        cout << DeleteZeros(data) << endl;
        Show(data);
    }
    {
        vector <int> data = {};
        cout << DeleteZeros(data) << endl;
        Show(data);
    }
    {
        vector <int> data = {0, 0, 0};
        cout << DeleteZeros(data) << endl;
        Show(data);
    }
    return 0;
}