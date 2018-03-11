/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:deduplicate_chars.cc
 * Author:
 * Mail:
 * Created Time:星期五  3/ 9 14:33:06 2018
 ***************************************************/
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/**
 * 题目描述:
 *   输入一个字符串，求出该字符串包含的字符集合
 *
 * 输入描述:
 *   每组数据输入一个字符串，字符串最大长度为100，且只包含字母，不可能为空串，区分大小写。
 *
 * 输出描述:
 *   每组数据一行，按字符串原有的字符顺序，输出字符集合，即重复出现并靠后的字母不输出。
 *
 * 输入例子:
 *   abcqweracb
 *
 * 输出例子:
 *   abcqwer
 */

class Solution {
public:
  string deduplicateChars (const string& str) {
    unordered_set<char> char_uset;
    string res;
    for (int i = 0; i < str.size(); i++) {
      if (char_uset.find(str[i]) == char_uset.end()) {
	char_uset.insert(str[i]);
	res.push_back(str[i]);
      }
    }
    return res;
  }
};

int main () {
  string s = "abcqweracb";
  Solution sl;
  string res = sl.deduplicateChars(s);
  cout << "res:" << res << endl;
  if (res == "abcqwer") {
    cout << "OK!" << endl;
  } else {
    cout << "Wrong!" << endl;
  }
  return 0;
}
