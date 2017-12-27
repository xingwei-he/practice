/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:646_First_Position_Unique_Character.cc
 * Author:
 * Mail:
 * Created Time:星期三 12/27 10:37:21 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
 *
 * Example
 * Given s = "lintcode", return 0.
 * Given s = "lovelintcode", return 2.
 */

class Solution {
public:
  /*
   * @param s: a string
   * @return: it's index
   */
  int firstUniqChar(string &s) {
    if (s.size() == 0) {
      return -1;
    }
    int pos = -1;
    unordered_map<char, int> umap;
    for (int i = 0; i < s.size(); i++) {
      if (umap.find(s[i]) != umap.end()) {
	umap[s[i]] += 1;
      } else {
	umap.insert(pair<char, int>(s[i], 1));
      }
    }
    for (int i = 0; i < s.size(); i++) {
      if (umap.find(s[i]) != umap.end() && 1 == umap[s[i]]) {
	pos = i;
	break;
      }
    }
    return pos;
  }
};

int main() {
  string s = "lovelintcode";
  Solution sl;
  int pos = sl.firstUniqChar(s);
  cout << "s:" << s << endl;
  cout << "pos:" << pos << endl;
  return 0;
}
