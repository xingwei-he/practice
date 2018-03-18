/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:640_Edit_Distance_II.cc
 * Author:
 * Mail:
 * Created Time:2018年03月18日 星期日 21时56分04秒
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given two strings S and T, determine if they are both one edit distance apart.
 *
 * Example
 *   Given s = "aDb", t = "adb"
 *   return true
 */

class Solution {
public:
  /**
   * @param s: a string
   * @param t: a string
   * @return: true if they are both one edit distance apart or false
   */
  bool isOneEditDistance(string &s, string &t) {
    int len1 = s.size();
    int len2 = t.size();
    vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 0; i <= len1; i++) {
      dp[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
      dp[0][j] = j;
    }
    for (int i = 1; i <= len1; i++) {
      for (int j = 1; j <= len2; j++) {
	if (s[i - 1] == t[j - 1]) {
	  dp[i][j] = dp[i - 1][j - 1];
	} else {
	  dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
	}
      }
    }
    return dp[len1][len2] == 1? true : false;
  }
};

int main() {
  string w1 = "aDb";
  string w2 = "adb";
  Solution sl;
  bool res = sl.isOneEditDistance(w1, w2);
  cout << boolalpha << "res:" << res << endl;
  return 0;
}
