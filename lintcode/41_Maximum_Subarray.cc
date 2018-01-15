/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:41_Maximum_Subarray_new.cc
 * Author:
 * Mail:
 * Created Time:星期四  1/11 11:15:52 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given an array of integers, find a contiguous subarray which has the largest sum.
 *
 * Notice
 *   The subarray should contain at least one number.
 *
 * Example
 * Given the array [−2,2,−3,4,−1,2,1,−5,3], the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 */

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
    /*
    for (int i = 0; i < nums.size(); i++) {
      cout << setw(4) << sum[i] << "  ";
    }
    cout << endl;
    */
    return max_sum;
  }
};

int main() {
  int arr[] = {-2,-1,5,-3,-1,-2,-6,-8,0,-9};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  for (int i = 0; i < nums.size(); i++) {
    cout << setw(4) << nums[i] << "  ";
  }
  cout << endl;
  Solution sl;
  int max_sum = sl.maxSubArray(nums);
  cout << "max_sum:" << max_sum << endl;
  return 0;
}
