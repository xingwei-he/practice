/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:407_Plus_One.cc
 * Author:
 * Mail:
 * Created Time:星期四  1/ 4 16:00:02 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a non-negative number represented as an array of digits, plus one to the number.
 * The digits are stored such that the most significant digit is at the head of the list.
 *
 * Example
 * Given [1,2,3] which represents 123, return [1,2,4].
 * Given [9,9,9] which represents 999, return [1,0,0,0].
 */

class Solution {
public:
  /*
   * @param digits: a number represented as an array of digits
   * @return: the result
   */
  vector<int> plusOne(vector<int> &digits) {
    vector<int> res;
    if (digits.size() == 0) {
      return res;
    }
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; i--) {
      int sum = digits[i] + carry;
      carry = sum / 10;
      digits[i] = sum % 10;
    }
    if (carry > 0) {
      res.push_back(carry);
    }
    for (int i = 0; i < digits.size(); i++) {
      res.push_back(digits[i]);
    }
    return res;
  }
};

int main() {
  int arr[] = {9,9,9};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  vector<int> res = sl.plusOne(nums);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << "  ";
  }
  cout << endl;
  return 0;
}

