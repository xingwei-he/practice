/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:420_Count_and_Say.cc
 * Author:
 * Mail:
 * Created Time:星期四  1/ 4 18:32:07 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 *
 * Notice
 *   The sequence of integers will be represented as a string.
 *
 * Example
 * Given n = 5, return "111221".
 */

class Solution {
public:
  /*
   * @param n: the nth
   * @return: the nth sequence
   */
  string countAndSay(int n) {
    string s = "1";
    for (int i = 1; i < n; i++) {
      string temp;
      int j = 0;
      while (j < s.size()) {
	int k = j;
	while (k < s.size() && s[j] == s[k]) {
	  k++;
	}
	temp.push_back(k - j + '0');
	temp.push_back(s[j]);
	j = k;
      }
      s = temp;
    }
    return s;
  }
};

int main() {
  int n = 5;
  Solution sl;
  string res = sl.countAndSay(n);
  cout << n << "\t" << res << endl;
  return 0;
}
