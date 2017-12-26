/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:702_Concatenated_String_with_Uncommon_Characters_of_Two_Strings.cc
 * Author:
 * Mail:
 * Created Time:2017年12月26日 星期二 22时57分53秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Two strings are given and you have to modify 1st string such that all the common characters of the 2nd strings have to be removed and the uncommon characters of the 2nd string have to be concatenated with uncommon characters of the 1st string.
 *
 * Example

 * Given s1 = aacdb, s2 = gafd
 * return cbgf

 * Given s1 = abcs, s2 = cxzca;
 * return bsxz
 */

class Solution {
public:
  /*
   * @param : the 1st string
   * @param : the 2nd string
   * @return: uncommon characters of given strings
   */
  string concatenetedString(string &s1, string &s2) {
    unordered_map<char, int> umap;
    for (int i = 0; i < s1.size(); i++) {
      umap.insert(pair<char, int>(s1[i], 1));
    }
    for (int i = 0; i < s2.size(); i++) {
      if (umap.find(s2[i]) != umap.end() && umap[s2[i]] != 2) {
	umap[s2[i]] = 0;
      } else {
	umap.insert(pair<char, int>(s2[i], 2));
      }
    }
    string res;
    for (int i = 0; i < s1.size(); i++) {
      if (umap.at(s1[i]) == 0) {
	continue;
      } else {
	res.push_back(s1[i]);
      }
    }
    for (int i = 0; i < s2.size(); i++) {
      if (umap.at(s2[i]) == 0) {
	continue;
      } else {
	res.push_back(s2[i]);
      }
    }
    return res;
  }
};

int main() {
  string s1 = "aacdb";
  string s2 = "gafd";
  cout << "s1:" << s1 << endl;
  cout << "s2:" << s2 << endl;
  Solution sl;
  string res = sl.concatenetedString(s1, s2);
  cout << "res:" << res << endl;
  return 0;
}


