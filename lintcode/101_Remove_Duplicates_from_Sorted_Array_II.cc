/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:101_Remove_Duplicates_from_Sorted_Array_II.cc
 * Author:
 * Mail:
 * Created Time:2018年01月01日 星期一 14时53分58秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?

 * For example,
 * Given sorted array A = [1,1,1,2,2,3],
 * Your function should return length = 5, and A is now [1,1,2,2,3].
 */

class Solution {
public:
  /**
   * @param A: a list of integers
   * @return : return an integer
   */
  int removeDuplicates(vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    }
    int counter = 1;
    int pre = nums[0];
    int pos = 0;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == pre) {
	counter++;
      } else {
	pre = nums[i];
	counter = 1;
      }
      if (2 >= counter) {
	nums[++pos] = nums[i];
      }
    }
    nums.erase(nums.begin() + pos + 1, nums.end());
    return pos + 1;
  }
};

int main() {
  int arr[] = {1,1,1,2,3,4,4,5,5,5,5,6,7,7,8,8,8,8};
  vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
  Solution sl;
  int len = sl.removeDuplicates(nums);
  cout << "len:" << len << endl;
  for (vector<int>::iterator iter = nums.begin();
       iter != nums.end();
       iter++) {
    cout << *iter << "  ";
  }
  cout << endl;
  return 0;
}
