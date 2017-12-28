/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:158_Two_Strings_Are_Anagrams.cc
 * Author:
 * Mail:
 * Created Time:2017年12月28日 星期四 23时43分44秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Write a method anagram(s,t) to decide if two strings are anagrams or not.
 *
 * Clarification
 *
 * What is Anagram?
 *   Two strings are anagram if they can be the same after change the order of characters.
 *
 * Example
 * Given s = "abcd", t = "dcab", return true.
 * Given s = "ab", t = "ab", return true.
 * Given s = "ab", t = "ac", return false.
 */

class Solution {
public:
  /**
   * @param s: The first string
   * @param b: The second string
   * @return true or false
   */
  bool anagram(string s, string t) {
    unordered_map<char, int> umap;
    for (int i = 0; i < s.size(); i++) {
      if (umap.find(s[i]) != umap.end()) {
	umap[s[i]] += 1;
      } else {
	umap.insert(pair<char, int>(s[i], 1));
      }
    }
    for (int i = 0; i < t.size(); i++) {
      if (umap.find(t[i]) != umap.end()) {
	umap[t[i]] -= 1;
      } else {
	return false;
      }
    }
    for (unordered_map<char, int>::iterator iter = umap.begin();
	 iter != umap.end();
	 iter++) {
      if (iter->second != 0) {
	return false;
      }
    }
    return true;
  }
};

int main() {
  return 0;
}

