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

class Solution {
public:
  /*
   * @param s: A string
   * @return: A list of lists of string
   */
  vector<vector<int> > initPalindromeMatix(const string& str) {
    int len = str.size();
    // 初始化 matrix
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
    int len = matrix.size();
    int x = 0;
    for (int y = j; y < len; y++) {
      x = i;
      if (matrix[x][y] != 1) {
	continue;
      }
      int rx = x;
      while (x < len) {
	if (matrix[x][y] == 1) {
	  rx = x;
	}
	x++;
      }
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
  string s("a");
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
