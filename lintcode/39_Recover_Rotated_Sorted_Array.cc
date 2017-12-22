/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:39_Recover_Rotated_Sorted_Array.cc
 * Author:
 * Mail:
 * Created Time:星期五 12/22 11:23:39 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

/**
 * Given a rotated sorted array, recover it to sorted array in-place.
 *
 * Clarification
 * What is rotated array?
 *   For example, the orginal array is [1,2,3,4], The rotated array of it can be [1,2,3,4], [2,3,4,1], [3,4,1,2], [4,1,2,3]
 *
 * Example
 * [4, 5, 1, 2, 3] -> [1, 2, 3, 4, 5]
 */

using namespace std;

class Solution {
public:
  /*
   * @param nums: An integer array
   * @return: nothing
   */
  // 用二分查找找到分界点，即返回全局最小值的位置
  int findPosition(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    int mid = 0;
    int left = 0;
    int right = nums.size() - 1;
    while (nums[left] >= nums[right]) {
      while (left < nums.size() - 1 && nums[left] == nums[left + 1]) {
	left++;
      }
      while (right >= 1 && nums[right] == nums[right - 1]) {
	right--;
      }
      mid = (left + right) / 2;
      if (0 == mid || nums.size() - 1 == mid) {
	break;
      }
      if (nums[mid - 1] > nums[mid]) {
	break;
      } else if (nums[mid] >= nums[left]) {
	left = mid;
      } else {
	right = mid;
      }
      cout << mid << endl;
    }
    return mid;
  }

  void recoverRotatedSortedArray(vector<int> &nums) {
    if (0 == nums.size() || 1 == nums.size()) {
      return;
    }
    int pos = findPosition(nums);
    if (0 == pos) {
      return;
    }
    queue<int> q;
    for (int i = 0; i < pos; i++) {
      q.push(nums[i]);
    }
    for (int i = pos; i < nums.size(); i++) {
      nums[i - pos] = nums[i];
    }
    int j = nums.size() - pos;
    while (!q.empty()) {
      int temp = q.front();
      q.pop();
      nums[j++] = temp;
    }
  }
};

int main() {
  //int arr[] = {5,6,7,8,9,1,2,3,4};
  //int arr[] = {6,1,2,3,4,5};
  int arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  //int arr[] = {116,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115};
  vector<int> nums(begin(arr), end(arr));
  Solution sl;
  int pos = sl.findPosition(nums);
  cout << "pos:" << pos << endl;
  sl.recoverRotatedSortedArray(nums);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << "  ";
  }
  cout << endl;
  return 0;
}
