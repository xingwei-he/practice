/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:513_Perfect_Squares.cc
 * Author:
 * Mail:
 * Created Time:星期五  3/16 15:06:18 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
 *
 * Example
 *   Given n = 12, return 3 because 12 = 4 + 4 + 4
 *   Given n = 13, return 2 because 13 = 4 + 9
 */

class Solution {
public:
  /**
   * @param n: a positive integer
   * @return: An integer
   */
  // 任一完美平方数都是由一个普通数加上一个完美平方数 i + j * j
  // 则有递推公式为 dp[i + j * j] = min(dp[i] + 1, dp[i + j * j])
  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    for (int i = 0; i * i <= n; i++) {
      dp[i * i] = 1;
    }
    for (int i = 1; i <= n; i++) {// 选定第一个数为 i
      for (int j = 1; i + j * j <= n; j++) {// 选定另一个数为 j*j
	dp[i + j * j] = min(dp[i] + 1, dp[i + j * j]);// 从小到大查找
      }
    }
    //debug1DVector(dp, 3);
    return dp[n];
  }
};

int main() {
  int n = 12;
  Solution sl;
  int res = sl.numSquares(n);
  cout << res << endl;
  return 0;
}
