/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:77_Longest_Common_Subsequence.cc
 * Author:
 * Mail:
 * Created Time:星期四  1/18 13:02:51 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given two strings, find the longest common subsequence (LCS).
 * Your code should return the length of LCS.
 *
 * Example
 * For "ABCD" and "EDCA", the LCS is "A" (or "D", "C"), return 1.
 * For "ABCD" and "EACB", the LCS is "AC", return 2.
 */

class Solution {
public:
  /*
   * @param A: A string
   * @param B: A string
   * @return: The length of longest common subsequence of A and B
   */
  // DP
  int longestCommonSubsequence(string &A, string &B) {
    if (A.empty() || B.empty()) {
      return 0;
    }
    int row_size = A.size() + 1;
    int col_size = B.size() + 1;
    vector<vector<int> > dp(row_size, vector<int>(col_size, 0));
    for (int i = 1; i < row_size; i++) {
      for (int j = 1; j < col_size; j++) {
	if (A[i - 1] == B[j - 1]) {
	  dp[i][j] = dp[i - 1][j - 1] + 1;
	} else {
	  dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
	}
      }
    }
    return dp[row_size - 1][col_size - 1];
  }
};

int main() {
  return 0;
}
