/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:82_Single_Number.cc
 * Author:
 * Mail:
 * Created Time:星期四 12/14 19:09:03 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given 2*n + 1 numbers, every numbers occurs twice except one, find it.
 *
 * Example
 * Given [1,2,2,1,3,4,3], return 4
 */

class Solution {
public:
  /*
   * @param A: An integer array
   * @return: An integer
   */
  int singleNumber(vector<int> &A) {
    vector<int> res(64, 0);
    for (int i = 0; i < A.size(); i++) {
      int j = 63;
      int temp = A[i];
      while (temp != 0 && j >= 0) {
	res[j] = res[j] ^ (temp % 2);
	temp /= 2;
	j--;
      }
    }
    int real_res = 0;
    for (int i = 0; i < 64; i++) {
      real_res = real_res * 2 + res[i];
    }
    return real_res;
  }
};

int main() {
  int arr[] = {1,4,5,2,4,1,3,8,3,5,2};
  vector<int> vec(begin(arr), end(arr));
  Solution sl;
  int sn = sl.singleNumber(vec);
  cout << sn << endl;

  return 0;
}
