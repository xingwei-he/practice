/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:182_Delete_Digits.cc
 * Author:
 * Mail:
 * Created Time:星期一  3/19 18:31:29 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given string A representative a positive integer which has N digits, remove any k digits of the number, the remaining digits are arranged according to the original order to become a new positive integer.
 * Find the smallest integer after remove k digits.
 * N <= 240 and k <= N,
 *
 * Example
 *   Given an integer A = "178542", k = 4
 *   return a string "12"
 */

class Solution {
public:
  /**
   * @param A: A positive integer which has N digits, A is a string
   * @param k: Remove k digits
   * @return: A string
   */
  string DeleteDigits(string &A, int k) {
    int len = A.size();
    vector<int> nums(len);
    vector<bool> peak(len, false);
    for (int i = 0; i < len; i++) {
      nums[i] = A[i] - '0';
    }
    for (int i = 0; i < len; i++) {
      if (i == 0 && nums[i] > nums[i + 1]) {
	peak[i] = true;
      } else if (i == len - 1 && nums[i] > nums[i - 1]) {
	peak[i] = true;
      } else {

      }
    }
  }
};

int main() {
  return 0;
}
