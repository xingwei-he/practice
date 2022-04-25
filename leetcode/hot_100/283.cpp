#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return;
        }
        int i = 0, j = 0; // i 指向零，j 指向非零
        while (nums[i] != 0 && i < n) {
            i++;
        }
        j = i;
        while (nums[j] == 0 && j < n) {
            j++;
        }
        while (i < n && j < n) {
            swap(nums[i], nums[j]);
            while (nums[i] != 0 && i < n) {
                i++;
            }
            while (nums[j] == 0 && j < n) {
                j++;
            }
        }
    }
};

int main() {
	vector<int> nums{0,0};
	Solution s;
	s.moveZeroes(nums);
	for (auto &i:nums) {
		cout << i << endl;
	}
	return 0;
}
