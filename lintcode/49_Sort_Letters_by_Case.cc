/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:49_Sort_Letters_by_Case.cc
 * Author:
 * Mail:
 * Created Time:星期三  1/17 10:31:06 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a string which contains only letters. Sort it by lower case first and upper case second.
 *
 * Notice
 *   It's NOT necessary to keep the original order of lower-case letters and upper case letters.
 *
 * Example
 * For "abAcD", a reasonable answer is "acbAD"
 */

class Solution {
public:
  /*
   * @param chars: The letter array you should sort by Case
   * @return: nothing
   */
  // 利用快速排序的 partition 算法
  void partition(string& chars, int left, int right) {
    char pivot = 'a';
    while (left < right) {
      while (left < right && chars[right] < pivot) {
	right--;
      }
      while (left < right && chars[left] >= pivot) {
	left++;
      }
      char temp = chars[left];
      chars[left] = chars[right];
      chars[right] = temp;
    }
  }

  void sortLetters(string &chars) {
    if (chars.size() == 0) {
      return;
    }
    int left = 0;
    int right = chars.size() - 1;
    partition(chars, left, right);
  }
};

int main() {
  string chars = "abAcdERDsfdEs";
  cout << "chars:" << chars << endl;
  Solution sl;
  sl.sortLetters(chars);
  cout << "sort res:" << chars << endl;
  return 0;
}
