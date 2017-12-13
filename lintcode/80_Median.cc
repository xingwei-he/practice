/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:80_Median.cc
 * Author:
 * Mail:
 * Created Time:2017年12月13日 星期三 23时56分03秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a unsorted array with integers, find the median of it.
 * A median is the middle number of the array after it is sorted.
 *
 * If there are even numbers in the array, return the N/2-th number after sorted.
 *
 * Example
 * Given [4, 5, 1, 2, 3], return 3.
 * Given [7, 9, 4, 5], return 5.
 */
class Solution {
public:
  /*
   * @param : A list of integers
   * @return: An integer denotes the middle number of the array
   */
  int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[left];
    while (left < right) {
      while (left < right && pivot <= nums[right]) {
	right--;
      }
      nums[left] = nums[right];
      while (left < right && pivot >= nums[left]) {
	left++;
      }
      nums[right] = nums[left];
    }
    nums[left] = pivot;
    return left;
  }

  int median(vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;
    int median_pos = (nums.size() - 1) / 2;
    int pos = partition(nums, left, right);
    while (pos != median_pos) {
      if (pos < median_pos) {
	left = pos + 1;
      } else if (pos > median_pos) {
	right = pos - 1;
      }
      pos = partition(nums, left, right);
    }
    return nums[pos];
  }
};

int main() {
  //int arr[] = {5, 2, 1, 8, 9, 6, 3, 4, 7, 0};
  int arr[] = {7, 9, 4, 5};
  vector<int> nums(begin(arr), end(arr));
  
  cout << "nums:" << endl;
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << "  ";
  }
  cout << endl;
  Solution sl;
  /*
  int pos = sl.partition(nums, 0, nums.size() - 1);
  cout << "after partition:" << endl;
  cout << "pos:" << pos << endl;
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << "  ";
  }
  cout << endl;
  */
  int median = sl.median(nums);
  cout << "median:" << median << endl;
  return 0;
}
