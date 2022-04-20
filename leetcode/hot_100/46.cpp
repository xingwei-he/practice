/**************************************
* He Xingwei, All Rights Reserved.
* Filename:46.cpp
* Date:2022-04-19 14:20:42
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
    	vector<vector<int>> res;
    	backtrack(nums, 0, res);
    	return res;
    }

    void backtrack(vector<int>& nums, int level, vector<vector<int>>& res) {
    	if (level == nums.size() - 1) { // 停止条件
    		res.emplace_back(nums);
    		return;
    	}
    	for (int i = level; i < nums.size(); i++) {
    		swap(nums[i], nums[level]);
    		backtrack(nums, level + 1, res);
    		swap(nums[i], nums[level]);
    	}
    }
};