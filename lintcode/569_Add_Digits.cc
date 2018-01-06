/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:569_Add_Digits.cc
 * Author:
 * Mail:
 * Created Time:2018年01月06日 星期六 23时29分46秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 *
 * Example
 *
 * Given num = 38.
 * The process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return 2.
 */

class Solution {
public:
  /*
   * @param num: a non-negative integer
   * @return: one digit
   */
  int addDigits(int num) {
    int res = num;
    vector<int> digits;
    while (0 != (res / 10)) {
      num = res;
      while (0 != num) {
        int d = num % 10;
        num /= 10;
        digits.push_back(d);
      }
      res = 0;
      for (int i = 0; i < digits.size(); i++) {
	res += digits[i];
      }
      digits.clear();
    }
    return res;
  }
};

int main() {
  int n = 38;
  Solution sl;
  int res = sl.addDigits(n);
  cout << "n:" << n << "\tres:" << res << endl;
  return 0;
}
