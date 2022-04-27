/**************************************
* He Xingwei, All Rights Reserved.
* Filename:136.cpp
* Date:2022-04-24 16:48:59
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	unordered_map<int, int> nums_count;
    	for (auto &i : nums) {
    		nums_count[i] += 1;
    	}
    	for (auto iter = nums_count.begin(); iter != nums_count.end(); iter++) {
    		if (iter->second == 1) {
    			return iter->first;
    		}
    	}
    	return 0;
    }
};