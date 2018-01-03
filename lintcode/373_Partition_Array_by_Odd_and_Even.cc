/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:373_Partition_Array_by_Odd_and_Even.cc
 * Author:
 * Mail:
 * Created Time:星期三  1/ 3 14:27:50 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Partition an integers array into odd number first and even number second.
 *
 * Example
 * Given [1, 2, 3, 4], return [1, 3, 2, 4]
 */

class Solution {
public:
  /*
   * @param nums: an array of integers
   * @return: nothing
   */
  void partitionArray(vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
      while (left < right && nums[left] % 2 == 1) {
	left++;
      }
      while (left < right && nums[right] % 2 == 0) {
	right--;
      }
      int temp = nums[left];
      nums[left] = nums[right];
      nums[right] = temp;
    }
  }
};

int main() {
  int arr[] = {1,6,5,3,8,2,7,9,4};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  sl.partitionArray(nums);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << "  ";
  }
  cout << endl;
  return 0;
}
