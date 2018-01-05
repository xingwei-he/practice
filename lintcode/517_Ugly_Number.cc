/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:517_Ugly_Number.cc
 * Author:
 * Mail:
 * Created Time:星期五  1/ 5 16:53:27 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Write a program to check whether a given number is an ugly number.
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
 *
 * Notice
 *   Note that 1 is typically treated as an ugly number.
 *
 * Example
 * Given num = 8 return true
 * Given num = 14 return false
 */

class Solution {
public:
  /*
   * @param num: An integer
   * @return: true if num is an ugly number or false
   */
  bool isUgly(int num) {
    while (num >= 2) {
      if (num % 2 == 0) {
	num /= 2;
      } else if (num % 3 == 0) {
	num /= 3;
      } else if (num % 5 == 0) {
	num /= 5;
      } else {
	return false;
      }
    }
    if (1 == num) {
      return true;
    }
    return false;
  }
};

int main() {
  return 0;
}

