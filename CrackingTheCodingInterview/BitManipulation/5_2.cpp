//
// Show double as bin
// Actually some shit here, I am sure that this code is incorrect
// I guess I misunderstood task
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void GetIntAsBin(int data, string& ret) {
    if (data >= 1) {
        ret += char(data % 2 + '0');
        GetIntAsBin(data / 2, ret);
    } else if (data == 1) {
        ret += '1';
    }
}

void ShowDoubleAsBin(double data) {
    int aValue = int(data);
    int bValue = 0;
    string line = to_string(data - aValue);
    while (line.back() == '0') {
        line.pop_back();
    }
    for (int i = 2; i < line.length(); ++i) {
        bValue *= 10;
        bValue += line[i] - '0';
    }
    int orderSize = 0;
    for (int i = aValue; i != 0; i /= 10) {
        ++orderSize;
    }

    string box;
    cout << "0,";
    box = "";
    GetIntAsBin(aValue, box);
    reverse(box.begin(), box.end());
    cout << box;
    box = "";
    GetIntAsBin(bValue, box);
    reverse(box.begin(), box.end());
    cout << box;
    cout << " * 10^" << orderSize << endl;
}

int main() {

    ShowDoubleAsBin(41.15);

    return 0;
}

