#include <iostream>
#include <vector>

int lowerBound(const std::vector <int>& nums, int target) {
    int l = 0;
    int r = nums.size();
    while (l < r) {
        int m = l + (r - l) / 2;
        if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    if (l == nums.size() || nums[l] != target) {
        return -1;
    }

    return l;
}

int upperBound(const std::vector <int>& nums, int target) {
    int l = 0;
    int r = nums.size();
    while (l < r) {
        int m = l + (r - l) / 2;
        if (nums[m] <= target) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    if (l != 0) {
        --l;
    }

    if (l == nums.size() || nums[l] != target) {
        return -1;
    }

    return l;
}

std::vector <int> searchRange(std::vector <int>& nums, int target) {
    return {lowerBound(nums, target), upperBound(nums, target)};
}

bool test() {
    {
        std::vector <int> nums = {5, 7, 7, 8, 8, 10};
        int target = 8;
        auto actual = searchRange(nums, target);
        if (actual != std::vector <int> {3, 4}) {
            std::cout << actual[0] << ' ' << actual[1] << std::endl;
            return false;
        }
    }
    return true;
}

int main() {

    std::cout << test() << std::endl;

    return 0;
}