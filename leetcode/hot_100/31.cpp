/**************************************
* He Xingwei, All Rights Reserved.
* Filename:31.cpp
* Date:2022-04-24 17:19:44
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	if (nums.size() <= 1) {
    		return;
    	}
    	int i = nums.size() - 2;
    	while (i >= 0 && nums[i] >= nums[i + 1]) { // i指向第一个逆序对
    		i--;
    	}
    	if (i >= 0) {
    		int j = nums.size() - 1;
    		while (j > i && nums[i] >= nums[j]) {
    			j--;
    		}
    		swap(nums[i], nums[j]);
    	}
    	reverse(nums.begin() + i + 1, nums.end());
    }
};