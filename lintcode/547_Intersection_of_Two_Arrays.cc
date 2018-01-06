/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:547_Intersection_of_Two_Arrays.cc
 * Author:
 * Mail:
 * Created Time:2018年01月06日 星期六 15时43分15秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given two arrays, write a function to compute their intersection.
 *
 * Notice
 *   Each element in the result must be unique.
 *   The result can be in any order.

 * Example
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

 **/

class Solution {
public:
  /*
   * @param nums1: an integer array
   * @param nums2: an integer array
   * @return: an integer array
   */
  vector<int> intersection(vector<int> nums1, vector<int> nums2) {
    unordered_set<int> uset1;
    for (int i = 0; i < nums1.size(); i++) {
      uset1.insert(nums1[i]);
    }
    unordered_set<int> uset2;
    for (int i = 0; i < nums2.size(); i++) {
      uset2.insert(nums2[i]);
    }
    vector<int> res;
    for (unordered_set<int>::iterator iter1 = uset1.begin(); iter1 != uset1.end(); iter1++) {
      if (uset2.find(*iter1) != uset2.end()) {
	res.push_back(*iter1);
      }
    }
    return res;
  }
};

int main() {
  return 0;
}
