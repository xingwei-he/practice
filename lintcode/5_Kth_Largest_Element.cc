/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:5_Kth_Largest_Element.cc
 * Author:
 * Mail:
 * Created Time:2018年01月07日 星期日 18时07分36秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Find K-th largest element in an array.
 *
 * Notice
 *   You can swap elements in the array
 *
 * Example
 * In array [9,3,2,4,8], the 3rd largest element is 4.
 * In array [1,2,3,4,5], the 1st largest element is 5, 2nd largest element is 4, 3rd largest element is 3 and etc.
 */

class Solution {
public:
  /*
   * @param n: An integer
   * @param nums: An array
   * @return: the Kth largest element
   */
  // 利用二分查找的 partition
  int partition(vector<int>& nums, int l, int r) {
    int pivot = nums[l];
    while (l < r) {
      while (l < r && nums[r] <= pivot) {
	r--;
      }
      nums[l] = nums[r];
      while (l < r && nums[l] >= pivot) {
	l++;
      }
      nums[r] = nums[l];
    }
    nums[l] = pivot;
    return l;
  }
  
  int kthLargestElement(int n, vector<int> &nums) {
    int pos = -1;
    int left = 0;
    int right = nums.size() - 1;
    while (pos != n - 1) {
      pos = partition(nums, left, right);
      if (pos < n - 1) {
	left = pos + 1;
      } else if (pos > n - 1) {
	right = pos - 1;
      }
    }
    return nums[pos];
  }
};

int main() {
  int arr[] = {1,2,3,4,5,6,8,9,10,7};
  int k = 10;
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  //int pos = sl.partition(nums, 0, nums.size() - 1);
  //cout << "pos:" << pos << endl;
  int element = sl.kthLargestElement(k, nums);
  cout << "k:" << k << "\telement:" << element << endl;
  return 0;
}
