/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:63_Search_in_Rotated_Sorted_Array_II.cc
 * Author:
 * Mail:
 * Created Time:星期一  1/ 8 10:34:45 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Follow up for Search in Rotated Sorted Array:
 * What if duplicates are allowed?
 * Would this affect the run-time complexity? How and why?
 * Write a function to determine if a given target is in the array.
 *
 * Example
 * Given [1, 1, 0, 1, 1, 1] and target = 0, return true.
 * Given [1, 1, 1, 1, 1, 1] and target = 0, return false.
 */

class Solution {
public:
  /*
   * @param A: an integer ratated sorted array and duplicates are allowed
   * @param target: An integer
   * @return: a boolean 
   */
  bool search(vector<int> &A, int target) {
    if (A.size() < 1) {
      return false;
    }
    bool res = false;
    int pos = 0;// pos 指向最大值点
    while (pos < A.size() - 1 && A[pos] <= A[pos + 1]) {
      pos++;
    }
    int left = 0;
    int right = A.size() - 1;
    int mid = 0;
    if (target == A[pos]) {
      return true;
    } else if (target >= A[pos + 1] && target <= A.back()) {
      left = pos + 1;
    } else {
      right = pos;
    }
    while (left <= right) {
      mid = (left + right) / 2;
      if (A[mid] == target) {
	return true;
      } else if (A[mid] < target) {
	left = mid + 1;
      } else {
	right = mid - 1;
      }
    }
    return res;
  }
};

int main() {
  int arr[] = {2,2,2,3,1};
  int target = 1;
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << "  ";
  }
  cout << endl;
  cout << "target:" << target << endl;
  Solution sl;
  bool res = sl.search(nums, target);
  cout << boolalpha << res << endl;
  return 0;
}

