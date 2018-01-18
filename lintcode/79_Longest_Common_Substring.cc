/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:79_Longest_Common_Substring.cc
 * Author:
 * Mail:
 * Created Time:星期四  1/18 13:54:57 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given two strings, find the longest common substring.
 * Return the length of it.
 *
 * Notice
 *   The characters in substring should occur continuously in original string. This is different with subsequence.
 *
 * Example
 * Given A = "ABCD", B = "CBCE", return 2.
 */

class Solution {
public:
  /*
   * @param A: A string
   * @param B: A string
   * @return: the length of the longest common substring.
   */
  int longestCommonSubstring(string &A, string &B) {
    if (A.empty() || B.empty()) {
      return 0;
    }
    int row_size = A.size() + 1;
    int col_size = B.size() + 1;
    vector<vector<int> > dp(row_size, vector<int>(col_size, 0));
    int max_len = 0;
    for (int i = 1; i < row_size; i++) {
      for (int j = 1; j < col_size; j++) {
	if (A[i - 1] == B[j - 1]) {
	  dp[i][j] = dp[i - 1][j - 1] + 1;
	  if (max_len < dp[i][j]) {
	    max_len = dp[i][j];
	  }
	}
      }
    }
    return max_len;
  }
};

int main() {
  string s1 = "www.lintcode.com code";
  string s2 = "www.ninechapter.com code";
  cout << "s1:" << s1 << endl;
  cout << "s2:" << s2 << endl;
  Solution sl;
  int res = sl.longestCommonSubstring(s1, s2);
  cout << "res:" << res << endl;
  return 0;
}
