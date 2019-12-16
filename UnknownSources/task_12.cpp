#include <iostream>
#include <vector>

using namespace std;

size_t MaxGuests(vector <pair <int, int>>& data) {
    auto box = vector <pair <int, int>>(data.size() * 2);
    auto it = box.begin();
    for (auto[in, out] : data) {
        it->first = in;
        it->second = 1;
        ++it;

        it->first = out;
        it->second = 0;
        ++it;
    }
    sort(box.begin(), box.end());

    int max_guests = 0;
    int cur_guest = 0;
    for (auto[day, status] : box) {
        if (status == 1) {
            // new guest
            ++cur_guest;
        } else {
            // guest leaves
            --cur_guest;
        }
        max_guests = max(max_guests, cur_guest);
    }
    return max_guests;
}

int main() {
    {
        vector <pair <int, int>> data = {{1, 5}, {5, 7}, {6, 10}};
        cout << (MaxGuests(data) == 2) << endl;
    }
    {
        vector <pair <int, int>> data = {{1, 5}, {5, 10}};
        cout << (MaxGuests(data) == 1) << endl;
    }
    {
        vector <pair <int, int>> data = {{1, 2}, {1, 3}, {1, 4}};
        cout << (MaxGuests(data) == 3) << endl;
    }
    return 0;
}