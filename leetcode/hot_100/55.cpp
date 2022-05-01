/**************************************
* He Xingwei, All Rights Reserved.
* Filename:55.cpp
* Date:2022-04-30 23:16:18
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }
        int n = nums.size();
        int furthest = 0;
        for (int i = 0; i < n; i++) {
            furthest = max(furthest, nums[i] + i);
            if (furthest >= n - 1) {
                return true;
            }
            if (furthest <= i) {
                return false;
            }
        }
        return false;
    }
};