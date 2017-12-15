/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:53_Reverse_Words_in_a_String.cc
 * Author:
 * Mail:
 * Created Time:星期五 12/15 14:08:27 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given an input string, reverse the string word by word.
 *
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 *
 * Clarification
 * What constitutes a word?
 * A sequence of non-space characters constitutes a word.
 * Could the input string contain leading or trailing spaces?
 * Yes. However, your reversed string should not contain leading or trailing spaces.
 * How about multiple spaces between two words?
 * Reduce them to a single space in the reversed string.
 */

class Solution {
public:
  /*
   * @param s: A string
   * @return: A string
   */
  void reverseString(string& str, int l, int r) {
    if (str.size() == 0) {
      return;
    }
    int left = l;
    int right = r;
    while (left < right) {
      char temp = str[left];
      str[left] = str[right];
      str[right] = temp;
      left++;
      right--;
    }
  }

  string reverseWords(string &s) {
    string res(s);
    int left = 0;
    int right = 0;
    while (left < res.size()) {
      while (left < res.size() && ' ' == res[left]) {
	left++;// 指向的单词首字母
      }
      right = left;
      while (right < res.size() && ' ' != res[right] ) {
	right++;// 指向的是单词末尾字母后的空格
      }
      reverseString(res, left, right - 1);
      left = right;
    }
    reverseString(res, 0, res.size() - 1);

    int l = 0;// 第一个非空格字符位置
    int r = res.size() - 1;// 最后一个非空格字符位置
    while (l < res.size()) {
      if (' ' == res[l]) {
	l++;
      } else {
	break;
      }
    }
    while (r >= 0) {
      if (' ' == res[r]) {
	r--;
      } else {
	break;
      }
    }
    int i = 0;// 合法字符存放位置
    int j = l;// 当前处理的字符位置，遍历范围在[l, r]
    int counter = 0;// 空格计数
    while (j <= r) {
      if (' ' == res[j]) {
	counter++;
	if (1 == counter) {
	  res[i] = res[j];
	  i++;
	}
      } else {
	res[i] = res[j];
	i++;
	counter = 0;
      }
      j++;
    }
    // 最后清除末尾无用数据
    res.erase(res.begin() + i, res.end());

    return res;
  }
};

int main() {
  string str = "    Coders  say   hello  world      ";
  //string str = "world";
  cout << "str:" << endl;
  cout << str << endl;
  Solution sl;
  string res = sl.reverseWords(str);
  cout << "res:" << endl;
  cout << res << endl;

  return 0;
}
