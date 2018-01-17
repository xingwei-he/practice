/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:44_Minimum_Subarray.cc
 * Author:
 * Mail:
 * Created Time:星期三  1/17 11:17:01 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given an array of integers, find the subarray with smallest sum.
 * Return the sum of the subarray.
 *
 * Notice
 *   The subarray should contain one integer at least.
 *
 * Example
 * For [1, -1, -2, 1], return -3. 
 */

class Solution {
public:
  /*
   * @param nums: a list of integers
   * @return: A integer indicate the sum of minimum subarray
   */
  int minSubArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    int min = dp[0];
    for (int i = 1; i < n; i++) {
      dp[i] = (dp[i - 1] + nums[i]) < nums[i] ? (dp[i - 1] + nums[i]) : nums[i];
      if (min > dp[i]) {
	min = dp[i];
      }
    }
    return min;
  }
};

int main() {
  int arr[] = {1,-1,-2,1};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  cout << sl.minSubArray(nums) << endl;
  return 0;
}
