/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:76_Longest_Increasing_Subsequence.cc
 * Author:
 * Mail:
 * Created Time:星期二 12/19 17:10:46 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a sequence of integers, find the longest increasing subsequence (LIS).
 * You code should return the length of the LIS.
 *
 * Clarification
 * What's the definition of longest increasing subsequence?
 *   1. The longest increasing subsequence problem is to find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.
 *   2.https://en.wikipedia.org/wiki/Longest_increasing_subsequence
 *
 * Example
 * For [5, 4, 1, 2, 3], the LIS is [1, 2, 3], return 3
 * For [4, 2, 4, 5, 3, 7], the LIS is [2, 4, 5, 7], return 4
 */

class Solution {
public:
  /*
   * @param nums: An integer array
   * @return: The length of LIS (longest increasing subsequence)
   */
  // DP
  int longestIncreasingSubsequence(vector<int> &nums) {
    if (nums.size() <= 0) {
      return 0;
    }
    int lis = 0;
    // dp 记录以 nums[i] 为结尾的 LIS 的长度
    for (int i = 1; i < nums.size(); i++) {
      for ()
    }
      
    for (int i = 0; i < dp.size(); i++) {
      cout << setw(4) << dp[i];
    }
    cout << endl;
    return lis;
  }
};

int main() {
  //int arr[] = {4, 2, 4, 5, 3, 7};
  //int arr[] = {88,4,24,82,86,1,56,74,71,9,8,18,26,53,77,87,60,27,69,17,76,23,67,14,98,13,10,83,20,43,39,29,92,31,0,30,90,70,37,59};
  int arr[] = {88,4,24,82,86,1,56,74,71,9,8,18};
  vector<int> nums(begin(arr), end(arr));
  for (int i = 0; i < nums.size(); i++) {
    cout << setw(4) << nums[i]; 
  }
  cout << endl;
  Solution sl;
  int lis = sl.longestIncreasingSubsequence(nums);
  cout << setw(4) << lis << endl;
  return 0;
}

