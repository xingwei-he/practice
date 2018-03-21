/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:57_3Sum.cc
 * Author:
 * Mail:
 * Created Time:星期三  3/21 17:08:49 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Notice
 *   Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 *   The solution set must not contain duplicate triplets.
 *
 * Example
 *   For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
 *   (-1, 0, 1)
 *   (-1, -1, 2)
 */

class Solution {
public:
  /**
   * @param numbers: Give an array numbers of n integer
   * @return: Find all unique triplets in the array which gives the sum of zero.
   */
  vector<vector<int> > threeSum(vector<int> &numbers) {
    int len = numbers.size();
    vector<vector<int> > res;
    if (len < 3) {
      return res;
    }
    sort(numbers.begin(), numbers.end());
    //bug1DVector<int>(numbers, 3);
    int i = 0, j = 0, k = 0;
    int target = 0;
    while (i <= len - 3) {
      j = i + 1;
      k = len - 1;
      target = 0 - numbers[i];
      while (j < k) {
	if (numbers[j] + numbers[k] == target) {
	  vector<int> one_res;
	  one_res.push_back(numbers[i]);
	  one_res.push_back(numbers[j]);
	  one_res.push_back(numbers[k]);
	  res.push_back(one_res);
	  while (j < k && numbers[j] == numbers[j + 1]) {
	    j++;
	  }
	  j++;
	  while (j < k && numbers[k] == numbers[k - 1]) {
	    k--;
	  }
	  k--;
	} else if (numbers[j] + numbers[k] > target) {
	  k--;
	} else {
	  j++;
	}
      }
      while (i <= len - 3 && numbers[i] == numbers[i + 1]) {
	i++;
      }
      i++;
    }
    return res;
  }
};

int main() {
  int arr[] = {1,0,-1,-1,-1,-1,0,1,1,1};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  vector<vector<int> > res = sl.threeSum(nums);
  debug2DVector<int>(res, 3);
  return 0;
}
