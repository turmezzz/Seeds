#include <iostream>
#include <vector>
#include <queue>

int CalcTime(int servers_amount, const std::vector<int>& images_meta) {
    std::priority_queue<int, std::vector<int>, std::greater<>>servers_timestamps;
    for (int i = 0; i < servers_amount; ++i) {
        servers_timestamps.push(0);
    }

    for (const auto time : images_meta) {
        auto min_time = servers_timestamps.top();
        servers_timestamps.pop();
        servers_timestamps.push(min_time + time);
    }
    int ret = 0;
    while (!servers_timestamps.empty()) {
        ret = servers_timestamps.top();
        servers_timestamps.pop();
    }
    return ret;
}

bool Test() {
    {
        std::vector<int> images_meta = {1, 2, 3, 3};
        int n = 2;
        if (CalcTime(n, images_meta) != 5) {
            return false;
        }
    }
    {
        std::vector<int> images_meta = {1, 1, 1, 1};
        int n = 1;
        if (CalcTime(n, images_meta) != 4) {
            return false;
        }
    }
    {
        std::vector<int> images_meta = {6, 1, 1, 1};
        int n = 2;
        if (CalcTime(n, images_meta) != 6) {
            return false;
        }
    }

    return true;
}

int main() {

    std::cout << Test() << std::endl;

    return 0;
}