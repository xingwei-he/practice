/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:55_Compare_Strings.cc
 * Author:
 * Mail:
 * Created Time:星期五 12/15 15:51:31 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Compare two strings A and B, determine whether A contains all of the characters in B.
 * The characters in string A and B are all Upper Case letters.
 *
 * Notice
 * The characters of B in A are not necessary continuous or ordered.
 *
 * Example
 * For A = "ABCD", B = "ACD", return true.
 * For A = "ABCD", B = "AABC", return false.
 */

class Solution {
public:
  /*
   * @param A: A string
   * @param B: A string
   * @return: if string A contains all of the characters in B return true else return false
   */
  bool compareStrings(string &A, string &B) {
    bool res = true;
    map<char, int> recorder;
    for (int i = 0; i < A.size(); i++) {
      if (recorder.find(A[i]) != recorder.end()) {
	recorder[A[i]] += 1;
      } else {
	recorder.insert(pair<char, int>(A[i], 1));
      }
    }
    for (int i = 0; i < B.size(); i++) {
      if (recorder.find(B[i]) == recorder.end()) {
	res = false;
	break;
      } else {
	recorder[B[i]] -= 1;
	if (recorder[B[i]] < 0) {
	  res = false;
	  break;
	}
      }
    }
    return res;
  }

};

int main() {
  string strA = "ABCD";
  string strB = "AABC";
  Solution sl;
  bool res = sl.compareStrings(strA, strB);
  cout << boolalpha << res << endl;
  return 0;
}
