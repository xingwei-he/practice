/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:83_Single_Number_II.cc
 * Author:
 * Mail:
 * Created Time:2017年12月14日 星期四 22时56分29秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given 3*n + 1 numbers, every numbers occurs triple times except one, find it.
 *
 * Example
 *
 * Given [1,1,2,3,3,3,2,2,4,1] return 4
 */

class Solution {
public:
  /*
   * @param A: An integer array
   * @return: An integer
   */
  int singleNumberII(vector<int> &nums) {
    int bar[MAX_BITS] = {0};
    for (int i = 0; i < nums.size(); i++) {
      int temp = nums[i];
      int j = MAX_BITS - 1;
      while (j >= 0) {
	if(1 == (temp & 1)) {
	  bar[j] += 1;
	}
	j--;
	temp >>= 1;
      }
    }
   
    int res = 0;
    for (int i = 0; i < MAX_BITS; i++) {
      bar[i] %= 3;
    }
    for (int i = 0; i < MAX_BITS; i++) {
      res = res * 2 + bar[i];
    }
    
    return res;
  }

private:
  static const int MAX_BITS = 64;
};

int main() {
  return 0;
}
