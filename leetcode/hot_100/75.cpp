/**************************************
* He Xingwei, All Rights Reserved.
* Filename:75.cpp
* Date:2022-05-01 14:31:52
* Description:
**************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
    	if (nums.empty()) {
    		return;
    	}
    	int len = nums.size();
    	int p0 = 0, p2 = len - 1;
    	for (int i = 0; i <= p2; i++) {
    		while (i <= p2 && nums[i] == 2) {
    			swap(nums[i], nums[p2]);
    			p2--;
    		}
    		if (nums[i] == 0) {
    			swap(nums[i], nums[p0]);
    			p0++;
    		}
    	}
    	//return;
    }
};

int main() {
	vector<int> nums{2,0,1};
	Solution s;
	s.sortColors(nums);
	for (auto &i : nums) {
		cout << i << ",";
	}
	cout << endl;
	return 0;
}