/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:582_Word_Break_II.cc
 * Author:
 * Mail:
 * Created Time:星期四  3/22 12:46:52 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
 * Return all such possible sentences.
 *
 * Example
 *   Gieve s = lintcode,
 *   dict = ["de", "ding", "co", "code", "lint"].
 *   A solution is ["lint code", "lint co de"].
 */

class Solution {
public:
  /*
   * @param s: A string
   * @param wordDict: A set of words.
   * @return: All possible sentences.
   */
  // DFS + 剪枝
  vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
    vector<string> res;
    if (s.size() <= 0 || wordDict.size() <= 0) {
      return res;
    }
    vector<string> path;
    vector<bool> can_break(s.size() + 1, true);
    dfs(s, wordDict, path, res, 0, can_break);
    return res;
  }
  void dfs(
      string& s,
      unordered_set<string>& wordDict,
      vector<string>& path,
      vector<string>& res,
      int index,
      vector<bool>& can_break) {
    int len = s.size();
    if (index == len) {
      debug1DVector<string>(path, 20);
      string one_res;
      for (int i = 0; i < path.size(); i++) {
	one_res.append(path[i]);
	one_res.append(" ");
      }
      res.push_back(one_res.substr(0, one_res.size() - 1));
      return;
    }
    // can_break[i] 表示 s[0~i-1] 能否拆分
    // 此处当 s[0~index-1] 不能拆分时，则直接返回，剪枝
    if (!can_break[index]) {
      return;
    }
    for (int i = index; i < len; i++) {
      string left_str = s.substr(index, i - index + 1);
      if (wordDict.find(left_str) == wordDict.end() || !can_break[i + 1]) {
	continue;
      }
      path.push_back(left_str);
      int size_before = res.size();
      dfs(s, wordDict, path, res, i + 1, can_break);
      if (size_before == res.size()) {// 如果此次 dfs 后没有新的结果填入 res，则剪枝
	can_break[i + 1] = false;
      }
      path.pop_back();
    }
  }

};

int main() {
  string s = "lintcode";
  string dict_arr[] = {"de", "ding", "co", "code", "lint"};
  vector<string> dict_vec(dict_arr, dict_arr + sizeof(dict_arr)/sizeof(string));
  unordered_set<string> dict(dict_vec.begin(), dict_vec.end());
  Solution sl;
  vector<string> res = sl.wordBreak(s, dict);
  debug1DVector<string>(res, 20);
  return 0;
}
