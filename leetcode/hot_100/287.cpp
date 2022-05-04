/**************************************
* He Xingwei, All Rights Reserved.
* Filename:287.cpp
* Date:2022-05-05 00:00:54
* Description:
**************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int p1 = 0, p2 = 0; // 快慢指针
        do {
            p1 = nums[p1]; // 慢指针走一步
            p2 = nums[nums[p2]]; // 快指针走两步
        } while(nums[p1] != nums[p2]);
        p2 = 0;
        while (nums[p1] != nums[p2]) {
            p1 = nums[p1];
            p2 = nums[p2];
        }
        return nums[p1];
    }
};

int main() {
    vector<int> nums{1,3,4,2,2};
    Solution s;
    int n = s.findDuplicate(nums);
    cout << n << endl;
    return 0;
}