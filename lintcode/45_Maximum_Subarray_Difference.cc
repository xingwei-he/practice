/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:45_Maximum_Subarray_Difference.cc
 * Author:
 * Mail:
 * Created Time:星期四  1/11 15:15:05 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given an array with integers.
 * Find two non-overlapping subarrays A and B, which |SUM(A) - SUM(B)| is the largest.
 * Return the largest difference.
 *
 * Notice
 *   The subarray should contain at least one number
 *
 * Example
 * For [1, 2, -3, 1], return 6.
 */

class Solution {
public:
  /*
   * @param nums: A list of integers
   * @return: An integer indicate the value of maximum difference between two substrings
   */
  int maxDiffSubArrays(vector<int> &nums) {
    int n = nums.size();
    int res = nums[0] - nums[n - 1];
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[n - 1] = nums[n - 1];
    vector<int> min(n, 0);
    vector<int> max(n, 0);
    // 左小右大
    min[0] = nums[0];
    max[n - 1] = nums[n - 1];
    for (int i = 1; i < n - 1; i++) {
      dp[i] = (dp[i - 1] + nums[i]) < nums[i] ? (dp[i - 1] + nums[i]) : nums[i];
      min[i] = min[i - 1] < dp[i] ? min[i - 1] : dp[i];
    }
    for (int i = n - 2; i > 0; i--) {
      dp[i] = (dp[i + 1] + nums[i]) > nums[i] ? (dp[i + 1] + nums[i]) : nums[i];
      max[i] = max[i + 1] > dp[i] ? max[i + 1] : dp[i];
    }
    for (int i = 0; i < n - 1; i++) {
      if (res < (max[i + 1] - min[i])) {
	res = max[i + 1] - min[i];
      }
    }
    // 左大右小
    min.clear(); min.resize(n);
    max.clear(); max.resize(n);
    max[0] = nums[0];
    min[n - 1] = nums[n - 1];
    for (int i = 1; i < n - 1; i++) {
      dp [i] = (dp[i - 1] + nums[i]) > nums[i] ? (dp[i - 1] + nums[i]) : nums[i];
      max[i] = max[i - 1] > dp[i] ? max[i - 1] : dp[i];
    }
    for (int i = n - 2; i > 0; i--) {
      dp[i] = (dp[i + 1] + nums[i]) < nums[i] ? (dp[i + 1] + nums[i]) : nums[i];
      min[i] = min[i + 1] < dp[i] ? min[i + 1] : dp[i];
    }
    for (int i = 0; i < n - 1; i++) {
      if (res < (max[i] - min[i + 1])) {
	res = max[i] - min[i + 1];
      }
    }
    return res;
  }
};

int main() {
  int arr[] = {-5,3,-4,0,0,0,-1,20,1,1,-1,-1,-1,-1,-1};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  int res = sl.maxDiffSubArrays(nums);
  cout << "maximum_subarray_difference:" << res << endl;
  return 0;
}

