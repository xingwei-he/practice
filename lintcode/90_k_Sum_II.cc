/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:90_k_Sum_II.cc
 * Author:
 * Mail:
 * Created Time:星期日  4/ 8 15:51:34 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Your title here...Given n unique integers, number k (1<=k<=n) and target.
 * Find all possible k integers where their sum is target.
 *
 * Example
 *   Given [1,2,3,4], k = 2, target = 5. Return:
 *   [
 *     [1,4],
 *     [2,3]
 *   ]
 */

class Solution {
public:
  /*
   * @param A: an integer array
   * @param k: a postive integer <= length(A)
   * @param target: an integer
   * @return: A list of lists of integer
   */
  // DFS
  void dfs(vector<int> &A, int index, int k, int target, int cur_sum, vector<int> &one_res, vector<vector<int> > &res) {
    if (one_res.size() == k && cur_sum == target) {
      res.push_back(one_res);// 满足要求，找到一个可行解
      return;
    }
    if (index == A.size()) {
      return;
    }
    if (cur_sum > target) {
      return;
    }
    one_res.push_back(A[index]);
    dfs(A, index + 1, k, target, cur_sum + A[index], one_res, res);// A[index]加入
    one_res.pop_back();
    dfs(A, index + 1, k, target, cur_sum, one_res, res);// A[index]不加入
  }

  vector<vector<int> > kSumII(vector<int> &A, int k, int target) {
    vector<int> one_res;
    vector<vector<int> > res;
    dfs(A, 0, k, target, 0, one_res, res);
    return res;
  }
};

int main() {
  int arr[] = {1,2,3,4};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  int k = 2;
  int target = 5;
  Solution sl;
  vector<vector<int> > res = sl.kSumII(nums, k, target);
  debug2DVector(res, 2);
  return 0;
}
