#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

void IsValid(char letter) {
    if (!('A' <= letter && letter <= 'Z')) {
        throw std::invalid_argument("invalid letter");
    }
}

std::string RLECompression(const std::string& text) {
    std::string compressed_text;
    for (int i = 0; i < text.size(); ++i) {
        IsValid(text[i]);
        compressed_text += text[i];
        int amount = 1;
        for (; text[i] == text[i + amount]; ++amount) {
            IsValid(text[i]);
        }
        if (amount != 1) {
            compressed_text += std::to_string(amount);
        }
        i += amount - 1;
    }
    return compressed_text;
}

bool Test() {
    {
        std::string text = "AAAABBBCCXYZDDDDEEEFFFAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBB";
        if (auto out = RLECompression(text); out != "A4B3C2XYZD4E3F3A6B28") {
            std::cout << out << std::endl;
            return false;
        }
    }
    {
        std::string text = "AAAB";
        if (auto out = RLECompression(text); out != "A3B") {
            std::cout << out << std::endl;
            return false;
        }
    }
    {
        std::string text = "AAAb";
        try {
            RLECompression(text);
            return false;
        } catch (...) {
        }
    }
    {
        std::string text = "b";
        try {
            RLECompression(text);
            return false;
        } catch (...) {
        }
    }
    return true;
}

int main() {

    std::cout << Test() << std::endl;

    return 0;
}