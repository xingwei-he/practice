/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:212_Space_Replacement.cc
 * Author:
 * Mail:
 * Created Time:星期二  1/ 2 19:01:46 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Write a method to replace all spaces in a string with %20. The string is given in a characters array, you can assume it has enough space for replacement and you are given the true length of the string.
 * You code should also return the new length of the string after replacement.
 *
 * Notice
 *   If you are using Java or Python，please use characters array instead of string.
 *
 * Example
 * Given "Mr John Smith", length = 13.
 * The string after replacement should be "Mr%20John%20Smith", you need to change the string in-place and return the new length 17.
 */

class Solution {
public:
  /*
   * @param string: An array of Char
   * @param length: The true length of the string
   * @return: The true length of new string
   */
  int replaceBlank(char string[], int length) {
    if (nullptr == string || length == 0) {
      return 0;
    }
    int counter = 0;
    for (int i = 0; i < length; i++) {
      if (' ' == string[i]) {
	counter++;
      }
    }
    int new_len = length + counter * 2;
    for (int i = length - 1, j = new_len - 1; i < j && i >= 0; i--) {
      if (' ' == string[i]) {
	string[j] = '0';
	string[j - 1] = '2';
	string[j - 2] = '%';
	j -= 3;
      } else {
	string[j] = string[i];
	j -= 1;
      }
    }
    return new_len;
  }
};

int main() {
  char str[] = "please tell me why!";
  Solution sl;
  int len = sl.replaceBlank(str, strlen(str));
  cout << len << endl;
  cout << str << endl;
  return 0;
}

