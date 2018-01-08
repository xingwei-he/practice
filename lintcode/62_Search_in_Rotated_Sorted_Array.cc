/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:62_Search_in_Rotated_Sorted_Array.cc
 * Author:
 * Mail:
 * Created Time:星期一 12/18 14:15:03 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 *
 * Example
 * For [4, 5, 1, 2, 3] and target=1, return 2.
 * For [4, 5, 1, 2, 3] and target=0, return -1.
 */

class Solution {
public:
  /*
   * @param A: an integer rotated sorted array
   * @param target: an integer to be searched
   * @return: an integer
   */
  int search(vector<int> &A, int target) {
    if (A.size() < 1) {
      return -1;
    }
    int left = 0;
    int right = A.size() - 1;
    int mid = 0;
    // 利用一次二分查找分界点，即序列中最小值点找出来
    while (A[left] >= A[right]) {
      mid = (left + right) / 2;
      cout << "mid:" << mid << "  val:" << A[mid] << endl;
      if (mid == 0 || mid == A.size() - 1) {
	break;
      } else {
	if (A[mid - 1] > A[mid] && A[mid] < A[mid + 1]) {
	  break;
	} else if (A[mid] > A[left]) {
	  left = mid;
	} else {
	  right = mid;
	}
      }
      cout << "left:" << left << "  right:" << right << endl;
    }
    cout << "minimun pos:" << mid << endl;
    // 再用一次二分查找搜索target
    left = 0;
    right = A.size() - 1;
    if (target >= A[mid] && target <= A[right]) {
      left = mid;
    } else {
      right = mid - 1;
    }
    while (left <= right) {
      mid = (left + right) / 2;
      if (A[mid] == target) {
	return mid;
      } else if (A[mid] > target) {
	right = mid - 1;
      } else {
	left = mid + 1;
      }
    }
    return -1;
  }
};

int main() {
  //int nums[] = {4,5,6,7,8,1,2,3};
  int nums[] = {0,1,2,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1};
  //int nums[] = {1};
  int target = -9;
  vector<int> arr(begin(nums), end(nums));
  Solution sl;
  int res = sl.search(arr, target);
  cout << res << endl;
  return 0;
}
