/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:211_String_Permutation.cc
 * Author:
 * Mail:
 * Created Time:星期二  1/ 2 18:24:12 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given two strings, write a method to decide if one is a permutation of the other.
 *
 * Example
 * abcd is a permutation of bcad, but abbe is not a permutation of abe
 */

class Solution {
public:
  /*
   * @param A: a string
   * @param B: a string
   * @return: a boolean
   */
  bool Permutation(string &A, string &B) {
    if (A.size() != B.size()) {
      return false;
    } else if (A.size() == 0 && B.size() == 0) {
      return true;
    }
    unordered_map<char, int> umap;
    for (int i = 0; i < A.size(); i++) {
      if (umap.find(A[i]) != umap.end()) {
	umap[A[i]] += 1;
      } else {
	umap.insert(pair<char, int>(A[i], 1));
      }
    }

    for (int i = 0; i < B.size(); i++) {
      if (umap.find(B[i]) != umap.end()) {
	umap[B[i]] -= 1;
	if (0 == umap[B[i]]) {
	  umap.erase(B[i]);
	}
      } else {
	return false;
      }
    }
    if (umap.size() == 0) {
      return true;
    } else {
      return false;
    }
    /*
    for (int i = 0; i < B.size(); i++) {
      if (umap.find(B[i]) != umap.end()) {
	if (0 == umap[B[i]]) {
	  return false;
	} else {
	  umap[B[i]] -= 1;
	}
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
    */
  }
};

int main() {
  return 0;
}

