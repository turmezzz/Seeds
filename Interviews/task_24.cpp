#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::pair<int, int> FindMixedSubstr(const std::string& text, const std::string& line) {
    std::unordered_map<char, int> data;
    int non_zero = 0;

    for (char letter : line) {
        if (++data[letter] == 1) {
            ++non_zero;
        }
    }

    if (non_zero == 0) {
        return {0, line.size()};
    }

    for (int i = 0; i < text.size(); ++i) {
        if (i >= line.size()) {
            char old = text[i - line.size()];
            ++data[old];
            if (data[old] == 0) {
                --non_zero;
            } else if (data[old] == 1) {
                ++non_zero;
            }

        }

        char letter = text[i];
        --data[letter];
        if (data[letter] == 0) {
            --non_zero;
        } else if (data[letter] == -1) {
            ++non_zero;
        }

        if (non_zero == 0) {
            return {i - line.size() + 1, i + 1};
        }
    }
    return {-1, -1};
}

bool Test() {
    {
        std::string text = "abcdefg";
        std::string line = "edc";

        if (auto box = FindMixedSubstr(text, line); box != std::pair<int, int>{2, 5}) {
            std::cout << box.first << ' ' << box.second << std::endl;
            return false;
        }
    }
    {
        std::string text = "fgasdasdasdasedadadadasdedasdadscdasdasdasabcde";
        std::string line = "edc";

        if (auto box = FindMixedSubstr(text, line); box != std::pair<int, int>{44, 47}) {
            std::cout << box.first << ' ' << box.second << std::endl;
            return false;
        }
    }
    {
        std::string text = "abc";
        std::string line = "edc";

        if (auto box = FindMixedSubstr(text, line); box != std::pair<int, int>{-1, -1}) {
            std::cout << box.first << ' ' << box.second << std::endl;
            return false;
        }
    }
    {
        std::string text = "abc";
        std::string line = "";

        if (auto box = FindMixedSubstr(text, line); box != std::pair<int, int>{0, 0}) {
            std::cout << box.first << ' ' << box.second << std::endl;
            return false;
        }
    }
    return true;
}

int main() {

    std::cout << Test();

    return 0;
}