/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:add_one_char_tobe_palindrome.cc
 * Author:
 * Mail:
 * Created Time:星期四  3/ 8 18:33:35 2018
 ***************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * 题目描述:
 *   给定一个字符串，问是否能通过添加一个字母将其变为回文串。
 *
 * 输入描述:
 *   一行一个由小写字母构成的字符串，字符串长度小于等于10。
 * 输出描述:
 *   输出答案(YES\NO).
 *
 * 输入例子:
 *   coco
 * 输出例子:
 *   YES
 * 思路：
 *   求字符串s与其繁转字符串rs的最长公共子序列，则结果就是回文字符串。
 */

class Solution {
public:
  string getReversedString(const string& str) {
    string rs;
    for (int i = str.size() - 1; i >= 0; i--) {
      rs.append(str, i, 1);
    }
    return rs;
  }

  // get length of Longest Common Substring
  int getLCSLength(const string& a, const string& b) {
    if (a.empty() || b.empty()) {
      return 0;
    }
    int row_size = a.size() + 1;
    int col_size = b.size() + 1;
    vector<vector<int> > dp(row_size, vector<int>(col_size, 0));
    for (int i = 1; i < row_size; i++) {
      for (int j = 1; j < col_size; j++) {
	if (a[i - 1] == b[j - 1]) {
	  dp[i][j] = dp[i - 1][j - 1] + 1;
	} else {
	  dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
	}
      }
    }
    return dp[row_size - 1][col_size - 1];
  }

  bool check(const string& str) {
    string rs = getReversedString(str);
    int lcs = getLCSLength(str, rs);
    if (str.size() - lcs == 1) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  string str = "coco";
  Solution sl;
  bool res = sl.check(str);
  cout << boolalpha << res << endl;
  return 0;
}
