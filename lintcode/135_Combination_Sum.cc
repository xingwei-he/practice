/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:135_Combination_Sum.cc
 * Author:
 * Mail:
 * Created Time:2018年03月23日 星期五 23时55分40秒
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Notice
 *   All numbers (including target) will be positive integers.
 *   Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 *   The solution set must not contain duplicate combinations.
 *
 * Example
 *   Given candidate set [2,3,6,7] and target 7, a solution set is:
 *   [7]
 *   [2, 2, 3]
 */

class Solution {
public:
  /**
   * @param candidates: A list of integers
   * @param target: An integer
   * @return: A list of lists of integers
   */
  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector<vector<int> > res;
    if (candidates.size() <= 0) {
      return res;
    }
    vector<int> one_res;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, 0, one_res, res);
    return res;
  }
  
  void dfs(vector<int>& candidates, int target, int index, vector<int>& one_res, vector<vector<int> >& res) {
    if (0 == target) {
      res.push_back(one_res);
    }
    for (int i = index; i < candidates.size(); i++) {
      if (candidates[i] > target) {
	continue;
      }
      one_res.push_back(candidates[i]);
      dfs(candidates, target - candidates[i], i, one_res, res);
      one_res.pop_back();
    }
  }
};

int main() {
  int arr[] = {2,3,6,7};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  int target = 7;
  Solution sl;
  vector<vector<int> > res = sl.combinationSum(nums, target);
  debug2DVector<int>(res, 3);
  return 0;
}
