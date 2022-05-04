/**************************************
* He Xingwei, All Rights Reserved.
* Filename:581.cpp
* Date:2022-05-04 10:48:46
* Description:
**************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        int min_num = nums[len - 1];
        int max_num = nums[0];
        int begin = 0, end = -1;
        for (int i = 0; i < len; i++) {
            if (nums[i] < max_num) {
                end = i;
            } else {
                max_num = nums[i];
            }
            if (nums[len - i - 1] > min_num) {
                begin = len - i - 1;
            } else {
                min_num = nums[len - i - 1];
            }
            cout << begin << "\t" << end << endl;
        }
        return end - begin + 1;
    }
};

int main() {
    vector<int> nums{2,6,4,8,10,9,15};
    Solution s;
    int res = s.findUnsortedSubarray(nums);
    cout << res << endl;
}