/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:84_Single_Number_III.cc
 * Author:
 * Mail:
 * Created Time:2017年12月14日 星期四 23时36分48秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given 2*n + 2 numbers, every numbers occurs twice except two, find them.
 * Have you met this question in a real interview?
 * 
 * Example
 *
 * Given [1,2,2,3,4,4,5,3] return 1 and 5
 */

class Solution {
public:
  /*
   * @param A: An integer array
   * @return: An integer array
   */
  
  /* 方法1 */
  /**
    该方法的思想是将两个 single number 分别分到两个组里，然后对每个组分别找一个 single num
    首先将所有的数字进行异或操作，所得结果是两个 single num 进行异或操作的结果，所以取出一位为1的位作为标记，用这个位将所有数字分为两组即可
   */
  vector<int> singleNumberIII(vector<int> &nums) {
    int k = 0;
    for (int i = 0; i < nums.size(); i++) {
      k ^= nums[i];
    }
    int flag = 0;// 标记位
    while (0 != k) {
      if (0 != (1 & k)) {
	break;
      } else {
	k >>= 1;
	flag++;
      }
    }
    vector<int> group_0;
    vector<int> group_1;
    for (int i = 0; i < nums.size(); i++) {
      if (((nums[i] >> flag) & 1) == 0) {
	group_0.push_back(nums[i]);
      } else {
	group_1.push_back(nums[i]);
      }
    }
    int t0 = 0;
    for (int i = 0; i < group_0.size(); i++) {
      t0 ^= group_0[i];
    }
    int t1 = 0;
    for (int i = 0; i < group_1.size(); i++) {
      t1 ^= group_1[i];
    }
    vector<int> res;
    res.push_back(t0);
    res.push_back(t1);
    return res;
  }

  /* 方法2 - 该方法利用 map/set 比较耗费时间和空间
  vector<int> singleNumberIII(vector<int> &nums) {
    map<int, int> counter_map;
    for (int i = 0; i < nums.size(); i++) {
      if (counter_map.find(nums[i]) != counter_map.end()) {
	counter_map[nums[i]] += 1;
      } else {
	counter_map.insert(pair<int, int>(nums[i], 1));
      }
    }
    
    vector<int> res;
    for (map<int, int>::iterator iter = counter_map.begin();
	 iter != counter_map.end();
	 iter++) {
      if (iter->second == 1) {
	res.push_back(iter->first);
      }
    }

    return res;
  }
  */
};

int main() {
  int arr[] = {1,2,3,3,2,4,1,5};
  vector<int> nums(begin(arr), end(arr));
  Solution sl;
  vector<int> res = sl.singleNumberIII(nums);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << "  ";
  }
  cout << endl;
  return 0;
}

