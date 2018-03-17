/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:183_Wood_Cut.cc
 * Author:
 * Mail:
 * Created Time:2018年03月17日 星期六 18时16分07秒
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given n pieces of wood with length L[i] (integer array). Cut them into small pieces to guarantee you could have equal or more than k pieces with the same length. What is the longest length you can get from the n pieces of wood? Given L & k, return the maximum length of the small pieces.
 *
 * Notice
 *   You couldn't cut wood into float length.
 *   If you couldn't get >= k pieces, return 0.
 *
 * Example
 *   For L=[232, 124, 456], k=7, return 114.
 */

class Solution {
public:
  /**
   * @param L: Given n pieces of wood with length L[i]
   * @param k: An integer
   * @return: The maximum length of the small pieces
   */
  // check 函数用于检查 len 是否满足约束条件
  bool check(vector<int>& L, const int& k, const long& len) {
    long counter = 0;
    for (int i = 0; i < L.size(); i++) {
      counter += L[i] / len;
    }
    return counter >= k;
  }

  int woodCut(vector<int> &L, int k) {
    if (L.size() == 0) {
      return 0;
    }
    long sum = 0;
    for (int i = 0; i < L.size(); i++) {
      sum += L[i];
    }
    if (sum < k) {
      return 0;
    }
    long len = *max_element(L.begin(), L.end());// len 记录最大的木材长度
    // 用二分查找搜索一个满足要求的长度，范围是[1, len]
    long left = 1;
    long right = len;
    long mid = 0;
    while (left <= right) {
      mid = (left + right) / 2;
      if (check(L, k, mid)) {// 当 mid 满足约束条件时，left 记录 mid + 1，所以在最后返回 left - 1
	left = mid + 1;
      } else {
	right = mid - 1;
      }
    }
    return left - 1;
  }
};

int main() {
  int arr[] = {232, 124, 456};
  vector<int> L(arr, arr + sizeof(arr)/sizeof(int));
  //int k = 7;
  int k = 5;
  Solution sl;
  int res = sl.woodCut(L, k);
  cout << "res:" << res << endl;
  return 0;
}
