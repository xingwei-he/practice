#include "practice/include/base.h"

using namespace std;

/**
 * Given an array of integers, every element appears twice except for one. Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
      res ^= nums[i];
    }
    return res;
  }
};

int main() {
  int arr_1[] = {1,3,5,5,7,8,1,3,7};
  vector<int> nums_1(begin(arr_1), end(arr_1));
  Solution solution_handler;
  cout << solution_handler.singleNumber(nums_1) << endl;
  return 0;
}
