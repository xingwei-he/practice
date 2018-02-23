/***************************************************
 * Xingwei_He All Rights numserved.
 * File Name:388_Permutation_Sequence.cc
 * Author:
 * Mail:
 * Created Time:星期五 12/15 13:42:24 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given n and k, return the k-th permutation sequence.
 *
 * Notice
 *   n will be between 1 and 9 inclusive.
 *
 * Example
 * For n = 3, all permutations are listed as follows:
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * If k = 4, the fourth permutation is "231"
 */

class Solution {\
public:
  /**
   * @param n: n
   * @param k: the k th permutation
   * @return: return the k-th permutation
   */
  // 该函数与 52 题解法完全相同！
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

  string getPermutation(int n, int k) {
    vector<int> nums;
    for (int i = 1; i <= n; i++) {
      nums.push_back(i);
    }
    while (k > 1) {
      nextPermutation(nums);
      k--;
    }
    string res;
    for (int i = 0; i < nums.size(); i++) {
      res.push_back(nums[i] + '0');
    }
    return res;
  }
};

int main() {
  int n = 4;
  int k = 5;
  Solution sl;
  string res = sl.getPermutation(n, k);
  cout << "n:" << n << "\tk:" << k << "\t" << res << endl;
  return 0;
}
