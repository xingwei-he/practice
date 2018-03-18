/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:119_Edit_Distance.cc
 * Author:
 * Mail:
 * Created Time:2018年03月18日 星期日 18时12分12秒
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 * You have the following 3 operations permitted on a word:
 *   Insert a character
 *   Delete a character
 *   Replace a character
 *
 * Example
 *  Given word1 = "mart" and word2 = "karma", return 3.
 **/

class Solution {
public:
  /**
   * @param word1: A string
   * @param word2: A string
   * @return: The minimum number of steps.
   */
  int minDistance(string &word1, string &word2) {
    int len1 = word1.size();
    int len2 = word2.size();
    vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 0; i <= len1; i++) {
      dp[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
      dp[0][j] = j;
    }
    for (int i = 1; i <= len1; i++) {
      for (int j = 1; j <= len2; j++) {
	if (word1[i - 1] == word2[j - 1]) {
	  dp[i][j] = dp[i - 1][j - 1];
	} else {
	  dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
	}
      }
    }
    return dp[len1][len2];
  }
};

int main() {
  string w1 = "sea";
  string w2 = "ate";
  Solution sl;
  int res = sl.minDistance(w1, w2);
  cout << "res:" << res << endl;
  return 0;
}
