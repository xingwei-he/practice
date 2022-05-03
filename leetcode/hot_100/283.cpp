#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 快排的一次划分
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }
        int n = nums.size();
        if (1 == n) {
            return;
        }
        int pivot = 0; // 不代表坐标
        int i = -1, j = 0;
        while (j < n) {
            if (nums[j] != pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
            j++;
        }
    }
};

int main() {
	vector<int> nums{0,1,0,3,12};
	Solution s;
	s.moveZeroes(nums);
	for (auto &i:nums) {
		cout << i << ",";
	}
    cout << endl;
	return 0;
}
