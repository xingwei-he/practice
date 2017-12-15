/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:52_Next_Permutation.cc
 * Author:
 * Mail:
 * Created Time:星期五 12/15 13:42:24 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a list of integers, which denote a permutation.
 * Find the next permutation in ascending order.
 *
 * Notice
 * The list may contains duplicate integers.
 *
 * Example
 * For [1,3,2,3], the next permutation is [1,3,3,2]
 * For [4,3,2,1], the next permutation is [1,2,3,4]
*/

class Solution {
public:
  /*
   * @param nums: A list of integers
   * @return: A list of integers
   */
  vector<int> nextPermutation(vector<int> &nums) {
    vector<int> res(nums);
    int pos = -1;
    for (int i = nums.size() - 2; i >= 0; i--) {
      if (nums[i] >= nums[i + 1]) {
	continue;
      } else {
	pos = i;
	break;
      }
    }
    if (pos < 0) {
      reverse(res.begin(), res.end());
    } else {
      int k = pos + 2;
      while (nums[pos] < nums[k] && k < res.size()) {
	k++;
      }
      k--;

      res[pos] ^= res[k];
      res[k] ^= res[pos];
      res[pos] ^= res[k];
      
      reverse(res.begin() + pos + 1, res.end());
    }
    return res;
  }
};

int main() {
  return 0;
}
