/**************************************
* He Xingwei, All Rights Reserved.
* Filename:494.cpp
* Date:2022-04-20 20:12:14
* Description:
**************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void get_sum_way(const vector<int>& nums, int target, int sum, int index, int& counter) {
		if (index == nums.size()) {
			if (sum == target) { // 结果OK
				counter++;
			}
			return;
		}
		
		// + nums[index]
		get_sum_way(nums, target, sum + nums[index], index + 1, counter);
		// - nums[index]
		get_sum_way(nums, target, sum - nums[index], index + 1, counter);
	}

    int findTargetSumWays(vector<int>& nums, int target) {
    	if (nums.empty()) {
    		return 0;
    	}
    	int counter = 0;
    	int sum = 0;
    	get_sum_way(nums, target, sum, 0, counter);
    	return counter;
    }
};

int main () {
	vector<int> nums{1,1,1,1,1};
	int target = 3;
	Solution s;
	int res = s.findTargetSumWays(nums, target);
	cout << res << endl;
	return 0;
}
