/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:400_Maximum_Gap.cc
 * Author:
 * Mail:
 * Created Time:星期五  3/23 11:15:10 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 * Return 0 if the array contains less than 2 elements.
 *
 * Notice
 *   You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
 *
 * Example
 *   Given [1, 9, 2, 5], the sorted form of it is [1, 2, 5, 9], the maximum gap is between 5 and 9 = 4.
 */

class Solution {
public:
  /**
   * @param nums: an array of integers
   * @return: the maximun difference
   */
  int maximumGap(vector<int> &nums) {
    int len = nums.size();
    if (len < 2) {
      return 0;
    }
    cout << "len:" << len << endl;
    int max_num = nums[0], min_num = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      max_num = max_num >= nums[i] ? max_num : nums[i];
      min_num = min_num <= nums[i] ? min_num : nums[i];
    }
    // 注意桶容量和桶数的求法
    // 每个桶容量至少为 1，如果 max_num - min_num < len，则说明有相等值，每个桶的容量必然是 1
    // 如果 max_num - min_num >= len，则桶的容量就是 (max_num - min_num)/len + 1，此处 +1 是为了取上界
    // 更直观的看，其实就是假设每个元素都扔进一个桶里，也就是把 [0, max_num - min_num] 这个区间分成 len 份
    int bucket_size = (max_num - min_num) / len + 1;// 每个桶的容量
    int bucket_num = (max_num - min_num) / bucket_size + 1;// 一共有多少桶
    cout << "bucket_size:" << bucket_size << endl;
    cout << "bucket_num:" << bucket_num << endl;
    vector<vector<int> > buckets(bucket_num);
    for (int i = 0; i < len; i++) {
      int n = (nums[i] - min_num) / bucket_size;// 选桶
      cout << nums[i] << "->" << n << endl;
      if (buckets[n].empty()) {
	buckets[n].reserve(2);
	buckets[n].push_back(nums[i]);
	buckets[n].push_back(nums[i]);
      } else {
	if (nums[i] < buckets[n][0]) {
	  buckets[n][0] = nums[i];
	} else if (nums[i] > buckets[n][1]) {
	  buckets[n][1] = nums[i];
	}
      }
    }
    int pre_n = 0;
    int max_gap = 0;
    for (int n = 1; n < buckets.size(); n++) {
      if (buckets[n].empty()) {
	continue;
      }
      max_gap = max(max_gap, buckets[n][0] - buckets[pre_n][1]);
      pre_n = n;
    }
    return max_gap;
  }
};

int main() {
  int arr[] = {1,1,1,1,1,10};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  int res = sl.maximumGap(nums);
  cout << res << endl;
  return 0;
}
