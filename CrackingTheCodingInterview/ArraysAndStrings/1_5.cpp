//
// aabcccccaaa -> a2b1c5a3
//

#include <algorithm>
#include <iostream>

using namespace std;

string CompressString(const string& line) {
    char symbol = 0;
    int cnt = 0;
    string ret;
    for (int i = 0; i < line.length();) {
        symbol = line[i];
        cnt = 0;
        for (; i < line.length() and line[i] == symbol; (++i, ++cnt));
        ret += symbol;
        ret += to_string(cnt);
    }
    return (ret.length() < line.length() ? ret : line);
}

bool Test() {
    {
        string a = "abc";
        string b = "abc";
        if (CompressString(a) != b) {
            return false;
        }
    }
    {
        string a = "aabbcc";
        string b = "aabbcc";
        if (CompressString(a) != b) {
            return false;
        }
    }
    {
        string a = "aaabbcc";
        string b = "a3b2c2";
        if (CompressString(a) != b) {
            return false;
        }
    }
    {
        string a = "aaa";
        string b = "a3";
        if (CompressString(a) != b) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test() << endl;

    return 0;
}

