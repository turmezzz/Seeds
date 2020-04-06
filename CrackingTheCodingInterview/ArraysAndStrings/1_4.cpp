//
// Replace all spaces with %20
//

#include <algorithm>
#include <iostream>

using namespace std;

void FixSpaces(string& line) {
    int spacesAmount = 0;
    for (int i = 0; i < line.length(); ++i) {
        if (line[i] == ' ') {
            ++spacesAmount;
        }
    }
    for (int i = (int)line.length() - 1; i >= 0; --i) {
        if (line[i] == ' ') {
            --spacesAmount;
        }
        int newPosition = i + spacesAmount * 2;
        if (newPosition >= line.length()) {
            continue;
        }
        if (line[i] == ' ') {
            line[newPosition] = '%';
            line[newPosition + 1] = '2';
            line[newPosition + 2] = '0';
        } else {
            line[newPosition] = line[i];
        }
    }
}

bool Test() {
    {
        string a = "a bcd ef    ";
        string b = "a%20bcd%20ef";
        FixSpaces(a);
        if (a != b) {
            return false;
        }
    }
    {
        string a = "Mr John Smith    ";
        string b = "Mr%20John%20Smith";
        FixSpaces(a);
        if (a != b) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test() << endl;

    return 0;
}

