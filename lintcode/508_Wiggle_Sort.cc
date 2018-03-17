/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:508_Wiggle_Sort.cc
 * Author:
 * Mail:
 * Created Time:2018年03月17日 星期六 23时55分34秒
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given an unsorted array nums, reorder it in-place such that
 * nums[0] <= nums[1] >= nums[2] <= nums[3]....
 *
 * Notice
 *   Please complete the problem in-place.
 *
 * Example
 *   Given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].
 */

class Solution {
public:
  /*
   * @param nums: A list of integers
   * @return: nothing
   */
  // 方法一
  // 可以将整个数组排序，然后将 nums[i] 与 nums[i + 1] 交换，i 的取值范围是 i >= 1

  // 方法二
  // 注意，其实并不用将整体排序，所以只需要判断 nums[i] 是否满足约束条件即可
  // 当 i 为奇数，nums[i] >= nums[i - 1]
  // 当 i 为偶数，nums[i] <= nums[i - 1]
  // 如果不能满足上述条件，则将两个数据交换即可
  void wiggleSort(vector<int> &nums) {
    if (nums.size() <= 1) {
      return;
    }
    for (int i = 1; i < nums.size(); ++i) {
      if ((i % 2 == 1 && nums[i] < nums[i - 1]) || (i % 2 == 0 && nums[i] > nums[i - 1])) {
	swap(nums[i], nums[i - 1]);
      }
    }
  }
};

int main() {
  int arr[] = {3, 5, 2, 1, 6, 4};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  sl.wiggleSort(nums);
  debug1DVector<int>(nums, 3);
  return 0;
}
