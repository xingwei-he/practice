/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:6_Merge_Two_Sorted_Arrays.cc
 * Author:
 * Mail:
 * Created Time:星期五 12/29 12:25:01 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Merge two given sorted integer array A and B into a new sorted integer array.
 *
 * Example
 * A=[1,2,3,4]
 * B=[2,4,5,6]
 * return [1,2,2,3,4,4,5,6]
 */

class Solution {
public:
  /*
   * @param A: sorted integer array A
   * @param B: sorted integer array B
   * @return: A new sorted integer array
   */
  vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
    int lenA = A.size();
    int lenB = B.size();
    A.resize(lenA + lenB);
    int pos = lenA + lenB - 1;
    int i = lenA - 1;
    int j = lenB - 1;
    while (pos >= 0) {
      if (i >= 0 && j >= 0) {
	if (A[i] >= B[j]) {
      	  A[pos] = A[i];
      	  i--;
      	} else if (j >= 0) {
      	  A[pos] = B[j];
      	  j--;
      	}
      } else if (j >= 0) {
	A[pos] = B[j];
	j--;
      }
      pos--;
    }
    return A;
  }
};

int main() {
  int arr_1[] = {1,2,5,8,9};
  int arr_2[] = {2,3,4,6,7,9};
  vector<int> vec_1(arr_1, arr_1 + sizeof(arr_1)/sizeof(int));
  vector<int> vec_2(arr_2, arr_2 + sizeof(arr_2)/sizeof(int));
  Solution sl;
  vector<int> res = sl.mergeSortedArray(vec_1, vec_2);
  for (int i = 0; i < res.size(); i++) {
    cout << res.at(i) << "  ";
  }
  cout << endl;
  return 0;
}

