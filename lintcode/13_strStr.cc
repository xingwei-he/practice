/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:13_strStr.cc
 * Author:
 * Mail:
 * Created Time:星期五 12/29 14:28:35 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * For a given source string and a target string, you should output the first index(from 0) of target string in source string.
 * If target does not exist in source, just return -1.
 *
 * Clarification
 * Do I need to implement KMP Algorithm in a real interview?
 *
 * Not necessary. When you meet this problem in a real interview, the interviewer may just want to test your basic implementation ability. But make sure you confirm with the interviewer first.
 *
 * Example
 * If source = "source" and target = "target", return -1.
 * If source = "abcdabcdefg" and target = "bcd", return 1.
 */

class Solution {
public:
  /*
   * @param source: source string to be scanned.
   * @param target: target string containing the sequence of characters to match
   * @return: a index to the first occurrence of target in source, or -1  if target is not part of source.
   */
  int strStr(const char *source, const char *target) {
    if (nullptr == source || nullptr == target) {
      return -1;
    }
    int len_src = strlen(source);
    int len_tar = strlen(target);
    int pos = -1;
    if (0 == len_tar) {
      return 0;
    } else if (len_src < len_tar) {
      return -1;
    }
    for (int i = 0; i <= len_src - len_tar; i++) {
      int j = i;
      int k = 0;
      while (k < len_tar && source[j] == target[k]) {
	if (k == len_tar - 1) {
	  pos = i;
	  return pos;
	}
	j++;
	k++;
      }
    }
    return pos;
  }
};

int main() {
  string src = "abcdabcdefg";
  string tar = "bcd";
  Solution sl;
  int pos = sl.strStr(src.c_str(), tar.c_str());
  cout << pos << endl;
  return 0;
}
