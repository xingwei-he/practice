/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:365_Count_1_in_Binary.cc
 * Author:
 * Mail:
 * Created Time:星期三  1/ 3 12:29:26 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Count how many 1 in binary representation of a 32-bit integer.
 *
 * Example
 * Given 32, return 1
 * Given 5, return 2
 * Given 1023, return 9
 */

class Solution {
public:
  /*
   * @param num: An integer
   * @return: An integer
   */
  int countOnes(int num) {
    unsigned int temp = num;
    int counter = 0;
    while (0 != temp) {
      if ((temp & 1) == 1) {
	counter++;
      }
      temp >>= 1;
    }
    return counter;
  }
};

int main() {
  int n = 5;
  Solution sl;
  int c = sl.countOnes(n);
  cout << n << "\t" << c << endl;
  return 0;
}
