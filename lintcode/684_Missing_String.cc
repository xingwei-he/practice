/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:684_Missing_String.cc
 * Author:
 * Mail:
 * Created Time:星期二 12/26 16:40:54 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given two strings, you have to find the missing string.
 *
 * Example
 * Given a string str1 = This is an example
 * Given another string str2 = is example
 * Return ["This", "an"]
 */

class Solution {
public:
  /*
   * @param : a given string
   * @param : another given string
   * @return: An array of missing string
   */
  vector<string> missingString(string str1, string str2) {
    vector<string> res;
    unordered_set<string> uset;
    int left = 0;
    int right = 0;
    while (left < str2.size()) {
      left = right;
      while (left < str2.size() && str2[left] == ' ') {
	left++;
      }
      right = left;
      while (right < str2.size() && str2[right] != ' ') {
	right++;
      }
      uset.insert(str2.substr(left, right - left));
    }
    left = 0;
    right = 0;
    while (left < str1.size()) {
      left = right;
      while (left < str1.size() && str1[left] == ' ') {
	left++;
      }
      right = left;
      while (right < str1.size() && str1[right] != ' ') {
	right++;
      }
      string target = str1.substr(left, right - left);
      unordered_set<string>::iterator iter = uset.find(target);
      if (iter == uset.end()) {
	res.push_back(target);
      }
    }
    return res;
  }
};

int main() {
  string str1 = "this is Jilin University";
  string str2 = "this is";
  Solution sl;
  vector<string> missing_strings = sl.missingString(str1, str2);
  for (int i = 0; i < missing_strings.size(); i++) {
    cout << missing_strings.at(i) << endl;
  }
  return 0;
}

