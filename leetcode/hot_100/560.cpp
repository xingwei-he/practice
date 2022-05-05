/**************************************
* He Xingwei, All Rights Reserved.
* Filename:560.cpp
* Date:2022-05-04 11:44:37
* Description:
**************************************/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    	unordered_map<int, int> pre_map;
    	pre_map[0] = 1;
    	int pre = 0; // 表示 [0, i] 的和
    	int counter = 0;
    	for (auto &n : nums) {
    		pre += n; // pre 记录了从头到当前值 n 的和
    		if (pre_map.find(pre - k) != pre_map.end()) {
    			// 此处逻辑的含义
    			// 通过 pre - k 将 nums 分成两段，即以当前值 n 作为子数组的最后一个数
    			// 前面一个子数组和为 pre - k，后面一段子数组和为 k
    			// 如果 pre - k，记录过，就可以知道，后面的子数组是一个ok的结果
    			counter += pre_map[pre - k];
    		}
    		pre_map[pre]++;
    	}
    	return counter;
    }
};

int main() {
    vector<int> nums{3,4,7,2,-3,1,4,2};
    int k = 7;
    Solution s;
    int res = s.subarraySum(nums, k);
    cout << res << endl;
    return 0;
}
