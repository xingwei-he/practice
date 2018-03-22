/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:117_Jump_Game_II.cc
 * Author:
 * Mail:
 * Created Time:2018年03月22日 星期四 00时22分06秒
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * Example
 *   Given array A = [2,3,1,1,4]
 *   The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 */

class Solution {
public:
  /**
   * @param A: A list of integers
   * @return: An integer
   */
  int jump(vector<int> &A) {
    int cur_max = A[0];
    int step_counter = 0;
    for (int i = 1; i < A.size(); i++) {
      if (i > cur_max) {
	 return -1;
      }
      if (cur_max >= A.size() - 1) {
	return step_counter + 1;
      } else {
	if (i + A[i] > cur_max) {
	  cur_max = i + A[i];
	  step_counter++;
	}
      }
    }
  }
};

int main() {
  int arr[] = {17,8,29,17,35,28,14,2,45,8,6,54,24,43,20,14,33,31,27,11};
  vector<int> steps(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  int res = sl.jump(steps);
  cout << res << endl;
  return 0;
}
