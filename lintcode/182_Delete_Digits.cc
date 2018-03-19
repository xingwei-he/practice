/**************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:182_Delete_Digits.cc
 * Author:
 * Mail:
 * Created Time:星期一  3/19 18:31:29 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given string A representative a positive integer which has N digits, remove any k digits of the number, the remaining digits are arranged according to the original order to become a new positive integer.
 * Find the smallest integer after remove k digits.
 * N <= 240 and k <= N,
 *
 * Example
 *   Given an integer A = "178542", k = 4
 *   return a string "12"
 */

class Solution {
public:
  /**
   * @param A: A positive integer which has N digits, A is a string
   * @param k: Remove k digits
   * @return: A string
   */
  // 删除 str 的第 k 个字符，取值范围 [0, str.size() - 1]
  string removeKthChar(string str, int k) {
    string res = str.substr(0, k) + str.substr(k + 1, str.size() - k - 1);
    return res;
  }
  
  string DeleteDigits(string &A, int k) {
    int len = A.size();
    if (len == k) {
      return "";
    }
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < len; j++) {
	if (j == len - 1 || A[j] > A[j + 1]) {// 如果是最后一个或者当前元素比后面元素大则删除
	  A = removeKthChar(A, j);
	  break;
	}
      }
    }
    int i = 0;
    while (i < len - 1 && A[i] == '0') {// 删掉前边的 0
      i++;
    }
    return A.substr(i, len - i);
  }
};

int main() {
  string str = "123332432";
  int k = 2;
  Solution sl;
  string res = sl.DeleteDigits(str, k);
  cout << res << endl;
  return 0;
}
