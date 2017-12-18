/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:64_Merge_Sorted_Array.cc
 * Author:
 * Mail:
 * Created Time:2017年12月18日 星期一 22时47分27秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 *
 * Notice
 * You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
 *
 * Example
 * A = [1, 2, 3, empty, empty], B = [4, 5]
 * After merge, A will be filled as [1, 2, 3, 4, 5]
 */

class Solution {
public:
  /*
   * @param A: sorted integer array A which has m elements, but size of A is m+n
   * @param m: An integer
   * @param B: sorted integer array B which has n elements
   * @param n: An integer
   * @return: nothing
   */
  void mergeSortedArray(int A[], int m, int B[], int n) {
    if (m < 0 || n < 0 || nullptr == A || nullptr == B) {
      return;
    }
    int pos = m + n - 1;
    while (m > 0 && n > 0) {
      if (A[m - 1] > B[n - 1]) {
	A[pos] = A[m - 1];
	m--;
      } else {
	A[pos] = B[n - 1];
	n--;
      }
      pos--;
    }
    while (n > 0) {
      A[pos] = B[n - 1];
      pos--;
      n--;
    }
  }
};

int main() {
  //int A[10] = {1,5,7,8,10};
  int A[6] = {0};
  //int B[5] = {2,3,4,6,9};
  int B[6] = {2,3,4,5,6,10};
  Solution sl;
  sl.mergeSortedArray(A, 0, B, 6);
  for (int i = 0; i < 6; i++) {
    cout << A[i] << "  ";
  }
  cout << endl;
  return 0;
}

