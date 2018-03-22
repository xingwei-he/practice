/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:683_Word_Break_III.cc
 * Author:
 * Mail:
 * Created Time:星期四  3/22 15:54:21 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Give a dictionary of words and a sentence with all whitespace removed, return the number of sentences you can form by inserting whitespaces to the sentence so that each word can be found in the dictionary.
 *
 * Notice
 *   Ignore case
 *
 * Example
 *   Given a String CatMat
 *   Given a dictionary ["Cat", "Mat", "Ca", "tM", "at", "C", "Dog", "og", "Do"]
 *   return 3
 *   we can form 3 sentences, as follows:
 *   CatMat = Cat Mat
 *   CatMat = Ca tM at
 *   CatMat = C at Mat
 */

class Solution {
public:
  /*
   * @param : A string
   * @param : A set of word
   * @return: the number of possible sentences.
   */
  // Time Limit Exceeded
  string toLowerCase(string s) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] >= 65 && s[i] <= 90) {
	s[i] += 32;
      }
    }
    return s;
  }
  int wordBreak3(string& s, unordered_set<string>& dict) {
    int res = 0;
    if (s.size() <= 0 || dict.size() <= 0) {
      return 0;
    }
    vector<string> segs;
    vector<bool> can_break(s.size() + 1, true);

    string local_s = toLowerCase(s);
    unordered_set<string> local_dict;
    for (unordered_set<string>::iterator iter = dict.begin();
	 iter != dict.end();
	 iter++) {
      local_dict.insert(toLowerCase(*iter));
    }
    dfs(local_s, local_dict, segs, res, 0, can_break);
    return res;
  }
  void dfs(
      string& s,
      unordered_set<string>& dict,
      vector<string>& segs,
      int& res,
      int index,
      vector<bool>& can_break) {
    int len = s.size();
    if (index == len) {
      res++;
      return;
    }
    if (!can_break[index]) {
      return;
    }
    for (int i = index; i < len; i++) {
      string one_seg = s.substr(index, i - index + 1);
      if (dict.find(one_seg) == dict.end()) {
	continue;
      }
      segs.push_back(one_seg);
      int res_before = res;
      dfs(s, dict, segs, res, i + 1, can_break);
      if (res_before == res) {
	can_break[i + 1] = false;
      }
      segs.pop_back();
    }
  }
};

int main() {
  string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  string dict_arr[] = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
  vector<string> dict_vec(dict_arr, dict_arr + sizeof(dict_arr)/sizeof(string));
  unordered_set<string> dict(dict_vec.begin(), dict_vec.end());
  Solution sl;
  int res = sl.wordBreak3(s, dict);
  cout << res << endl;
  return 0;
}
