/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:718_Repeat_String.cc
 * Author:
 * Mail:
 * Created Time:星期四  3/15 16:42:28 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Write a function, give a string A consisting of N characters and a string B consisting of M characters, returns the number of times A must be stated such that B is a substring of the repeated string. If B can never be a substring of the repeated A, then your function should return -1.
 *
 * Notice
 *   Assume that 0 <= N <= 1000, 1 <= M <= 1000
 *
 * Example
 *   Given A = abcd, B = cdabcdab
 *   your function should return 3, bcause after stating string A three times we obtain the string abcdabcdabcd. String B is a substring of this string.
 */

class Solution {
public:
  /**
   * @param A: string A to be repeated
   * @param B: string B
   * @return: the minimum number of times A has to be repeated
   */
  int repeatedString(string &A, string &B) {
    if (A.size() <= 0) {
      return -1;
    }
    int res = 1;
    string str = A;
    while (str.size() < B.size()) {
      str.append(A);
      res += 1;
    }
    if (str.find(B) != string::npos) {
      return res;
    }
    str.append(A);
    res += 1;
    if (str.find(B) != string::npos) {
      return res;
    } else {
      return -1;
    }
  }
};

int main() {
  string A = "abcd";
  string B = "cdabcdab";
  Solution sl;
  int res = sl.repeatedString(A, B);
  cout << res << endl;
  return 0;
}
