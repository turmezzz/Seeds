#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cctype>

std::string ZoomLine(const std::string& line, const int width) {
    if (line.size() >= width) {
        return line;
    }

    std::vector<std::string> words;
    words.emplace_back("");

    for (int i = 0; i != line.size(); ++i) {
        if (!isspace(line[i])) {
            words.back() += line[i];
        } else if (isspace(line[i]) && !words.back().empty()) {
            words.emplace_back("");
        }
    }

    std::string zoomed_line;
    auto need_to_add = width - line.size() + words.size() - 1;
    if (words.size() == 1) {
        zoomed_line += words[0];
        for (int i = 0; i < need_to_add; ++i) {
            zoomed_line += ' ';
        }
        return zoomed_line;
    }

    int common = need_to_add / (words.size() - 1);
    need_to_add %= (words.size() - 1);
    for (int word_id = 0; word_id < words.size() - 1; ++word_id) {
        auto&& word = std::move(words[word_id]);
        zoomed_line += word;
        for (int i = 0; i < common; ++i) {
            zoomed_line += ' ';
        }
        if (need_to_add != 0) {
            zoomed_line += ' ';
            --need_to_add;
        }
    }
    zoomed_line += words.back();
    return zoomed_line;
}

bool Test() {
    {
        std::string data = "enough to explain to";
        std::string expected = "enough to explain to";
        if (auto actually = ZoomLine(data, 20); actually != expected) {
            std::cout << "width: " << 20 << std::endl;
            std::cout << "actually: " << actually << std::endl;
            std::cout << "expected: " << expected << std::endl;
            return false;
        }
    }
    {
        std::string data = "enough to explain to";
        std::string expected = "enough  to  explain  to";
        if (auto actually = ZoomLine(data, 23); actually != expected) {
            std::cout << "width: " << 23 << std::endl;
            std::cout << "actually: " << actually << std::endl;
            std::cout << "expected: " << expected << std::endl;
            return false;
        }
    }
    {
        std::string data = "enough to explain to";
        std::string expected = "enough   to   explain  to";
        if (auto actually = ZoomLine(data, 25); actually != expected) {
            std::cout << "width: " << 25 << std::endl;
            std::cout << "actually: " << actually << std::endl;
            std::cout << "expected: " << expected << std::endl;
            return false;
        }
    }
    {
        std::string data = "do";
        std::string expected = "do   ";
        if (auto actually = ZoomLine(data, 5); actually != expected) {
            std::cout << "width: " << 25 << std::endl;
            std::cout << "actually: " << actually << std::endl;
            std::cout << "expected: " << expected << std::endl;
            return false;
        }
    }
    return true;
}

int main() {

    std::cout << Test() << std::endl;

    return 0;
}