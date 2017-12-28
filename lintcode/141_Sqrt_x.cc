/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:141_Sqrt_x.cc
 * Author:
 * Mail:
 * Created Time:星期四 12/28 13:07:10 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Implement int sqrt(int x).
 * Compute and return the square root of x.
 *
 * Example
 * sqrt(3) = 1
 * sqrt(4) = 2
 * sqrt(5) = 2
 * sqrt(10) = 3
 */

class Solution {
public:
  /*
   * @param x: An integer
   * @return: The sqrt of x
   */
  // 二分法
  // √x <= (x+1)/2 则右边界应该为 x/2 + 1
  int sqrt(int x) {
    long long left = 0;
    long long right = x / 2 + 1;
    long long mid = 0;
    while (left <= right) {
      mid = (left + right) / 2;
      long long sqrt = mid * mid;
      if (sqrt == x) {
	return mid;
      } else if (sqrt < x) {
	left = mid + 1;
      } else {
	right = mid - 1;
      }
    }
    return right;
  }
};

int main() {
  Solution sl;
  int sqrt = sl.sqrt(999999999);
  cout << sqrt << endl;
  return 0;
}

