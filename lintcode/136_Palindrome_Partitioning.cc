/***************************************************
 Xingwei_He All Rights Reserved.
 * File Name:136_Palindrome_Partitioning.cc
 * Author:
 * Mail:
 * Created Time:星期2017年12月10日 星期日 21时47分51秒
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
	    if (j == i + 1 ||
	        matrix[i + 1][j - 1] == 1) {
	      matrix[i][j] = 1;
	    }
	  }
	}
      }
    }
    return matrix;
  }

  /*
  vector<vector<string>> partition(string &s) {

  }
  */
};

int main() {
  //string s("abccbccdedf");
  string s("abba");
  cout << "str:"  << s << endl; 
  vector<vector<int> > matrix;
  Solution sl;
  matrix = sl.initPalindromeMatix(s);
  cout << "初始化 matrix:" << endl;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      cout << matrix[i][j] << "  ";
    }
    cout << endl;
  }

  return 0;
}
