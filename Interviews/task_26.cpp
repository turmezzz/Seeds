#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cctype>

void ReverseWord(std::string& line, int begin, int end) {
    for (; begin < end; (++begin, --end)) {
        std::swap(line[begin], line[end]);
    }
}

void ReverseWords(std::string& line) {
    for (int i = 0; i != line.size(); ++i) {
        if (isspace(line[i])) {
            continue;
        }
        int j = i;
        while (j != line.size() && !std::isspace(line[j])) {
            ++j;
        }
        ReverseWord(line, i, j - 1);
        i = j - 1;
    }
}

bool Test() {
    {
        std::string data = "QUICK FOX JUMPS";
        std::string expected = "KCIUQ XOF SPMUJ";
        if (ReverseWords(data); data != expected) {
            std::cout << "data: " << data << std::endl;
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