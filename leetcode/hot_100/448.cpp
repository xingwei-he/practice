/**************************************
* He Xingwei, All Rights Reserved.
* Filename:448.cpp
* Date:2022-04-23 12:09:54
* Description:
**************************************/

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        if (nums.empty()) {
            return res;
        }
        unordered_set<int> nums_set;
        for (auto &i : nums) {
            nums_set.insert(i);
        }
        for (int i = 1; i <= nums.size(); i++) {
            if (nums_set.find(i) == nums_set.end()) {
                res.emplace_back(i);
            }
        }
        return res;
    }
};
