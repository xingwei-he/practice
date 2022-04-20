/**************************************
* He Xingwei, All Rights Reserved.
* Filename:15.cpp
* Date:2022-04-18 22:16:58
* Description:
**************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	int n = nums.size();
    	if (n < 3) {
    		return vector<vector<int>>();
    	}
    	sort(nums.begin(), nums.end(),
    			[](int &x, int &y){
    				return x < y;
    			});
    	vector<vector<int>> res;
    	for (int i = 0; i <= n - 3; i++) {
    		int left = i + 1, right = n - 1;
    		if (nums[i] > 0) { // 如果最小的都已经大于0，则直接break
    			break;
    		}
    		if (i > 0 && nums[i] == nums[i - 1]) {
    			continue;
    		}
    		while (left < right) {
    			int sum = nums[i] + nums[left] + nums[right];
    			if (sum < 0) {
                    do {
                        left++;
                    } while (left < right && nums[left] == nums[left - 1]);
                } else if (sum > 0) {
                    do {
                        right--;
                    } while (left < right && nums[right] == nums[right + 1]);
    			} else { // sum == 0
    				res.emplace_back(vector<int>{nums[i], nums[left], nums[right]});
                    do {
                        left++;
                    } while (left < right && nums[left] == nums[left - 1]);
                    do {
                        right--;
                    } while (left < right && nums[right] == nums[right + 1]);
    			}
    		}
    	}
    	return res;
    }
};

int main () {
    vector<int> nums{34,55,79,28,46,33,2,48,31,-3,84,71,52,-3,93,15,21,-43,57,-6,86,56,94,74,83,-14,28,-66,46,-49,62,-11,43,65,77,12,47,61,26,1,13,29,55,-82,76,26,15,-29,36,-29,10,-70,69,17,49};
    Solution s;
    vector<vector<int>> v = s.threeSum(nums);
    for (auto v1 : v) {
        for (auto i : v1) {
            cout << i << ",";
        }
        cout << endl;
    }
    return 0;
}
