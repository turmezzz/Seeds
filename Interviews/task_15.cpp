#include <iostream>

using namespace std;

bool IsPalindrome(const string& line) {
    if (line.size() <= 1) {
        return true;
    }
    auto left_it = line.begin();
    auto right_it = line.end();
    --right_it;
    while (left_it < right_it) {
        while (left_it != line.end() and not isalpha(*left_it)) {
            ++left_it;
        }
        while (right_it != line.begin() and not isalpha(*right_it)) {
            --right_it;
        }
        if (left_it > right_it) {
            return true;
        }
        if (tolower(*left_it) != tolower(*right_it)) {
            return false;
        }
        ++left_it;
        --right_it;
    }
    return true;
}

int main() {
    cout << (IsPalindrome("Kazak")) << endl;
    cout << (IsPalindrome("Do geese see god")) << endl;
    cout << (IsPalindrome("abc")) << endl;
    cout << (IsPalindrome("ab c")) << endl;
    cout << (IsPalindrome("ab cba")) << endl;
    cout << (IsPalindrome("abc c !b ?a")) << endl;
    cout << (IsPalindrome("")) << endl;
    cout << (IsPalindrome("   ?!@?!@#")) << endl;
    return 0;
}