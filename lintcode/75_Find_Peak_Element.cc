/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:75_Find_Peak_Element.cc
 * Author:
 * Mail:
 * Created Time:星期二 12/19 10:47:48 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * There is an integer array which has the following features:
 *   1. The numbers in adjacent positions are different.
 *   2. A[0] < A[1] && A[A.length - 2] > A[A.length - 1].
 *
 * We define a position P is a peek if:
 *   A[P] > A[P-1] && A[P] > A[P+1]
 *
 * Find a peak element in this array. Return the index of the peak.
 *
 * Notice
 *  It's guaranteed the array has at least one peak.
 *  The array may contain multiple peeks, find any of them.
 *  The array has at least 3 numbers in it.

 *  Example
 *  Given [1, 2, 1, 3, 4, 5, 7, 6]
 *  Return index 1 (which is number 2) or 6 (which is number 7)
 */

class Solution {
public:
  /*
   * @param A: An integers array.
   * @return: return any of peek positions.
   */
  // 利用二分查找
  // 如果是峰值则返回，否则，如果 A[mid] 大于 A[mid - 1] 就抛弃左侧，反之抛弃右侧
  int findPeak(vector<int>& A) {
    if (A.size() < 3) {
      return -1;
    }
    int left = 0;
    int right = A.size() - 1;
    int mid = 0;
    while (left <= right) {
      mid = (left + right) / 2;
      if (A[mid] > A[mid + 1] && A[mid] > A[mid - 1]) {
	return mid;
      } else if (A[mid] > A[mid - 1]) {
	left = mid + 1;
      } else {
	right = mid - 1;
      }
    }
    return mid;
  }
};

int main() {
  //int arr[] = {1, 2, 1, 3, 4, 5, 6, 7};
  int arr[] = {100,102,104,7,9,11,4,3};
  //int arr[] = {1, 2, 3, 2, 1};
  vector<int> nums(begin(arr), end(arr));
  Solution sl;
  int peak = sl.findPeak(nums);
  cout << peak << endl;
  return 0;
}
