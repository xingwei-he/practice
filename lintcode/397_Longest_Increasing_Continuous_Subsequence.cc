/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:397_Longest_Increasing_Continuous_Subsequence.cc
 * Author:
 * Mail:
 * Created Time:星期四  1/ 4 15:21:42 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Give an integer array，find the longest increasing continuous subsequence in this array.
 * An increasing continuous subsequence:
 * Can be from right to left or from left to right.
 * Indices of the integers in the subsequence should be continuous.
 *
 * Notice
 *   O(n) time and O(1) extra space.
 *
 * Example
 * For [5, 4, 2, 1, 3], the LICS is [5, 4, 2, 1], return 4.
 * For [5, 1, 2, 3, 4], the LICS is [1, 2, 3, 4], return 4.
 */

class Solution {
public:
  /*
   * @param A: An array of Integer
   * @return: an integer
   */
  int longestIncreasingContinuousSubsequence(vector<int> &A) {
    if (A.size() == 0) {
      return 0;
    }
    int increasing_lenth = 1;
    int max_increasing_length = 1;
    int decreasing_lenth = 1;
    int max_decreasing_length = 1;
    for (int i = 1; i < A.size(); i++) {
      if (A[i - 1] < A[i]) {
	increasing_lenth++;
	decreasing_lenth = 1;
      } else if (A[i - 1] > A[i]) {
	increasing_lenth = 1;
	decreasing_lenth++;
      } else {
	increasing_lenth++;
	decreasing_lenth++;
      }
      if (max_increasing_length < increasing_lenth) {
	max_increasing_length = increasing_lenth;
      }
      if (max_decreasing_length < decreasing_lenth) {
	max_decreasing_length = decreasing_lenth;
      }
    }
    return max_increasing_length > max_decreasing_length ? max_increasing_length : max_decreasing_length;
  }
};

int main() {
  int arr[] = {5, 4, 2, 1, 3};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  int res = sl.longestIncreasingContinuousSubsequence(nums);
  cout << "res:" << res << endl;
  return 0;
}

