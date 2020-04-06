//
// Implement a function void reverse(char* str)
// in C or C++ which reverse a null-terminated string.
//

#include <iostream>
#include <cstring>

using namespace std;

void reverse(char* str) {
    int len = 0;
    for (; str[len] != '\0'; ++len);
    for (int i = 0; i < len / 2; ++i) {
        char box = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = box;
    }
}

bool Test() {
    {
        char* a = new char[4]{'a', 'b', 'c', '\0'};
        char* b = new char[4]{'c', 'b', 'a', '\0'};
        reverse(a);
        bool ret = true;
        if (strcmp(a, b) != 0) {
            ret = false;
        }
        delete[] a;
        delete[] b;
        if (not ret) {
            return false;
        }
    }
    {
        char* a = new char[3]{'a', 'b', '\0'};
        char* b = new char[3]{'b', 'a', '\0'};
        reverse(a);
        bool ret = true;
        if (strcmp(a, b) != 0) {
            ret = false;
        }
        delete[] a;
        delete[] b;
        if (not ret) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test() << endl;

    return 0;
}
