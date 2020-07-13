//
// We have array which represents display and it's width (can be div by 8)
// One byte consists of 8 pixels
// Need to draw a horizontal line from (x1, y) to (x2, y)
//

#include <iostream>
#include <vector>

using namespace std;

void Show(const vector <unsigned char>& display, int width) {
    width /= 8;
    for (int i = 0; i < display.size(); ++i) {
        for (unsigned char j = 128; j > 0; j >>= 1) {
            cout << ((display[i] & j) == 0 ? 0 : 1);
        }
        cout << '|';
        if ((i + 1) % width == 0) {
            cout << endl;
        }
    }
}

// width - amount of pixels
void DrawHorizontalLine(vector <unsigned char>& display, int width,
                        int x1, int x2, int y) {
    width /= 8;
    ++x2;

    int heightShift = y * width;
    int x1Shift = x1 / 8;
    int x2Shift = x2 / 8;
    for (int i = x1Shift + bool(x1 % 8); i < x2Shift - not bool(x2 % 8); ++i) {
        display[heightShift + i] = 255;
    }

    if (int box = x1 % 8; box != 0) {
        display[heightShift + x1Shift] = 0;
        unsigned char pen = 0;
        for (int i = 0; i < 8 - box; ++i) {
            pen <<= 1;
            pen |= 1;
        }
        display[heightShift + x1Shift] |= pen;
    }
    if (int box = x2 % 8; box != 0) {
        display[heightShift + x2Shift] = 0;
        unsigned char pen = 0;
        for (int i = 0; i < 8 - box; ++i) {
            pen <<= 1;
            pen |= 1;
        }
        display[heightShift + x2Shift] |= ~pen;
    }
}

int main() {
    vector <unsigned char> display = {0, 0, 0,
                                      0, 0, 0,
                                      0, 0, 0};
    int width = 3 * 8;
    DrawHorizontalLine(display, width,
                       5, 17, 1);
    Show(display, width);
    return 0;
}

