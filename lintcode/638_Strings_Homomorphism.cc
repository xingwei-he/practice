/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:638_Strings_Homomorphism.cc
 * Author:
 * Mail:
 * Created Time:星期三 12/27 10:14:15 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given two strings s and t, determine if they are isomorphic.
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 *
 * Notice
 * You may assume both s and t have the same length.
 *
 * Example
 * Given s = "egg", t = "add", return true.
 * Given s = "foo", t = "bar", return false.
 * Given s = "paper", t = "title", return true.
 */

class Solution {
public:
  /*
   * @param s: a string
   * @param t: a string
   * @return: true if the characters in s can be replaced to get t or false
   */
  bool isIsomorphic(string s, string t) {
    bool res = false;

    unordered_map<char, int> umap;
    int id = 1;
    string s_shape;
    for (int i = 0; i < s.size(); i++) {
      if (umap.find(s[i]) != umap.end()) {
	s_shape.push_back(umap[s[i]]);
      } else {
	umap.insert(pair<char, int>(s[i], id));
	id++;
      }
    }
    umap.clear();

    id = 1;
    string t_shape;
    for (int i = 0; i < t.size(); i++) {
      if (umap.find(t[i]) != umap.end()) {
	t_shape.push_back(umap[t[i]]);
      } else {
	umap.insert(pair<char, int>(t[i], id));
	id++;
      }
    }

    if (s_shape.compare(t_shape) == 0) {
      res = true;
    } else {
      res = false;
    }
    return res;
  }
};

int main() {
  string s = "abbcdeddf";
  string t = "bqqamcmmz";
  Solution sl;
  bool res = sl.isIsomorphic(s, t);
  cout << "s:" << s << endl;
  cout << "t:" << t << endl;
  cout << "res:" << boolalpha << res << endl;
  return 0;
}
