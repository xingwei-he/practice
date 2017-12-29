/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:8_Rotate_String.cc
 * Author:
 * Mail:
 * Created Time:星期五 12/29 12:57:48 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a string and an offset, rotate string by offset. (rotate from left to right)
 *
 * Example
 * Given "abcdefg".
 * offset=0 => "abcdefg"
 * offset=1 => "gabcdef"
 * offset=2 => "fgabcde"
 * offset=3 => "efgabcd"
 */

class Solution {
public:
  /*
   * @param str: An array of char
   * @param offset: An integer
   * @return: nothing
   */
  void rotateUtil(string& str, int from, int to) {
    if (str.size() == 0 || from < 0 || to < 0 || from > to) {
      return;
    }
    while (from < to) {
      char temp = str[from];
      str[from] = str[to];
      str[to] = temp;
      from++;
      to--;
    }
  }

  void rotateString(string &str, int offset) {
    if (0 == str.size() || offset < 0) {
      return;
    }
    int len = str.size();
    offset = offset % len;
    rotateUtil(str, 0, len - 1);
    rotateUtil(str, 0, offset - 1);
    rotateUtil(str, offset, len - 1);
  }
};

int main() {
  string str = "abcdefgh";
  cout << "str:" << str << endl;
  Solution sl;
  sl.rotateString(str, 15);
  cout << "rotate string:" << str << endl;
  return 0;
}
