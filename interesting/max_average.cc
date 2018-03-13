/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:max_average.cc
 * Author:
 * Mail:
 * Created Time:星期一  3/12 17:38:42 2018
 ***************************************************/
#include <iostream>
#include <vector>
using namespace std;

/**
 * 题目描述
 *   给定n个数的数组，找到所有长度大于等于k的连续子数组中平均值最大的那个。返回那个最大的平均值。
 *   1 <= k <= n <= 10000，数组中的元素在范围[-10000, 10000]之间，最后返回的答案的误差应在10^(-5)以内。
 *
 * 样例
 *   输入：[1,12,-5,-6,50,3], k = 4
 *   输出：12.75
 */

class Solution {
public:
  static const int RANGE_MIN = -10000;
  static const int RANGE_MAX = 10000;
  float getMaxAverage(vector<int> nums, int k) {
    if (nums.size() <= 0 || k <= 0) {
      return 0;
    }
    int len = nums.size();
    vector<long> sum_vec(len + 1, 0);// 记录 nums[0~j] 的和
    for (int i = 0; i < len; i++) {
      sum_vec[i + 1] = sum_vec[i] + nums[i];
    }
    float res = RANGE_MIN;
    long sum = 0;
    float average = 0.0;
    for (int i = 0; i <= len - k; i++) {
      for (int j = i + k; j <= len; j++) {
	sum = sum_vec[j] - sum_vec[i];
	average = sum / (double)(j - i);
	if (res < average) {
	  res = average;
	}
      }
    }
    return res;
  }
};

int main() {
  int arr[] = {-1,-2,-5,-3,-1};
  int k = 2;
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  float res = sl.getMaxAverage(nums, k);
  cout << res << endl;
  return 0;
}
