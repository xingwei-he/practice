/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:60_Search_Insert_Position.cc
 * Author:
 * Mail:
 * Created Time:星期五 12/15 18:09:34 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 * You may assume NO duplicates in the array.
 *
 * Example
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 */

class Solution {
public:
  /*
   * @param A: an integer sorted array
   * @param target: an integer to be inserted
   * @return: An integer
   */
  // 利用二分查找
  int searchInsert(vector<int> &A, int target) {
    int pos = 0;
    int left = 0;
    int right = A.size() - 1;
    int mid = (left + right) / 2;
    while (left <= right) {
      mid = (left + right) / 2;
      if (A[mid] == target) {
	pos = mid;
	break;
      } else if (A[mid] > target) {
	right = mid - 1;
	//pos = mid;
      } else {
	left = mid + 1;
	//pos = mid + 1;
      }
    }
    return pos;
  }
};

int main() {
  int arr[] = {5,6};
  int target = 3;
  vector<int> nums(begin(arr), end(arr));
  Solution sl;
  int pos = sl.searchInsert(nums, target);
  cout << "pos:" << pos << endl;
  return 0;
}


