/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:56_Two_Sum.cc
 * Author:
 * Mail:
 * Created Time:星期五 12/15 17:40:05 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are NOT zero-based.
 *
 * Notice
 *   You may assume that each input would have exactly one solution
 *
 * Example
 *   numbers=[2, 7, 11, 15], target=9
 *   return [1, 2]
 */
class Solution {
public:
  /*
   * @param numbers: An array of Integer
   * @param target: target = numbers[index1] + numbers[index2]
   * @return: [index1 + 1, index2 + 1] (index1 < index2)
   */
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> res;
    map<int, int> num_map;// 用 map 记录值-位置信息
    for (int i = numbers.size() - 1; i >= 0; i--) {
      num_map.insert(pair<int, int>(numbers[i], i));
      if (num_map.find(target - numbers[i]) != num_map.end()) {
	if (i < num_map[target - numbers[i]]) {
	  res.push_back(i);
	  res.push_back(num_map[target - numbers[i]]);
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
