/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:413_Reverse_Integer.cc
 * Author:
 * Mail:
 * Created Time:星期四  1/ 4 17:07:31 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Reverse digits of an integer. Returns 0 when the reversed integer overflows (signed 32-bit integer).
 *
 * Example
 * Given x = 123, return 321
 * Given x = -123, return -321
 */

class Solution {
public:
  /*
   * @param n: the integer to be reversed
   * @return: the reversed integer
   */
  int reverseInteger(int n) {
    int MAX_SIGNED_INT = numeric_limits<int>::max();
    //int MIN_SIGNED_INT = numeric_limits<int>::min();
    bool is_pos = true;
    if (n < 0) {
      is_pos = false;
      n *= -1;
    }
    queue<int> q;
    while (0 != n) {
      int temp = n % 10;
      n = n / 10;
      q.push(temp);
    }
    int res = 0;
    while (!q.empty()) {
      if ((double)MAX_SIGNED_INT / 10.0 > res) {
	res *= 10;
	res += q.front();
	q.pop();
      } else {
	return 0;
      }
    }
    if (!is_pos) {
      res *= -1;
    }
    return res;
  }
};

int main() {
  int n = 1534236469;
  cout << "n:" << n << endl;
  Solution sl;
  int res = sl.reverseInteger(n);
  cout << "reverse res:" << res << endl;
  return 0;
}
