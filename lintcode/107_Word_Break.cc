/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:107_Word_Break.cc
 * Author:
 * Mail:
 * Created Time:星期五  1/12 14:39:44 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a string s and a dictionary of words dict, determine if s can be break into a space-separated sequence of one or more dictionary words.
 *
 * Example
 * Given s = "lintcode", dict = ["lint", "code"].
 * Return true because "lintcode" can be break as "lint code".
 */

class Solution {
public:
  /*
   * @param s: A string
   * @param dict: A dictionary of words dict
   * @return: A boolean
   */
  /*
  // Time Limit Exceeded
  // DP
  bool wordBreak(string &s, unordered_set<string> &dict) {
    if (s.size() == 0) {
      return true;
    }
    if (dict.empty()) {
      return false;
    }
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++) {
      for (int j = 0; j < i; j++) {
	if (true== dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
	  dp[i] = true;
	  break;
	}
      }
    }
    return dp.back();
  }
  */

  // DP
  int getMaxLength(unordered_set<string>& dict) {
    int max_length = 0;
    for (unordered_set<string>::iterator iter = dict.begin(); iter != dict.end(); iter++) {
      max_length = max_length > iter->size() ? max_length : iter->size();
    }
    return max_length;
  }
  bool wordBreak(string s, unordered_set<string> &dict) {
    int max_length = getMaxLength(dict);
    // 用 seg[i] 记录 s[0]~s[i-1] 是否可以被分割，其中 s[0] 初始化为 true
    vector<bool> seg(s.size() + 1, false);
    seg[0] = true;
    for (int i = 1; i <= s.size(); i++) {
      for (int j = 1; j <= max_length && j <= i; j++) {
	if (!seg[i - j]) {
	  continue;
	}
	string sub_str = s.substr(i - j, j);
	if (dict.find(sub_str) != dict.end()) {
	  seg[i] = true;
	  break;
	}
      }
    }
    return seg[s.size()];
  }
};

int main() {
  string s = "aaab";
  string arr[] = {"b", "aa", "aaa"};
  int n = 3;
  vector<string> vec;
  for (int i = 0; i < n; i++) {
    vec.push_back(arr[i]);
  }
  //unordered_set<string> dict(vec.begin(), vec.end());
  unordered_set<string> dict;
  for (int i = 0; i < vec.size(); i++) {
    dict.insert(vec[i]);
  }
  Solution sl;
  bool res = sl.wordBreak(s, dict);
  cout << boolalpha << "res:" << res << endl;
  return 0;
}
