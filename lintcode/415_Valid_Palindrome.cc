/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:415_Valid_Palindrome.cc
 * Author:
 * Mail:
 * Created Time:星期四  1/ 4 18:09:05 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *
 * Notice
 *   Have you consider that the string might be empty? This is a good question to ask during an interview.
 *   For the purpose of this problem, we define empty string as valid palindrome.
 *
 * Example
 *   "A man, a plan, a canal: Panama" is a palindrome.
 *   "race a car" is not a palindrome.
 */

class Solution {
public:
  /*
   * @param s: A string
   * @return: Whether the string is a valid palindrome
   */
  bool isAlphanumericChar(const char& c) {
    if ((c >= '0' && c <= '9') ||
	(c >= 'a' && c <= 'z') ||
	(c >= 'A' && c <= 'Z')) {
      return true;
    }
    return false;
  }

  bool isPalindrome(string &s) {
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
      while (left < right && !isAlphanumericChar(s[left])) {
	left++;
      }
      while (left < right && !isAlphanumericChar(s[right])) {
	right--;
      }
      if (s[left] == s[right] || s[left] + 32 == s[right] || s[left] - 32 == s[right]) {
	left++;
	right--;
      } else {
	return false;
      }
    }
    return true;
  }
};

int main() {
  string str = "A man, a plan, a canal: Panama";
  cout << "str:" << str << endl;
  Solution sl;
  bool res = sl.isPalindrome(str);
  cout << "res:" << boolalpha << res << endl;
  return 0;
}
