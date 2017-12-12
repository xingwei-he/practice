/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:1_Two_Sum.cc
 * Author:
 * Mail:
 * Created Time:星期二 12/12 11:09:15 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */

class Solution {
public:
  /*
  // 方法1
  // 两层循环
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    for (int i = 0; i < nums.size() - 1; i++) {
      for (int j = i + 1; j < nums.size(); j++) {
	if (nums[i] + nums[j] == target) {
	  res.push_back(i);
	  res.push_back(j);
	  return res;
	}
      }
    }
    return res;
  }
  */

  // 方法2
  // 利用 map
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    map<int, int> num_map;
    for (int i = nums.size() - 1; i >= 0; i--) {
      // 边插值边查询
      //num_map.insert(make_pair<int, int>(nums[i], i));
      num_map.insert(pair<int, int>(nums[i], i));
      if (num_map.find(target - nums[i]) != num_map.end()) {
	if (i < num_map[target - nums[i]]) {
	  res.push_back(i);
	  res.push_back(num_map[target - nums[i]]);
	  return res;
	}
      }
    }
    return res;
  }

};

int main() {
  return 0;
}
