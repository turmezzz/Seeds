//
// Implement an algorithm to determine if a string have all unique characters.
// What if you cannot use additional data structures?
//

#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

bool OnlyUnique1(const string& line) {
    unordered_set <char> cnt;
    for (auto c : line) {
        if (auto it = cnt.find(c); it != cnt.end()) {
            return false;
        }
        cnt.insert(c);
    }
    return true;
}

bool OnlyUnique2(string line) {
    sort(line.begin(), line.end());
    for (int i = 0; i < (int)line.size() - 1; ++i) {
        if (line[i] == line[i + 1]) {
            return false;
        }
    }
    return true;
}

bool Test() {
    {
        string a = "abc";
        if (OnlyUnique1(a) != OnlyUnique2(a) or not OnlyUnique1(a)) {
            return false;
        }
    }
    {
        string a = "abb";
        if (OnlyUnique1(a) != OnlyUnique2(a) or OnlyUnique1(a)) {
            return false;
        }
    }
    {
        string a = "";
        if (OnlyUnique1(a) != OnlyUnique2(a) or not OnlyUnique1(a)) {
            return false;
        }
    }
    {
        string a = "hello there";
        if (OnlyUnique1(a) != OnlyUnique2(a) or OnlyUnique1(a)) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test() << endl;

    return 0;
}
