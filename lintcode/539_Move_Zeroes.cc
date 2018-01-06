/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:539_Move_Zeroes.cc
 * Author:
 * Mail:
 * Created Time:2018年01月06日 星期六 14时03分21秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 *
 * Notice
 *   You must do this in-place without making a copy of the array.
 *   Minimize the total number of operations.
 *
 * Example
 * Given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 */

class Solution {
public:
  /*
   * @param nums: an integer array
   * @return: 
   */
  void moveZeroes(vector<int>& nums) {
    int i = 0;
    int j = 0;
    while (i < nums.size()) {
      while (i < nums.size() && 0 != nums[i]) {
	i++;
      }
      j = i;
      while (j < nums.size() && 0 == nums[j]) {
	j++;
      }
      if (i < nums.size() && j < nums.size()) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
      }
      i++;
    }
  }
};

int main() {
  //int arr[] = {0, 1, 2, 0, 0, 3, 0, 0, 0, 4, 5, 6, 0, 7, 8, 0, 0, 0, 9, 0};
  int arr[] = {0,1,0,3,12};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  sl.moveZeroes(nums);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << "  ";
  }
  cout << endl;
  return 0;
}
