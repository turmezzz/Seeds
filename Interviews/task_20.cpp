#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


string FindSubstr(const string& text, const string& s) {
    unordered_map <char, int> symbols_cnt;
    int zeros = 0;
    for (auto i : s) {
        ++symbols_cnt[i];
    }

    for (int i = 0; i < text.length(); ++i) {
        // add new symbol
        auto new_sym_it = symbols_cnt.find(text[i]);
        if (new_sym_it != symbols_cnt.end()) {
            --new_sym_it->second;
            if (new_sym_it->second == 0) {
                ++zeros;
            }
            if (new_sym_it->second == -1) {
                --zeros;
            }
        }

        // pop old symbol
        if (i - s.length() >= 0) {
            auto old_sym_it = symbols_cnt.find(text[i - s.length()]);
            if (old_sym_it != symbols_cnt.end()) {
                ++old_sym_it->second;
                if (old_sym_it->second == 0) {
                    ++zeros;
                }
                if (old_sym_it->second == 1) {
                    --zeros;
                }
            }
        }

        if (zeros == s.length()) {
            return text.substr(i - s.length() + 1, s.length());
        }
    }
    return "";
}


int main() {
    {
        string text = "ayxzb";
        string s = "xyz";
        cout << FindSubstr(text, s) << endl;
    }
    {
        string text = "axyxzb";
        string s = "xyz";
        cout << FindSubstr(text, s) << endl;
    }
    {
        string text = "axxyyzxb";
        string s = "xyz";
        cout << FindSubstr(text, s) << endl;
    }
    {
        string text = "axxyyzzxffyb";
        string s = "xyz";
        cout << FindSubstr(text, s) << endl;
    }
    {
        string text = "";
        string s = "xyz";
        cout << FindSubstr(text, s) << endl;
    }
    {
        string text = "xyz";
        string s = "xyz";
        cout << FindSubstr(text, s) << endl;
    }


    return 0;
}