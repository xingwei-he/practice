/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:692_Sliding_Window_Unique_Elements_Sum.cc
 * Author:
 * Mail:
 * Created Time:星期二  3/20 10:26:02 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given an array and a window size that is sliding along the array, find the sum of the count of unique elements in each window.
 *
 * Example
 *   Given a array nums = [1, 2, 1, 3, 3] and k = 3
 *   First window [1, 2, 1], only 2 is unique, count is 1.
 *   Second window [2, 1, 3], all elements unique, count is 3.
 *   Third window [1, 3, 3], only 1 is unique, count is 1.
 *   sum of count = 1 + 3 + 1 = 5
 *   Return 5
 */

class Solution {
public:
  /**
   * @param nums: the given array
   * @param k: the window size
   * @return: the sum of the count of unique elements in each window
   */
  int slidingWindowUniqueElementsSum(vector<int> &nums, int k) {
    int len = nums.size();
    unordered_map<int, int> counter_map;
    for (int i = 0; i < k && i < len; i++) {
      if (counter_map.find(nums[i]) != counter_map.end()) {
	counter_map[nums[i]] += 1;
      } else {
	counter_map.insert(pair<int, int>(nums[i], 1));
      }
    }
    int res = 0;
    for (unordered_map<int, int>::iterator iter = counter_map.begin();
	 iter != counter_map.end();
	 iter++) {
      if (iter->second == 1) {
	res++;
      }
    }
    if (len <= k) {// 如果窗口大于数组长度，则直接返回 res
      return res;
    }
    int last_res = res;
    for (int i = k; i < len; i++) {
      if (nums[i] == nums[i - k]) {
	res += last_res;
	continue;
      }
      counter_map[nums[i - k]] -= 1;
      if (counter_map[nums[i - k]] == 1) {
	last_res++;
      } else if (counter_map[nums[i - k]] == 0) {
	last_res--;
      }
      if (counter_map.find(nums[i]) != counter_map.end()) {
	counter_map[nums[i]] += 1;
      } else {
	counter_map[nums[i]] = 1;
      }
      if (counter_map[nums[i]] == 1) {
	last_res++;
      } else if (counter_map[nums[i]] == 2) {
	last_res--;
      }
      res += last_res;
    }
    return res;
  }
};

int main() {
  int arr[] = {1,2,1,3,3};
  int k = 3;
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  int res = sl.slidingWindowUniqueElementsSum(nums, k);
  cout << "res:" << res << endl;
  return 0;
}
