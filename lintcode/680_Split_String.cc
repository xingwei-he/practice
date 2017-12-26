/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:680_Split_String.cc
 * Author:
 * Mail:
 * Created Time:星期二 12/26 13:26:04 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Give a string, you can choose to split the string after one character or two adjacent characters, and make the string to be composed of only one character or two characters. Output all possible results.
 *
 * Example
 * Given the string "123"
 * return [["1","2","3"],["12","3"],["1","23"]]
 */

class Solution {
public:
  /*
   * @param : a string to be split
   * @return: all possible split string array
   */
  vector<vector<string> > splitString(string& s) {
    vector<vector<string> > res;
    if (s.size() == 0) {
      vector<string> temp_vec;
      res.push_back(temp_vec);
      return res;
    }
    if (s.size() >= 1) {
      vector<string> vec;
      vec.push_back(s.substr(0, 1));
      res.push_back(vec);
    }
    for (int i = 1; i < s.size(); i++) {
      vector<vector<string> > temp_res_vec;
      for (int k = 0; k < res.size(); k++) {
	if (res[k].back().size() == 1) {
	  vector<string> temp_vec(res[k]);
	  temp_vec[temp_vec.size() - 1] += s.substr(i, 1);
	  temp_res_vec.push_back(temp_vec);
	}
	res[k].push_back(s.substr(i, 1));
      }
      res.insert(res.end(), temp_res_vec.begin(), temp_res_vec.end());
      /*
      for (int k = 0; k < temp_res_vec.size(); k++) {
	res.push_back(temp_res_vec[k]);
      }
      */
    }
    return res;
  }
};

int main() {
  string s = "abcd";
  Solution sl;
  vector<vector<string> > res = sl.splitString(s);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << "  ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
