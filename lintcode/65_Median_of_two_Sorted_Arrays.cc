/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:65_Median_of_two_Sorted_Arrays.cc
 * Author:
 * Mail:
 * Created Time:星期三  1/17 18:39:14 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays.
 *
 * Example
 * Given A=[1,2,3,4,5,6] and B=[2,3,4,5], the median is 3.5.
 * Given A=[1,2,3] and B=[4,5], the median is 3.
 */

class Solution {
public:
  /*
   * @param A: An integer array
   * @param B: An integer array
   * @return: a double whose format is *.5 or *.0
   */
  double findKth(vector<int>& nums1, int p1, vector<int>& nums2, int p2, int k) {
    if (p1 >= nums1.size()) {
      return nums2[p2 + k - 1];
    }
    if (p2 >= nums2.size()) {
      return nums1[p1 + k - 1];
    }
    // 当 k 为 1 时，表示取最小值
    if (1 == k) {
      return nums1[p1] < nums2[p2] ? nums1[p1] : nums2[p2];
    }
    int key1 = p1 + k/2 - 1 >= nums1.size() ? INT_MAX : nums1[p1 + k/2 - 1];
    int key2 = p2 + k/2 - 1 >= nums2.size() ? INT_MAX : nums2[p2 + k/2 - 1];
    if (key1 < key2) {
      return findKth(nums1, p1 + k/2, nums2, p2, k - k/2);
    } else {
      return findKth(nums1, p1, nums2, p2 + k/2, k - k/2);
    }
  }

  double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
    int len1 = A.size();
    int len2 = B.size();
    int len = len1 + len2;
    double res;
    if (len & 1) {
      res = findKth(A, 0, B, 0, len/2 + 1);
    } else {
      res = (findKth(A, 0, B, 0, len/2) + findKth(A, 0, B, 0, len/2 + 1)) / 2.0;
    }
    return res;
  }
};

int main() {
  return 0;
}
