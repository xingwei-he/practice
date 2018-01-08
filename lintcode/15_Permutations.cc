/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:15_Permutations.cc
 * Author:
 * Mail:
 * Created Time:星期一  1/ 8 13:43:25 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a list of numbers, return all possible permutations.
 *
 * Notice
 *   You can assume that there is no duplicate numbers in the list.
 *
 * Example
 * For nums = [1,2,3], the permutations are:
 * [
 *   [1,2,3],
 *   [1,3,2],
 *   [2,1,3],
 *   [2,3,1],
 *   [3,1,2],
 *   [3,2,1]
 * ]
 */

class Solution {
public:
  /*
   * @param nums: A list of integers.
   * @return: A list of permutations.
   */
  vector<vector<int> > permute(vector<int> &nums) {
    vector<vector<int> > res;
    permuteDFS(nums, 0, res);
    return res;
  }
  void permuteDFS(vector<int>& nums, int start, vector<vector<int> >& res) {
    if (start >= nums.size()) {
      res.push_back(nums);
    }
    for (int i = start; i < nums.size(); i++) {
      swap(nums[start], nums[i]);
      permuteDFS(nums, start + 1, res);
      swap(nums[start], nums[i]);
    }
  }
};

int main() {
  int arr[] = {1,2,3};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  vector<vector<int> > res = sl.permute(nums);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << "  ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
