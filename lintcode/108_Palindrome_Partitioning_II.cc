/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:108_Palindrome_Partitioning_II.cc
 * Author:
 * Mail:
 * Created Time:星期四  1/25 14:45:07 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a string s, cut s into some substrings such that every substring is a palindrome.
 * Return the minimum cuts needed for a palindrome partitioning of s.
 *
 * Example
 * Given s = "aab",
 * Return 1 since the palindrome partitioning ["aa", "b"] could be produced using 1 cut.
 */

class Solution {
public:
  /**
   * @param s a string
   * @return an integer
   */
  int minCut(string s) {
    int n = s.size();
    vector<vector<int> > dp(n, vector<int>(n, 0));
    // min_cut[i] 表示第 i 个字符到最后一个字符所构成的子串的最小分割次数
    vector<int> min_cut(n + 1, -1);
    for (int i = n - 1; i >= 0; i--) {// 从右下角开始填
      min_cut[i] = INT_MAX;
      for (int j = i; j < n; j++) {
	if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1]) == 1) {
	  dp[i][j] = 1;
	  min_cut[i] = min(1 + min_cut[j + 1], min_cut[i]);
	}
      }
    }
    return min_cut[0];
  }
};

int main() {
  string s = "abbacacbc";
  cout << s << endl;
  Solution sl;
  int res = sl.minCut(s);
  cout << res << endl;
  return 0;
}
