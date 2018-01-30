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
  string minWindow(string &source , string &target) {
    string res("");
    if (source.size() == 0) {
      return res;
    }
    unordered_map<char, int> target_counter;
    for (int i = 0; i < target.size(); i++) {
      if (target_counter.find(target[i]) != target_counter.end()) {
	target_counter[target[i]]++;
      } else {
	target_counter.insert(pair<char, int>(target[i], 1));
      }
    }
    int bingo = 0;
    unordered_map<char, int> source_counter;
    int min_window_size = INT_MAX;
    int min_left = 0, min_right = 0;
    int left = 0, right = 0;
    while (right < source.size()) {
      if (target_counter.find(source[right]) != target_counter.end()) {
	if (source_counter.find(source[right]) != source_counter.end()) {
	  source_counter[source[right]]++;
	} else {
	  source_counter.insert(pair<char, int>(source[right], 1));
	}
	if (source_counter[source[right]] == target_counter[source[right]]) {
	  bingo++;
	}
	if (bingo == target_counter.size()) {
	  while (right - left + 1 >= target.size()) {
	    if (min_window_size > (right - left + 1)) {
	      min_window_size = right - left + 1;
	      min_left = left;
	      min_right = right;
	    }
	    if (source_counter.find(source[left]) != source_counter.end()) {
	      if (source_counter[source[left]] > 0) {
		source_counter[source[left]]--;
	      }
	      if (source_counter[source[left]] == target_counter[source[left]] - 1) {
		bingo--;
	      }
	      if (bingo < target_counter.size()) {
		left++;
		break;
	      }
	    }
	    left++;
	  }
	}
      }
      right++;
    }

    if (min_window_size != INT_MAX) {
      res = source.substr(min_left, min_window_size);
    }
    return res;
  }
};

int main() {
  string s = "adfqeradboaf23098724huhfda923hadf78adfhadfhadfaodiyfas8";
  string t = "dfje89affefy8f";
  cout << "source:" << s << endl;
  cout << "target:" << t << endl;
  Solution sl;
  string min_window = sl.minWindow(s, t);
  cout << "res:" <<  min_window << endl;
  return 0;
}
