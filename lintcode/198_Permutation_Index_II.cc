/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:198_Permutation_Index_II.cc
 * Author:
 * Mail:
 * Created Time:2018年03月28日 星期三 13时25分41秒
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given a permutation which may contain repeated numbers, find its index in all the permutations of these numbers, which are ordered in lexicographical order. The index begins at 1.
 *
 * Example
 *   Given the permutation [1, 4, 2, 2], return 3.
 */

class Solution {
public:
  /**
   * @param A: An array of integers
   * @return: A long integer
   */
  // 求阶乘
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

  long long permutationIndexII(vector<int> &A) {
    long long res = 1;
    int len = A.size();
    for (int i = 0; i < len; i++) {
      long temp = 0;
      long n = 0;
      map<int, int> m;
      temp = getFactorial(len - i - 1);
      for (int j = i; j < len; j++) {
	if (A[j] < A[i]) {
	  n++;
	}
	if (m.find(A[j]) == m.end()) {
	  m.insert(pair<int, int>(A[j], 1));
	} else {
	  m[A[j]] += 1;
	}
      }
      long x = 1;
      for (map<int, int>::iterator iter = m.begin();
	   iter != m.end();
	   iter++) {
	if (iter->second >= 2) {
	  x *= getFactorial(iter->second);
	}
      }
      cout << "temp:" << temp << endl;
      cout << "n:" << n << endl;
      cout << "x:" << x << endl;
      res += (temp * n / x);
      cout << "res:" << res << endl;
    }
    return res;
  }
};

int main() {
  int arr[] = {2,2,3,3,1};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  long long res = sl.permutationIndexII(nums);
  cout << res << endl;
  return 0;
}
