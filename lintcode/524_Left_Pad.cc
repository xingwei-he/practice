/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:524_Left_Pad.cc
 * Author:
 * Mail:
 * Created Time:星期五  1/ 5 17:51:27 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * You know what, left pad is javascript package and referenced by React: 
 * One day his author unpublished it, then a lot of javascript projects in the world broken.
 * You can see from github it's only 11 lines.
 * You job is to implement the left pad function. If you do not know what left pad does, see examples below and guess.
 *
 * Example
 * leftpad("foo", 5)
 * >> "  foo"
 * leftpad("foobar", 6)
 * >> "foobar"
 * leftpad("1", 2, "0")
 * >> "01"
 */

class StringUtils {
public:
  /*
   * @param originalStr: the string we want to append to
   * @param size: the target length of the string
   * @param padChar: the character to pad to the left side of the string
   * @return: A string
   */
  static string leftPad(string &originalStr, int size, char padChar=' ') {
    if (originalStr.size() >= size) {
      return originalStr;
    }
    int original_size = originalStr.size();
    originalStr.resize(size);
    int i = 0, j = 0;
    for (i = original_size - 1, j = size - 1; i >= 0; i--, j--) {
      originalStr[j] = originalStr[i];
    }
    while (j >= 0) {
      originalStr[j] = padChar;
      j--;
    }
    return originalStr;
  }
};

int main() {
  string s = "abc";
  int size = 5;
  char pad_char = '_';
  StringUtils sl;
  string res = sl.leftPad(s, size, pad_char);
  cout << res << endl;
  return 0;
}
