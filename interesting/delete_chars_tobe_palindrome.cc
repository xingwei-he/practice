/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:delete_chars_tobe_palindrome.cc
 * Author:
 * Mail:
 * Created Time:星期三  3/ 7 17:18:27 2018
 ***************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * 给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
 * 输出需要删除的字符个数。
 *
 * 输入描述:
 * 输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.
 *
 * 输出描述:
 * 对于每组数据，输出一个整数，代表最少需要删除的字符个数。
 *
 * 输入例子:
 * abcda
 * google
 *  
 * 输出例子:
 * 2
 * 2
 * 思路：
 * 求字符串s与其繁转字符串rs的最长公共子序列，则结果就是回文字符串。
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

  int deleteCharsTobePalindrome(const string& str) {
    string rs = getReversedString(str);
    int lcs = getLCSLength(str, rs);
    return str.size() - lcs;
  }
};

int main() {
  string str = "abbcad";
  Solution sl;
  int res = sl.deleteCharsTobePalindrome(str);
  cout << "res:"<< res << endl;
  return 0;
}
