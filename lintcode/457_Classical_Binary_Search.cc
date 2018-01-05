/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:457_Classical_Binary_Search.cc
 * Author:
 * Mail:
 * Created Time:星期五  1/ 5 14:29:09 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Find any position of a target number in a sorted array. Return -1 if target does not exist.
 *
 * Example
 * Given [1, 2, 2, 4, 5, 5].
 * For target = 2, return 1 or 2.
 * For target = 5, return 4 or 5.
 * For target = 6, return -1.
 */

class Solution {
public:
  /*
   * @param nums: An integer array sorted in ascending order
   * @param target: An integer
   * @return: An integer
   */
  int findPosition(vector<int> &nums, int target) {
    if (nums.size() == 0) {
      return -1;
    }
    int left = 0;
    int right = nums.size();
    int mid = 0;
    while (left <= right) {
      mid = (left + right) / 2;
      if (nums[mid] == target) {
	return mid;
      } else if (nums[mid] < target) {
	left++;
      } else {
	right--;
      }
    }
    return -1;
  }
};

int main() {
  int arr[] = {1,2,2,3,4,4,5,6,7,8,8,8,9};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  int pos = sl.findPosition(nums, 8);
  cout << "pos:" << pos << endl;
  return 0;
}

