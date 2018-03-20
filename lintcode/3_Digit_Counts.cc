/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:3_Digit_Counts.cc
 * Author:
 * Mail:
 * Created Time:2018年01月07日 星期日 11时50分51秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Count the number of k's between 0 and n. k can be 0 - 9.
 *
 * Example
 * if n = 12, k = 1 in
 * [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
 * we have FIVE 1's (1, 10, 11, 12)
 */

class Solution {
public:
  /*
   * @param : An integer
   * @param : An integer
   * @return: An integer denote the count of digit k in 1..n
   */
  /*
  // 方法一 穷举法
  int countK(const int& n, const int& k) {
    int temp = n;
    int counter = 0;
    do {
      if (temp % 10 == k) {
	counter++;
      }
      temp /= 10;
    } while (0 != temp);
    return counter;
  }

  int digitCounts(int k, int n) {
    int counter = 0;
    for (int i = 0; i <= n; i++) {
      counter += countK(i, k);
    }
    return counter;
  }
  */
  int digitCounts(int k, int n) {
    int count = 0;
    if (k == 0) {
      count = 1;
    }   
    for (int i = 1; i <= n; i++) {
      int number = i;
      while (number > 0) {
	if (number % 10 == k) {
	  count += 1;
	}
	number /= 10;
      }
    }
    return count;
  }
};

int main() {
  int n = 12;
  int k = 1;
  cout << "n:" << n << "\tk:" << k << endl; 
  Solution sl;
  int res = sl.digitCounts(k, n);
  cout << "res:" << res << endl;
  return 0;
}

