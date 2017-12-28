/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:142_O(1)_Check_Power_of_2.cc
 * Author:
 * Mail:
 * Created Time:星期四 12/28 15:34:00 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Using O(1) time to check whether an integer n is a power of 2.
 *
 * Example
 * For n=4, return true;
 * For n=5, return false;
 */

class Solution {
public:
  /*
   * @param n: An integer
   * @return: True or false
   */
  bool checkPowerOf2(int n) {
    bool res = false;
    if (n <= 0) {
      return false;
    }
    while ((n & 1) == 0) {
      n >>= 1;
    }
    if (1 == n) {
      res = true;
    } else {
      res = false;
    }
    return res;
  }
};

int main() {
  Solution sl;
  bool res = sl.checkPowerOf2(128);
  cout << boolalpha << res << endl;
  return 0;
}
