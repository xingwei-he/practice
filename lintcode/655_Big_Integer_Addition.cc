/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:655_Big_Integer_Addition.cc
 * Author:
 * Mail:
 * Created Time:星期三 12/27 10:56:25 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

 * Notice
 *   The length of both num1 and num2 is < 5100.
 *   Both num1 and num2 contains only digits 0-9.
 *   Both num1 and num2 does not contain any leading zero.
 *   You must not use any built-in BigInteger library or convert the inputs to integer directly.
 *
 * Example
 * Given num1 = "123", num2 = "45"
 * return "168"
 */

class Solution {
public:
  /*
   * @param num1: a non-negative integers
   * @param num2: a non-negative integers
   * @return: return sum of num1 and num2
   */
  string addStrings(string &num1, string &num2) {
    string res;
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    while (i >= 0 || j >= 0 || carry > 0) {
      int x = 0;
      int y = 0;
      int val = 0;
      if (i >= 0) {
	x = num1[i] - '0';
	i--;
      }
      if (j >= 0) {
	y = num2[j] - '0';
	j--;
      }
      val = (carry + x + y) % 10;
      carry = (carry + x + y) / 10;
      res.push_back(char(val + '0'));
    }
    // reverse res
    for (i = 0, j = res.size() - 1; i < j; i++, j--) {
       char temp = res[i];
       res[i] = res[j];
       res[j] = temp;
    }
    cout << res << endl;
    return res;
  }
};

int main() {
  string num1 = "657";
  string num2 = "899";
  Solution sl;
  string res = sl.addStrings(num1, num2);
  cout << "num1:" << num1 << "\tnum2:" << num2 << endl;
  cout << "res:" << res << endl;
  return 0;
}
