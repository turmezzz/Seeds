//
// Given two strings, write a method to decide if one is a permutation of another.
//

#include <iostream>
#include <unordered_map>

using namespace std;

bool IsPermutation(const string& source, const string& line) {
    unordered_map <char, int> cnt;
    int checkSum = 0;

    for (auto c : source) {
        ++cnt[c];
        ++checkSum;
    }

    for (auto c : line) {
        if (auto it = cnt.find(c); it != cnt.end() and it->second != 0) {
            --it->second;
            --checkSum;
        } else {
            return false;
        }
    }
    return checkSum == 0;
}

bool Test() {
    {
        string a = "abc";
        string b = "abc";
        if (not IsPermutation(a, b)) {
            return false;
        }
    }
    {
        string a = "abc";
        string b = "bac";
        if (not IsPermutation(a, b)) {
            return false;
        }
    }
    {
        string a = "abc";
        string b = "gbc";
        if (IsPermutation(a, b)) {
            return false;
        }
    }
    {
        string a = "abc";
        string b = "abcxx";
        if (IsPermutation(a, b)) {
            return false;
        }
    }
    {
        string a = "abcxx";
        string b = "abc";
        if (IsPermutation(a, b)) {
            return false;
        }
    }
    {
        string a = "axbxc";
        string b = "abcxxxx";
        if (IsPermutation(a, b)) {
            return false;
        }
    }
    {
        string a = "axbxcxxxx";
        string b = "abcxxxx";
        if (IsPermutation(a, b)) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test() << endl;

    return 0;
}
