/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:617_Maximum_Average_Subarray.cc
 * Author:
 * Mail:
 * Created Time:星期一  3/12 18:36:10 2018
 ***************************************************/
#include <iostream>

#include "../include/base.h"

using namespace std;

/**
 * Given an array with positive and negative numbers, find the maximum average subarray which length should be greater or equal to given length k.
 *
 * Notice
 *   It's guaranteed that the size of the array is greater or equal to k.
 *
 * Example
 *   Given nums = [1, 12, -5, -6, 50, 3], k = 3
 *   Return 15.667 // (-6 + 50 + 3) / 3 = 15.667
 */

class Solution {
public:
  /*
   * @param nums: an array with positive and negative numbers
   * @param k: an integer
   * @return: the maximum average
   */
  // Time Limit Exceeded
  double maxAverage(vector<int> &nums, int k) {
    if (nums.size() <= 0 || k <= 0) {
      return 0;
    }
    int len = nums.size();
    vector<long> sum_vec(len + 1, 0);// 记录 nums[0~i] 的和
    // up 和 down 只当做上下界
    long up = 0;
    long down = 0;
    for (int i = 0; i < len; i++) {
      sum_vec[i + 1] = nums[i] + sum_vec[i];
      if (nums[i] > 0) {
	up += nums[i];
      } else {
	down += nums[i];
      }
    }
    long sum = 0;
    double average = 0.0;
    double res = down;
    for (int i = 0; i <= len - k; i++) {
      for (int j = i + k; j <= len; j++) {
	sum = sum_vec[j] - sum_vec[i];
	average = (double)sum / (j - i);
	if (res < average) {
	  res = average;
	}
      }
    }
    return res;
  }
};

int main() {
  int arr[] = {-2,-7,-8,-1};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  int k = 2;
  cout << sl.maxAverage(nums, k) << endl;
  return 0;
}
