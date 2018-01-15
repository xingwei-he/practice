/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:48_Majority_Number_III.cc
 * Author:
 * Mail:
 * Created Time:星期一  1/15 12:42:18 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given an array of integers and a number k, the majority number is the number that occurs more than 1/k of the size of the array.
 * Find it.
 *
 * Notice
 *   There is only one majority number in the array.
 *
 * Example
 * Given [3,1,2,3,2,3,3,4,4,4] and k=3, return 3.
 */

class Solution {
public:
  /*
   * @param nums: A list of integers
   * @param k: An integer
   * @return: The majority number
   */
  int majorityNumber(vector<int> &nums, int k) {
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
    if (max_occurence > n / k) {
      return max_number;
    }
  }
};

int main() {
  return 0;
}
