/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:408_Add_Binary.cc
 * Author:
 * Mail:
 * Created Time:星期四  1/ 4 16:20:39 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given two binary strings, return their sum (also a binary string).
 *
 * Example
 * a = 11
 * b = 1
 * Return 100
 */

class Solution {
public:
  /*
   * @param a: a number
   * @param b: a number
   * @return: the result
   */
  string addBinary(string &a, string &b) {
    string res;
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    stack<int> st;
    while (i >= 0 && j >= 0) {
      int sum = (a[i] - '0') + (b[j] - '0') + carry;
      carry = sum / 2;
      sum = sum % 2;
      st.push(sum);
      i--;
      j--;
    }
    while (i >= 0) {
      int sum = (a[i] - '0') + carry;
      carry = sum / 2;
      sum = sum % 2;
      st.push(sum);
      i--;
    }
    while (j >= 0) {
      int sum = (b[j] - '0') + carry;
      carry = sum / 2;
      sum = sum % 2;
      st.push(sum);
      j--;
    }
    if (carry > 0) {
      st.push(carry);
    }
    while (!st.empty()) {
      res.push_back(st.top() + '0');
      st.pop();
    }
    return res;
  }
};

int main() {
  string a = "0";
  string b = "0";
  Solution sl;
  string res = sl.addBinary(a, b);
  cout << res << endl;
  return 0;
}
