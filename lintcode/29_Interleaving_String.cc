/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:29_Interleaving_String.cc
 * Author:
 * Mail:
 * Created Time:星期四 12/21 11:02:07 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given three strings: s1, s2, s3, determine whether s3 is formed by the interleaving of s1 and s2.
 *
 * Example
 * For s1 = "aabcc", s2 = "dbbca"
 *   When s3 = "aadbbcbcac", return true.
 *   When s3 = "aadbbbaccc", return false.
 */

class Solution {
public:
  /*
   * @param s1: A string
   * @param s2: A string
   * @param s3: A string
   * @return: Determine whether s3 is formed by interleaving of s1 and s2
   */
  // DP
  bool isInterleave(string &s1, string &s2, string &s3) {
    if (s1.size() == 0 && s2.size() == 0 && s3.size() == 0) {
      return true;
    }
    int len1 = s1.size();
    int len2 = s2.size();
    int len3 = s3.size();
    if (len3 != (len1 + len2)) {
      return false;
    }
    // dp[i][j]记录s1[0 ~ i] 和 s2[0 ~ j] 能否组成 s3[0 ~ i+j]
    vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= len1; i++) {
      if (s1[i - 1] == s3[i - 1]) {
	dp[i][0] = dp[i - 1][0];
      }
    }
    for (int j = 1; j<= len2; j++) {
      if (s2[j - 1] == s3[j - 1]) {
	dp[0][j] = dp[0][j - 1];
      }
    }
    for (int i = 1; i <= len1; i++) {
      for (int j = 1; j <= len2; j++) {
	if ((s3[i + j - 1] == s1[i - 1] && dp[i - 1][j] == 1) ||
	    (s3[i + j - 1] == s2[j - 1] && dp[i][j - 1] == 1)) {
	  dp[i][j] = 1;
	} else {
	  dp[i][j] = 0;
	}
      }
    }
    if (dp[len1][len2] == 1) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  //string s1 = "aabcc";
  string s1 = "";
  //string s2 = "dbbca";
  string s2 = "a";
  //string s3 = "aadbbcbcac";
  string s3 = "a";
  Solution sl;
  bool is;
  is = sl.isInterleave(s1, s2, s3);
  cout << boolalpha << is << endl;
  return 0;
}

