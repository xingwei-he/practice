/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:split_odd_even.cc
 * Author:
 * Mail:
 * Created Time:星期五  2/23 15:53:47 2018
 ***************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  /*
   * 仅用O(1)的空间，将整数数组按奇偶数分成2部分，数组左边是奇数、右边是偶数。（要求：给出完整代码，尽量高效，简洁）
   */
  // 用首尾两个指针遍历交换数据，相对位置会改变
  void splitOddEven(vector<int>& nums) {
    int sz = nums.size();
    if (sz <= 1) {
      return;
    }
    vector<int>::iterator left_iter = nums.begin();
    vector<int>::iterator right_iter = nums.begin() + sz - 1;
    while (left_iter < right_iter) {
      while (*left_iter % 2 == 1 && left_iter < right_iter) {
	left_iter++;
      }
      while (*right_iter % 2 == 0 && left_iter < right_iter) {
	right_iter--;
      }
      *left_iter ^= *right_iter;
      *right_iter ^= *left_iter;
      *left_iter ^= *right_iter;
    }
  }
  // 用两个指针都从最左侧遍历，相对位置不会发生变化
  //void splitOddEven_2(vector<int>& nums) {}
};

int main() {
  int arr[] = {1,2,3,4,5,6,7,8,9};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  sl.splitOddEven(nums);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << "  ";
  }
  cout << endl;
  return 0;
}
