/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:32_Minimum_Window_Substring.cc
 * Author:
 * Mail:
 * Created Time:星期三 12/20 19:45:09 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a string source and a string target, find the minimum window in source which will contain all the characters in target.
 *
 * Notice
 *   If there is no such window in source that covers all characters in target, return the emtpy string "".
 *   If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in source.
 *
 * Clarification
 *   Should the characters in minimum window has the same order in target?
 *   Not necessary.
 *
 * Example
 *   For source = "ADOBECODEBANC", target = "ABC", the minimum window is "BANC"
 */

class Solution {
public:
  /*
   * @param source : A string
   * @param target: A string
   * @return: A string denote the minimum window, return "" if there is no such a string
   */
  // DP
  string minWindow(string &source , string &target) {
    string res("");
    if (source.size() == 0) {
      return res;
    }
    map<char, int> pos;
    for (int i = 0; i < target.size(); i++) {
      target_set.insert(pair<char, int>(target[i], -1));
    }
    int left = -1;
    int right = -1;
    int min = 0;
    for (int i = 0; i < source.size(); i++) {
      if (pos.find(source[i]) != pos.end()) {
	if 
      }
    }
    return res;
  }
};

int main() {
  return 0;
}
