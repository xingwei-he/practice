#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range;
        if (nums.empty() || target < nums.front() || target > nums.back()) {
            range.emplace_back(-1);
            range.emplace_back(-1);
            return range;
        }
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        // 第一轮确定左端点
        while (left < right) {
            mid = (left + right) / 2;
            if (target <= nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (target != nums[left]) {
            return vector<int>({-1, -1});
        }
        range.emplace_back(left);
        left = 0;
        right = nums.size() - 1;
        // 第二轮确定右端点
        while (left < right) {
            mid = (left + right) / 2;
            if (target >= nums[mid]) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        range.emplace_back(left);
        return range;
    }
};

int main() {
    vector<int> nums{5,7,7,8,8,10};
    int target = 8;
    Solution s;
    auto v = s.searchRange(nums, target);
    for (auto &n : v) {
        cout << n << " ";
    }
    return 0;
}