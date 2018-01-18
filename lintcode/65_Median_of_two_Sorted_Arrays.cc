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
  /**
    对于一个长度为 n 的已排序数列 arr，若 n 为奇数，中位数为 arr[n/2 + 1]，
    若 n 为偶数，则中位数为 (arr[n/2] + arr[n/2 + 1]) / 2
    如果我们可以在两个数列中求出第 K 小的元素，便可以解决该问题
    不妨设数列 A 元素个数为 n1，数列 B 元素个数为 n2，各自升序排序，求第 k 小元素
    取 A[k/2] 和 B[k/2] 比较，
    如果 A[k/2] > B[k/2] 那么，所求的元素必然不在 B 的前 k/2 个元素中(证明反证法)
    反之，必然不在 A 的前 k/2 个元素中，于是我们可以将 A 或 B 数列的前 k/2 元素删去，求剩下两个数列的
    k - k/2 小元素，于是得到了数据规模变小的同类问题，递归解决
    如果 k/2 大于某数列个数，所求元素必然不在另一数列的前 k/2 个元素中，同上操作就好。
   */
  double findKth(vector<int>& nums1, int p1, vector<int>& nums2, int p2, int k) {
    // 参数 p1 和 p2 分别表示两个数列的起始位置（position，起始值为 0），而 k 表示第几个，起始值为 1 而不是 0
    // 当 p1 或 p2 超过数列长度时，则只需返回另一个数列的第 k 个元素即可
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
