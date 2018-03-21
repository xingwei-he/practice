/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:58_4Sum.cc
 * Author:
 * Mail:
 * Created Time:星期三  3/21 18:47:49 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
 * Find all unique quadruplets in the array which gives the sum of target.
 *
 * Notice
 *   Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 *   The solution set must not contain duplicate quadruplets.
 *
 * Example
 *   Given array S = {1 0 -1 0 -2 2}, and target = 0. A solution set is:
 *   (-1, 0, 0, 1)
 *   (-2, -1, 1, 2)
 *   (-2, 0, 0, 2)
 */

class Solution {
public:
  /**
   * @param numbers: Give an array
   * @param target: An integer
   * @return: Find all unique quadruplets in the array which gives the sum of zero
   */
  vector<vector<int> > fourSum(vector<int> &numbers, int target) {
    int len = numbers.size();
    vector<vector<int> > res;
    if (len < 4) {
      return res;
    }
    sort(numbers.begin(), numbers.end());
    debug1DVector<int>(numbers, 3);
    int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
    int t = 0;
    while (p1 <= len - 4) {
      p2 = p1 + 1;
      while (p2 <= len - 3) {
	p3 = p2 + 1;
	p4 = len - 1;
	t = target - numbers[p1] - numbers[p2];
	while (p3 < p4) {
	  if (numbers[p3] + numbers[p4] == t) {
	    vector<int> one_res;
	    one_res.push_back(numbers[p1]);
	    one_res.push_back(numbers[p2]);
	    one_res.push_back(numbers[p3]);
	    one_res.push_back(numbers[p4]);
	    res.push_back(one_res);
	    while (p3 < p4 && numbers[p3] == numbers[p3 + 1]) {
	      p3++;
	    }
	    p3++;
	    while (p3 < p4 && numbers[p4] == numbers[p4 - 1]) {
	      p4--;
	    }
	    p4--;
	  } else if (numbers[p3] + numbers[p4] > t) {
	    p4--;
	  } else {
	    p3++;
	  }
	}
	while (p2 <= len - 3 && numbers[p2] == numbers[p2 + 1]) {
	  p2++;
	}
	p2++;
      }
      while (p1 <= len - 4 && numbers[p1] == numbers[p1 + 1]) {
	p1++;
      }
      p1++;
    }
    return res;
  }
};

int main() {
  int arr[] = {1, 0, -1, 0, -2, 2};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  int target = 0;
  Solution sl;
  vector<vector<int> > res = sl.fourSum(nums, target);
  debug2DVector<int>(res, 3);
  return 0;
}
