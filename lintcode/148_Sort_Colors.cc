/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:148_Sort_Colors.cc
 * Author:
 * Mail:
 * Created Time:星期四  3/15 18:32:20 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 *
 * Notice
 *   You are not suppose to use the library's sort function for this problem. 
 *   You should do it in-place (sort numbers in the original array).
 *
 * Example
 *   Given [1, 0, 1, 2], sort it in-place to [0, 1, 1, 2].
 */

class Solution {
public:
  /**
   * @param nums: A list of integer which is 0, 1 or 2 
   * @return: nothing
   */
  void swap(int& a, int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
  }

  void sortColors(vector<int> &nums) {
    int left = 0, pos = 0, right = nums.size() - 1;
    while (pos < right) {
      while (0 == nums[left]) {
        left++;
      }
      while (2 == nums[right]) {
        right--;
      }
      pos = left + 1;
      while (1 == nums[pos] && pos < right) {
	pos++;
      }
      if (0 == nums[pos]) {
	swap(nums[left], nums[pos]);
      } else if (2 == nums[pos]) {
	swap(nums[right], nums[pos]);
      }
    }
  }
};

int main() {
  int arr[] = {1,2,2,0,0,1,2,1,1,2,0};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  sl.sortColors(nums);
  debug1DVector<int>(nums, 3);
  return 0;
}
