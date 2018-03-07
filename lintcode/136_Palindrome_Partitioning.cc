/***************************************************
 Xingwei_He All Rights Reserved.
 * File Name:136_Palindrome_Partitioning.cc
 * Author:
 * Mail:
 * Created Time:2017年12月10日 星期日 21时47分51秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * Return all possible palindrome partitioning of s.
 *
 * Example
 *   Given s = "aab", return:
 *   [
 *     ["aa","b"],
 *     ["a","a","b"]
 *   ]
 */

class Solution {
public:
  /*
   * @param s: A string
   * @return: A list of lists of string
   */
  vector<vector<int> > initPalindromeMatix(const string& str) {
    int len = str.size();
    // 初始化 matrix
    // 利用 matrix 存储回文子串的结果，1 表示子串 str[i~j] 是一个回文子串
    // 初始化过程从矩阵右下角开始填写
    vector<vector<int> > matrix(len, vector<int>(len, 0));
    for (int i = len - 1; i >= 0; i--) {
      for (int j = i; j < len; j++) {
	if (i == j) {
	  matrix[i][j] = 1;
	} else {
	  if (str[i] == str[j]) {
	    if (j == i + 1 || matrix[i + 1][j - 1] == 1) {
	      matrix[i][j] = 1;
	    }
	  }
	}
      }
    }
    return matrix;
  }

  void palindromeMatrixDFS(
      string str,
      vector<vector<int> >& matrix, int i, int j,
      vector<vector<string> >& res, vector<string>& one_res) {
    // res：整体的结果
    // one_res：将 str 分割一次的结果
    // 该算法的整体思想是，对 matrix 做 dfs，例如有 str:abcb，则有如下对应的 matrix
    //   1  0  0  0
    //   0  1  0  1
    //   0  0  1  0
    //   0  0  0  1
    // 对此 matrix 进行 dfs 的原则是，先右再下，比如在 2 行，有两个 1，说明在此处产生分支，
    // 每个分支子问题是从 1 往下找另一个 1，如 matrix[1][1] 下没有 1 了，所以这个分支子问题的解就是 "b"，
    // 而另一个分支子问题是在 matrix[1][3]，往下搜索到 matrix[3][3] 是 1，则这个分支子问题的解是 "bcb"
    int len = matrix.size();
    int x = 0;
    for (int y = j; y < len; y++) {
      x = i;
      if (matrix[x][y] != 1) {
	continue;
      }
      // 上面的 if 模块每 continue 一次就 y++ 一次，此时的 matrix[x][y] 是 1，表示 str[x~y] 是一个回文串
      int rx = x;
      while (x < len) {
	if (matrix[x][y] == 1) {
	  rx = x;
	}
	x++;
      }
      // 此时 str[i~rx] 为一个回文子串放入 one_res
      one_res.push_back(str.substr(i, rx - i + 1));
      if (rx == len - 1) {
	res.push_back(one_res);
	/*
	for (int a = 0; a < one_res.size(); a++) {
	  cout << one_res[a] << "\t";
	}
	cout << endl;
	*/
      } else {
	palindromeMatrixDFS(str, matrix, rx + 1, y + 1, res, one_res);
      }
      one_res.pop_back();
    }
  }

  vector<vector<string> > partition(string &s) {
    vector<vector<int> > matrix;
    matrix = initPalindromeMatix(s);
    vector<vector<string> > res;
    vector<string> one_res;
    palindromeMatrixDFS(s, matrix, 0, 0, res, one_res);
    return res;
  }
};

int main() {
  //string s("abccbccdedf");
  string s("abcb");
  //string s("a");
  cout << "str:"  << s << endl; 
  Solution sl;
  vector<vector<int> > matrix = sl.initPalindromeMatix(s);
  cout << "初始化 matrix:" << endl;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      cout << matrix[i][j] << "  ";
    }
    cout << endl;
  }
  cout << "********" << endl;
  vector<vector<string> > res = sl.partition(s);
  cout << "结果 size:" << res.size() << endl;
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
