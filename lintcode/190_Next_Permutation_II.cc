/***************************************************
 * Xingwei_He All Rights numserved.
 * File Name:190_Next_Permutation_II.cc
 * Author:
 * Mail:
 * Created Time:星期五 12/15 13:42:24 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *
 * Example
 * Here are some examples. Inputs are in the left-hand column and its cornumsponding outputs are in the right-hand column.
 *
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */

class Solution {
public:
  /**
   * @param nums: An array of integers
   * @return: nothing
   */
  // 与 52 解法完全相同！
  void nextPermutation(vector<int> &nums) {
    int pos = -1;
    // 定位右侧第一个正序位(nums[i] < nums[i + 1])，并记录下位置i
    for (int i = nums.size() - 2; i >= 0; i--) {
      if (nums[i] >= nums[i + 1]) {
	continue;
      } else {
	pos = i;
	break;
      }
    }
    if (pos < 0) {
      // 如果整个序列都是逆序，则翻转即可得到下一个序列
      reverse(nums.begin(), nums.end());
    } else {
      int k = pos + 2;
      // 定位 nums[i] 右侧序列中第一个小于它的数 nums[k]
      while (nums[pos] < nums[k] && k < nums.size()) {
	k++;
      }
      // 把 nums[i] 和 nums[k] 前面的数交换
      k--;
      nums[pos] ^= nums[k];
      nums[k] ^= nums[pos];
      nums[pos] ^= nums[k];
      // 再把 nums[i] 后面的序列翻转
      reverse(nums.begin() + pos + 1, nums.end());
    }
  }
};

int main() {
  return 0;
}
