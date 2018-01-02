/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:181_Flip_Bits.cc
 * Author:
 * Mail:
 * Created Time:星期二  1/ 2 15:16:04 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Determine the number of bits required to flip if you want to convert integer n to integer m.
 *
 * Notice
 *   Both n and m are 32-bit integers.
 *
 * Example
 * Given n = 31 (11111), m = 14 (01110), return 2.
 */

class Solution {
public:
  /*
   * @param a: An integer
   * @param b: An integer
   * @return: An integer
   */
  int bitSwapRequired(int a, int b) {
    int res = 0;
    unsigned int temp = a ^ b;// int 型右移是算数右移，unsigned int 型是逻辑右移
    while (0 != temp) {
      res += temp & 1;
      temp >>= 1;
    }
    return res;
  }
};

int main() {
  int a = 21;
  int b = 8;
  Solution sl;
  int res = sl.bitSwapRequired(a, b);
  cout << "res:" << res << endl;
  return 0;
}
