/**************************************
* He Xingwei, All Rights Reserved.
* Filename:1.cpp
* Date:2022-04-17 23:19:43
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_dict;
        vector<int> res(2, -1);
        for (int i = 0; i < nums.size(); i++) {
            int temp = target - nums[i];
            if (num_dict.find(temp) != num_dict.end()) {
                res[0] = num_dict[temp];
                res[1] = i;
            } else {
                num_dict[nums[i]] = i;
            }
        }
        return res;
    }
};
