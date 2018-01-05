/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:488_Happy_Number.cc
 * Author:
 * Mail:
 * Created Time:星期五  1/ 5 16:20:32 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Write an algorithm to determine if a number is happy.
 * A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 *
 * Example
 * 19 is a happy number

 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 */

class Solution {
public:
  /*
   * @param n: An integer
   * @return: true if this is a happy number or false
   */
  int getX(int n) {
    vector<int> nums;
    while (0 != n) {
      nums.push_back(n % 10);
      n /= 10;
    }
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
      res += nums[i] * nums[i];
    }
    return res;
  }
  /*
  bool isHappy(int n) {
    while (true) {
      if (1 == n) {
	return true;
      } else if (4 == n) {
	// 当 n 为 4 时，结果会无限循环下去，故当结果中出现 4 即不是 happy number
	return false;
      }
      n = getX(n);
    }
  }
  */
  bool isHappy(int n) {
    set<int> x_set;
    while (true) {
      if (1 == n) {
	return true;
      }
      if (x_set.find(n) != x_set.end()) {
	return false;
      } else {
	x_set.insert(n);
      }
      n = getX(n);
    }
  }
};

int main() {
  int n = 19;
  Solution sl;
  bool res = sl.isHappy(n);
  cout << boolalpha << res << endl;
  return 0;
}
