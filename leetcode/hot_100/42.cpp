#include <iostream>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int volume = 0;
        int left = 0, right = height.size() - 1;
        int left_max_hegiht = 0, right_max_height = 0;
        while (left < right) {
            left_max_hegiht = max(left_max_hegiht, height[left]);
            right_max_height = max(right_max_height, height[right]);
            if (height[left] < height[right]) {
                // 如果 height[left] < height[right]
                // 则有 left_max_height <= right_max_height
                // 从低的一边开始缩小范围
                volume += left_max_hegiht - height[left];
                left++;
            } else {
                volume += right_max_height - height[right];
                right--;
            }
        }
        return volume;
    }
};