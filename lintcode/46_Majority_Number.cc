/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:46_Majority_Number.cc
 * Author:
 * Mail:
 * Created Time:星期一  1/15 10:48:54 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given an array of integers, the majority number is the number that occurs more than half of the size of the array. Find it.
 *
 * Notice
 *   You may assume that the array is non-empty and the majority number always exist in the array.
 *
 * Example
 * Given [1, 1, 1, 1, 2, 2, 2], return 1
 */

class Solution {
public:
  /*
   * @param nums: a list of integers
   * @return: find a  majority number
   */
  int majorityNumber(vector<int> &nums) {
    unordered_map<int, int> counter_map;
    int n = nums.size();
    int max_occurence = 0;
    int max_number = 0;
    for (int i = 0; i < n; i++) {
      if (counter_map.find(nums[i]) != counter_map.end()) {
	counter_map[nums[i]] += 1;
      } else {
	counter_map.insert(pair<int, int>(nums[i], 1));
      }
      if (max_occurence < counter_map[nums[i]]) {
	max_occurence = counter_map[nums[i]];
	max_number = nums[i];
      }
    }
    if (max_occurence > n / 2) {
      return max_number;
    }
  }
};

int main() {
  return 0;
}

