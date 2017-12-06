#include "practice/include/base.h"

using namespace std;

class Solution {
public:
  /*
   * @param nums: A list of integers
   * @return: A integer indicate the sum of max subarray
   */
  int maxSubArray(vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    }
    vector<int> sum(nums.size(), 0);
    sum[0] = nums[0];
    int max_sum = sum[0];
    for (int i = 1; i < nums.size(); i++) {
      int sum_i = (sum[i - 1] + nums[i]) > nums[i] ? (sum[i - 1] + nums[i]) : nums[i];
      sum[i] = sum_i;
      if (sum[i] > max_sum) {
	max_sum = sum[i];
      }
    }
    return max_sum;
  }
};

int main() {
  return 0;
}
