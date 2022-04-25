#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int n = nums.size();
        if (1 == n) {
            if (target == nums[0]) {
                return 0;
            } else {
                return -1;
            }
        }
        int left = 0, right = n - 1, mid = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (target == nums[mid]) {
                return mid;
            }
            if (nums[left] <= nums[mid]) { // [left, mid] 有序
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else { // [mid, right] 有序
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};


int main() {
    vector<int> nums{3,1};
    int target = 1;
    Solution s;
    int pos = s.search(nums, target);
    cout << pos << endl;
    return 0;
}