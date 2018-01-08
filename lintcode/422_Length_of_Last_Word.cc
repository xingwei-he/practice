/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:422_Length_of_Last_Word.cc
 * Author:
 * Mail:
 * Created Time:星期五  1/ 5 10:13:20 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 * If the last word does not exist, return 0.
 *
 * Notice
 *   A word is defined as a character sequence consists of non-space characters only.
 *
 * Example
 * Given s = "Hello World", return 5.
 */

class Solution {
public:
  /*
   * @param s: A string
   * @return: the length of last word
   */
  int lengthOfLastWord(string &s) {
    if (s.size() == 0) {
      return 0;
    }
    int left = 0;
    int right = s.size() - 1;
    while (right >= 0 && s[right] == ' ') {
      right--;
    }
    left = right;
    while (left >= 0 && s[left] != ' ') {
      left--;
    }
    if (right < 0) {
      return 0;
    }
    string subs = s.substr(left + 1, right - left);
    return subs.size();
  }
};

int main() {
  string s = "Hello World";
  cout << s << endl;
  Solution sl;
  int len = sl.lengthOfLastWord(s);
  cout << "length of last word:" << len << endl;
  return 0;
}
