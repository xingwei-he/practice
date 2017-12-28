/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:157_Unique_Characters.cc
 * Author:
 * Mail:
 * Created Time:星期四 12/28 18:59:27 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Implement an algorithm to determine if a string has all unique characters.
 *
 * Example
 * Given "abc", return true.
 * Given "aab", return false.
 */

class Solution {
public:
  /*
   * @param str: A string
   * @return: a boolean
   */
  // lintcode 需要显式 #include <bitset>
  bool isUnique(string &str) {
    bitset<256> bs;
    for (int i = 0; i < str.size(); i++) {
      if (bs.test(str[i])) {
	return false;
      } else {
	bs.set(str[i]);
      }
    }
    return true;
  }
};

int main() {
  //string str = "abcdefg";
  string str = "abcdemas";
  Solution sl;
  bool is_unique = sl.isUnique(str);
  cout << boolalpha << is_unique << endl;
  return 0;
}

