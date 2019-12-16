#include <iostream>
#include <string>

using namespace std;

void NormSpace(string& line) {
    int spaces = 0;
    int words = 0;
    char prev_symbol = 'a';
    for (int i = 0; i < line.length(); ++i) {
        if (line[i] == ' ') {
            ++spaces;
            prev_symbol = line[i];
        } else {
            if (prev_symbol == ' ') {
                ++words;
            }
            prev_symbol = line[i];
            swap(line[i], line[i - spaces + words]);
        }
    }
    int pop_spaces = spaces - (int)(line[0] == ' ') - (words - 1) - (int)(line[line.length() - 1] == ' ') - 1;
    for (int i = 0; i < pop_spaces; ++i) {
        line.pop_back();
    }
}

int main() {
    {
        string line = "a ab  abcd ";
        NormSpace(line);
        cout << line << endl;
    }
    {
        string line = " a ab  abcd ";
        NormSpace(line);
        cout << line << endl;
    }
    {
        string line = "   a ab  abcd    ";
        NormSpace(line);
        cout << line << endl;
    }
    {
        string line = "  ";
        NormSpace(line);
        cout << line << endl;
    }
    {
        string line = " a ";
        NormSpace(line);
        cout << line << endl;
    }

    return 0;
}