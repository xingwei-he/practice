/***************************************************
 Xingwei_He All Rights Reserved.
 * File Name:491_Palindrome_Number.cc
 * Author:
 * Mail:
 * Created Time:星期2017年12月10日 星期日 13时59分07秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/*
 * Check a positive number is a palindrome or not.
 * A palindrome number is that if you reverse the whole number you will get exactly the same number.
 *  
 * Notice
 * It's guaranteed the input number is a 32-bit integer, but after reversion, the number may exceed the 32-bit integer.
 *
 * Example
 * 11, 121, 1, 12321 are palindrome numbers.
 * 23, 32, 1232 are not palindrome numbers.
 */

class Solution {
public:
  /*
   * @param num: a positive number
   * @return: true if it's a palindrome or false
   */
  bool isPalindrome(int num) {
    vector<int> vec;
    int temp = num;
    while (0 != temp) {
      vec.push_back(temp % 10);
      temp /= 10;
    }
    
    int len = vec.size();
    bool res = true;
    for (int i = 0; i < len/2 ; i++) {
      if (vec[i] != vec[len - i - 1]) {
	res = false;
	break;
      }
    }
    return res;
  }
};

int main() {
  Solution sl;
  cout << boolalpha << sl.isPalindrome(23) << endl;
  return 0;
}
