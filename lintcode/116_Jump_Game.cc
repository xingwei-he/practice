/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:116_Jump_Game.cc
 * Author:
 * Mail:
 * Created Time:2018年03月21日 星期三 23时22分24秒
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index.
 *
 * Notice
 *   This problem have two method which is Greedy and Dynamic Programming.
 *   The time complexity of Greedy method is O(n).
 *   The time complexity of Dynamic Programming method is O(n^2).
 *   We manually set the small data set to allow you pass the test in both ways. This is just to let you learn how to use this problem in dynamic programming ways. If you finish it in dynamic programming ways, you can try greedy method to make it accept again.
 *
 * Example
 *   A = [2,3,1,1,4], return true.
 *   A = [3,2,1,0,4], return false.
 */

class Solution {
public:
  /**
   * @param A: A list of integers
   * @return: A boolean
   */
  // 贪心算法
  bool canJump(vector<int> &A) {
    int cur_max = A[0];
    for (int i = 1; i < A.size(); i++) {
      if (i > cur_max) {
	return false;
      }
      cur_max = max(i + A[i], cur_max);
      if (cur_max >= A.size() - 1) {
	return true;
      }
    }
  }
};

int main() {
  return 0;
}
