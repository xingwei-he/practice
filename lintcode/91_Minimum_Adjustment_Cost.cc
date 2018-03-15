/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:91_Minimum_Adjustment_Cost.cc
 * Author:
 * Mail:
 * Created Time:星期四  3/15 11:11:46 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given an integer array, adjust each integers so that the difference of every adjacent integers are not greater than a given number target.
 * If the array before adjustment is A, the array after adjustment is B, you should minimize the sum of |A[i]-B[i]|
 *
 *  Notice
 *    You can assume each number in the array is a positive integer and not greater than 100.
 *
 *  Example
 *    Given [1,4,2,3] and target = 1, one of the solutions is [2,3,2,3], the adjustment cost is 2 and it's minimal.
 *    Return 2. 
 */

class Solution {
public:
  /*
   * @param A: An integer array
   * @param target: An integer
   * @return: An integer
   */
  // DP
  static const int RANGE_LIMIT = 100;
  int MinAdjustmentCost(vector<int> &A, int target) {
    int len = A.size();
    if (len <= 0 || target < 0) {
      return 0;
    }
    // matrix[i][j] 表示从 A[i] 调整到 j 的代价，原则是根据上一行选取更小的代价来填写
    // 例如要填写 matrix[i][j] 时，要对 matrix[i - 1][j - target ~ j + target] + abs(A[i] - j) 中取最小值
    // 实际就是当 A[i] 调整到 j 时，对于前一个数 A[i - 1] 要求它调整范围是 [j - target, j + target]，因为只有当前一个数的范围满足这个要求时， A[i] 调整到 j 才是一个合法操作，所以只需要取这个范围内的最小值再加上 abs(A[i] - j) 即可
    vector<vector<int> > matrix(len, vector<int>(RANGE_LIMIT, INT_MAX));
    for (int j = 0; j < RANGE_LIMIT; j++) {
      matrix[0][j] = abs(A[0] - j);
    }
    for (int i = 1; i < len; i++) {
      for (int j = 0; j < RANGE_LIMIT; j++) {
	for (int k = j - target; k <= j + target; k++) {
	  if (k < 0 || k >= RANGE_LIMIT) {
	    continue;
	  }
	  matrix[i][j] = min(matrix[i][j], matrix[i - 1][k] + abs(A[i] - j));
	}
      }
    }
    int res = INT_MAX;
    for (int j = 0; j < RANGE_LIMIT; j++) {
      if (res > matrix[len - 1][j]) {
	res = matrix[len - 1][j];
      }
    }
    return res;
  }
};

int main() {
  int arr[] = {1,4,2,3};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  int target = 1;
  Solution sl;
  int res = sl.MinAdjustmentCost(nums, target);
  cout << res << endl;
  return 0;
}
