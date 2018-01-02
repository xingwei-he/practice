/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:197_Permutation_Index.cc
 * Author:
 * Mail:
 * Created Time:星期二  1/ 2 17:23:33 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a permutation which contains no repeated number, find its index in all the permutations of these numbers, which are ordered in lexicographical order. The index begins at 1.
 *
 * Example
 * Given [1,2,4], return 1.
 */

class Solution {
public:
  /*
   * @param A: An array of integers
   * @return: A long integer
   */
  long long getFactorial(long long n) {
    if (n < 0) {
      return -1;
    }
    long long res = 1;
    for (long long i = 1; i <= n; i++) {
      res *= i;
    }
    return res;
  }

  // 记第 i 位后面有 si 个数比 A[i] 小
  long long permutationIndex(vector<int> &A) {
    if (A.size() == 0) {
      return 0;
    }
    long long res = 1;// 初值为 1
    int len = A.size();
    for (int i = 0; i < len; i++) {
      int si = 0;// 记录 i 后面比 A[i] 小的数的个数
      for (int j = i; j < len; j++) {
	if (A[j] < A[i]) {
	  si++;
	}
      }
      res += getFactorial(len - i - 1) * si;
    }
    return res;
  }
};

int main() {
  int arr[] = {2,6,4,5,8,1,7,3};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  int res = sl.permutationIndex(nums);
  cout << res << endl;
  return 0;
}

