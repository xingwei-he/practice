/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:51_Previous_Permutation.cc
 * Author:
 * Mail:
 * Created Time:星期五 12/15 10:09:38 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a list of integers, which denote a permutation.
 * Find the previous permutation in ascending order.
 *
 * Notice
 * The list may contains duplicate integers.
 *
 * Example
 * For [1,3,2,3], the previous permutation is [1,2,3,3]
 * For [1,2,3,4], the previous permutation is [4,3,2,1]
 */

class Solution {
public:
  /*
   * @param nums: A list of integers
   * @return: A list of integers that's previous permuation
   */

  /*
   * 从右向左扫描，遇到第一个分割点即可；分割点的选取规则为分割点右侧为一个递增序列
   */
  vector<int> previousPermuation(vector<int> &nums) {
    vector<int> res(nums);
    int pos = -1;
    // 注意，默认最后一个数字是一个递增序列
    for (int i = nums.size() - 2; i >= 0; i--) {
      if (nums[i] <= nums[i + 1]) {
	continue;
      } else {
	pos = i;// 用 pos 标识右侧递增序列的前一个元素位置，取值 [0, size - 2]
	// 注意！找到最右一个 pos 即可
	break;
      }
    }
    if (pos < 0) {
      reverse(res.begin(), res.end());
    } else {
      int k = pos + 2;// k 指向的是右侧的增序列中第一个比 pos 位置大的元素
      while (nums[pos] > nums[k] && k < res.size()) {
	k++;
      }
      k--;

      /* 交换
      int temp = res[pos];
      res[pos] = res[k];
      res[k] = temp;
      */
      // 利用抑或运算交换数据
      res[pos] ^= res[k];
      res[k] ^= res[pos];
      res[pos] ^= res[k];

      reverse(res.begin() + pos + 1, res.end());
    }
    return res;
  }
};

int main() {
  /*
     1,2,3,4
     1,2,4,3
     1,3,2,4
     1,3,4,2
     1,4,2,3
     1,4,3,2
     2,1,3,4
     ...
  */
  int arr[] = {2,1,3};
  vector<int> nums(begin(arr), end(arr));
  
  cout << "nums:" << endl;
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i]  << "  ";
  }
  cout << endl;

  Solution sl;
  vector<int> res = sl.previousPermuation(nums);
  cout << "res:" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i]  << "  ";
  }
  cout << endl;

  return 0;
}
