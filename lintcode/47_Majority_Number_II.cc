/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:47_Majority_Number_II.cc
 * Author:
 * Mail:
 * Created Time:星期一  1/15 11:26:16 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given an array of integers, the majority number is the number that occurs more than 1/3 of the size of the array.
 * Find it.
 *
 * Notice
 *   There is only one majority number in the array.
 *
 * Example
 * Given [1, 2, 1, 2, 1, 3, 3], return 1.
 */

class Solution {
public:
  /*
   * @param nums: a list of integers
   * @return: The majority number that occurs more than 1/3
   */
  /*
  // O(n) time and O(n) extra space
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
    if (max_occurence > n / 3) {
      return max_number;
    }
  }
  */

  // O(n) time and O(1) extra space
  int majorityNumber(vector<int> nums) {
    int candidate1, candidate2;
    int count1 = 0, count2 = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (candidate1 == nums[i]) {
	count1 ++;
      } else if (candidate2 == nums[i]) {
	count2 ++;
      } else if (count1 == 0) {
	candidate1 = nums[i];
	count1 = 1;
      } else if (count2 == 0) {
	candidate2 = nums[i];
	count2 = 1;
      } else {
	count1--;
	count2--;
      }
    }
    count1 = count2 = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == candidate1) {
	count1++;
      } else if (nums[i] == candidate2) {
	count2++;
      }
    }
    return count1 > count2 ? candidate1 : candidate2;
  }
};

int main() {
  int arr[] = {1, 2, 2, 2, 1, 3, 3, 3, 2, 1, 3, 3};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  int n = sl.majorityNumber(nums);
  cout << "majority_number:" << n << endl;
  return 0;
}
