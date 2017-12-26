/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:720_Rearrange_a_String_With_Integers.cc
 * Author:
 * Mail:
 * Created Time:星期二 12/26 18:33:37 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

/**
 * Given a string containing uppercase alphabets and integer digits (from 0 to 9), write a function to return the alphabets in the order followed by the sum of digits.
 *
 * Example
 * Given str = AC2BEW3, return ABCEW5
 * Alphabets in the lexicographic order, followed by the sum of integers(2 and 3).
 */

using namespace std;

class Solution {
public:
  /*
   * @param str: a string containing uppercase alphabets and integer digits
   * @return: the alphabets in the order followed by the sum of digits
   */
  string rearrange(string &str) {
    string res(str);
    if (res.size() == 0 || res.size() == 1) {
      return res;
    }
    int sum = 0;
    int char_counter = 0;
    int digit_counter = 0;
    for (int i = 0; i < res.size(); i++) {
      int min_pos = 0;
      if ('0' <= res[i] && res[i] <= '9') {
	sum += res[i] - '0';
	digit_counter++;
	continue;
      } else if ('A' <= res[i] && res[i] <= 'Z') {
	char_counter++;
	min_pos = i;
      }
      for (int j = i; j < res.size(); j++) {
	if ('A' <= res[j] && res[j] <= 'Z') {
	  if (res[min_pos] > res[j]) {
	    min_pos = j;
	  }
	} else if ('0' <= res[j] && res[j] <= '9') {
	  continue;
	}
      }
      if (i != min_pos) {
	char temp = res[min_pos];
	res[min_pos] = res[i];
	res[i] = temp;
      }
    }
    int real_pos = 0;
    for (int i = 0; i < res.size(); i++) {
      if ('A' <= res[i] && res[i] <= 'Z') {
	res[real_pos] = res[i];
	real_pos++;
      }
    }
    int sum_len = 0;
    int temp_sum = sum;
    while (0 != temp_sum) {
      temp_sum /= 10;
      sum_len++;
    }
    temp_sum = sum;
    int temp_sum_len = sum_len;
    while (0 != temp_sum_len) {
      res[real_pos + temp_sum_len - 1] = '0' + temp_sum % 10;
      temp_sum /= 10;
      temp_sum_len--;
    }
    res.erase(res.begin() + char_counter + sum_len, res.end());
    return res;
  }
};

int main() {
  string str = "BA12F5CD34E";
  cout << "str:" << str << endl;
  Solution sl;
  string res = sl.rearrange(str);
  cout << "res:" << res << endl;
  return 0;
}
