/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:548_Intersection_of_Two_Arrays_II.cc
 * Author:
 * Mail:
 * Created Time:2018年01月06日 星期六 21时27分01秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given two arrays, write a function to compute their intersection.
 *
 * Notice
 *   Each element in the result should appear as many times as it shows in both arrays.
 *   The result can be in any order.
 *
 * Example
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 */

class Solution {
public:
  /*
   * @param nums1: an integer array
   * @param nums2: an integer array
   * @return: an integer array
   */
  vector<int> intersection(vector<int> nums1, vector<int> nums2) {
    unordered_map<int, int> umap1;
    for (int i = 0; i < nums1.size(); i++) {
      if (umap1.find(nums1[i]) != umap1.end()) {
	umap1[nums1[i]] += 1;
      } else {
	umap1.insert(pair<int, int>(nums1[i], 1));
      }
    }
    vector<int> res;
    for (int i = 0; i < nums2.size(); i++) {
      if (umap1.find(nums2[i]) != umap1.end()) {
	if (umap1[nums2[i]] > 0) {
	  umap1[nums2[i]] -= 1;
	  res.push_back(nums2[i]);
	}
      }
    }
    return res;
  }
};

int main() {
  return 0;
}
