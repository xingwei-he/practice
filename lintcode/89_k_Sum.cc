/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:89_k_Sum.cc
 * Author:
 * Mail:
 * Created Time:星期日  4/ 8 14:13:38 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given n distinct positive integers, integer k (k <= n) and a number target.
 * Find k numbers where sum is target. Calculate how many solutions there are?
 * Example
 *   Given [1,2,3,4], k = 2, target = 5.
 *   There are 2 solutions: [1,4] and [2,3].
 *   Return 2.
 */

class Solution {
public:
  /**
   * @param A: An integer array
   * @param k: A positive integer (k <= length(A))
   * @param target: An integer
   * @return: An integer
   */
  // DP
  int kSum(vector<int> &A, int k, int target) {
    if (target < 0) {
      return 0;
    }
    int len = A.size();
    // dp[i][j][t] 表示前i个数中选取j个满足和为t的方法数
    vector<vector<vector<int> > > dp(len + 1, vector<vector<int> >(k + 1, vector<int>(target + 1)));
    for (int i = 0; i <= len; i++) {
      for (int j = 0; j <= k; j++) {
	for (int t = 0; t <= target; t++) {
	  if (0 == j && 0 == t) {
	    dp[i][j][t] = 1;// 前i个数中选取0个满足和为0的方法数就是1，其实就是一个都不选满足和为0
	  } else if(0 != i && 0 != j && 0 != t) {
	    dp[i][j][t] = dp[i - 1][j][t];// 如果不选A[i - 1]，则前i - 1个数中选j个满足和为t的方法数即为结果
	    if (t - A[i - 1] >= 0) {
	      dp[i][j][t] += dp[i - 1][j - 1][t - A[i - 1]];// 如果要把A[i - 1]选进来，则需要在不选A[i - 1]的基础上加上前i - 1个数中选取j - 1个满足和为t - A[i - 1]的方法数即可
	    }
	  }
	}
      }
    }
    return dp[len][k][target];
  }
};

int main() {
  int arr[] = {1,2,3,4};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  int k = 2;
  int target = 5;
  Solution sl;
  int res = sl.kSum(nums, k, target);
  cout << res << endl;
  return 0;
}
