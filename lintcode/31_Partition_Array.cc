/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:31_Partition_Array.cc
 * Author:
 * Mail:
 * Created Time:星期三 12/20 17:30:36 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given an array nums of integers and an int k, partition the array (i.e move the elements in "nums") such that:
 * All elements < k are moved to the left
 * All elements >= k are moved to the right
 * Return the partitioning index, i.e the first index i nums[i] >= k.
 *
 * Notice
 * You should do really partition in array nums instead of just counting the numbers of integers smaller than k.
 * If all elements in nums are smaller than k, then return nums.length
 *
 * Example
 * If nums = [3,2,2,1] and k=2, a valid answer is 1.
 */

class Solution {
public:
  /*
   * @param nums: The integer array you should partition\
   * @param k: An integer
   * @return: The index after partition
   */
  /*
  void debug(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
      cout << vec[i] << "  ";
    }
    cout << endl;
  }
  */

  int partitionArray(vector<int> &nums, int k) {
    int left = 0;
    int right = nums.size() - 1;
    int pivot = k;
    while (left < right) {
      while (left < right && nums[right] >= pivot) {
	right--;
      }
      while (left <= right && nums[left] < pivot) {
	left++;
      }
      int temp = nums[left];
      nums[left] = nums[right];
      nums[right] = temp;
    }
    return left;
  }
};

int main() {
  //int arr[] = {7,7,9,8,6,6,8,7,9,8,6,6};
  int arr[] = {6,6,8,6,7,9,8,7,9,6,8,6,8,9,8,7,8,6,7,6,6,8,6,6};
  vector<int> nums(begin(arr), end(arr));
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << "  ";
  }
  cout << endl;
  Solution sl;
  int pos = sl.partitionArray(nums, 5);
  cout << pos << endl;
  return 0;
}

