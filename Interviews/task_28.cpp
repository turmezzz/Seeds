#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::pair<int, int> FindMixedSubstr(const std::string& text, const std::string& line) {
    if (line.empty()) {
        return {0, 0};
    }
    if (text.empty()) {
        return {-1, -1};
    }

    std::unordered_map<char, int> data;
    int positive_sum = 0;
    for (char letter : line) {
        ++data[letter];
        ++positive_sum;
    }

    int shift = line.size() + 2;

    for (int i = 0; i < text.size(); ++i) {
        if (i >= shift) {
            char old = text[i - shift];
            ++data[old];
            if (data[old] >= 1) {
                ++positive_sum;
            }
        }

        char letter = text[i];
        --data[letter];
        if (data[letter] >= 0) {
            --positive_sum;
        }

        if (positive_sum == 0) {
            return {std::max(i - shift + 1, 0), i + 1};
        }
    }
    return {-1, -1};
}

bool Test() {
    {
        std::string text = "abcdaabbсadac";
        std::string line = "aabc";

        if (auto box = FindMixedSubstr(text, line); box != std::pair<int, int>{0, 5}) {
            std::cout << box.first << ' ' << box.second << std::endl;
            return false;
        }
    }
    {
        std::string text = "fgasdasdasdasedadadadasdedasdadscdasdasdasabcde";
        std::string line = "edc";

        if (auto box = FindMixedSubstr(text, line); box != std::pair<int, int>{42, 47}) {
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
    {
        std::string text = "abxxaabbcadac";
        std::string line = "aabc";

        if (auto box = FindMixedSubstr(text, line); box != std::pair<int, int>{3, 9}) {
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