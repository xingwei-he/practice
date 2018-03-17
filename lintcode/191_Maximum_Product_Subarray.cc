/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:191_Maximum_Product_Subarray.cc
 * Author:
 * Mail:
 * Created Time:星期五  3/16 17:30:25 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 *
 * Example
 *   For example, given the array [2,3,-2,4], the contiguous subarray [2,3] has the largest product = 6.
 */

class Solution {
public:
  /**
   * @param nums: An array of integers
   * @return: An integer
   */
  // DP
  int maxProduct(vector<int> &nums) {
    int max_product = nums[0];
    vector<int> max_vec(nums.size(), nums[0]);// max_vec[i] 记录以 nums[i] 为结尾的最大乘积
    vector<int> min_vec(nums.size(), nums[0]);// min_vec[i] 记录以 nums[i] 为结尾的最小乘积
    max_vec[0] = nums[0];
    min_vec[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      max_vec[i] = max(nums[i], max(max_vec[i - 1] * nums[i], min_vec[i - 1] * nums[i]));
      min_vec[i] = min(nums[i], min(max_vec[i - 1] * nums[i], min_vec[i - 1] * nums[i]));
      if (max_product < max_vec[i]) {// 做简单修改即可求最小乘积
	max_product = max_vec[i];
      }
    }
    //debug1DVector<int>(max_vec, 3);
    //debug1DVector<int>(min_vec, 3);
    return max_product;;
  }
};

int main() {
  int arr[] = {2,3,-2,4};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  debug1DVector<int>(nums, 3);
  Solution sl;
  int res = sl.maxProduct(nums);
  cout << res << endl;
  return 0;
}
