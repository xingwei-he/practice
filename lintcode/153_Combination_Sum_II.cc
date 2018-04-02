/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:153_Combination_Sum_II.cc
 * Author:
 * Mail:
 * Created Time:2018年03月24日 星期六 11时18分51秒
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 * Each number in C may only be used once in the combination.
 *
 * Notice
 *   All numbers (including target) will be positive integers.
 *   Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 *   The solution set must not contain duplicate combinations.
 *
 * Example
 *   Given candidate set [10,1,6,7,2,1,5] and target 8,
 *   A solution set is:
 *   [
 *     [1,7],
 *     [1,2,5],
 *     [2,6],
 *     [1,1,6]
 *   ]
 */

class Solution {
public:
  /**
   * @param num: Given the candidate numbers
   * @param target: Given the target number
   * @return: All the combinations that sum to target
   */
  vector<vector<int> > combinationSum2(vector<int> &nums, int target) {
    set<vector<int> > res;// 防止结果出现重复，所以用 set 进行去重
    if (nums.size() <= 0) {
      return vector<vector<int> >(res.begin(), res.end());
    }
    vector<int> one_res;
    sort(nums.begin(), nums.end());
    dfs(nums, target, 0, one_res, res);
    return vector<vector<int> >(res.begin(), res.end());
  }

  void dfs(vector<int>& nums, int target, int index, vector<int>& one_res, set<vector<int> >& res) {
    if (0 == target) {
      res.insert(one_res);
      return;
    }
    for (int i = index; i < nums.size(); i++) {
      if (nums[i] > target) {
	continue;
      }
      one_res.push_back(nums[i]);
      dfs(nums, target - nums[i], i + 1, one_res, res);
      one_res.pop_back();
    }
  }
};

int main() {
  int arr[] = {7,1,2,5,1,6,10};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  int target = 8;
  Solution sl;
  vector<vector<int> > res = sl.combinationSum2(nums, target);
  debug2DVector<int>(res, 3);
  return 0;
}
