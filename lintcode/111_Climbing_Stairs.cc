/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:111_Climbing_Stairs.cc
 * Author:
 * Mail:
 * Created Time:2018年01月01日 星期一 17时52分25秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 *
 * Example
 * Given an example n=3 , 1+1+1=2+1=1+2=3
 * return 3
 */

class Solution {
public:
  /**
   * @param n: An integer
   * @return: An integer
   */
  int climbStairs(int n) {
    if (1 > n) {
      return 0;
    } else if (1 == n) {
      return 1;
    } else if (2 == n) {
      return 2;
    }
    int t1 = 1;
    int t2 = 2;
    for (int i = 3; i <= n; i++) {
      int temp = t1 + t2;
      t1 = t2;
      t2 = temp;
    }
    return t2;
  }
};

int main() {
  int n = 4;
  Solution sl;
  int steps = sl.climbStairs(n);
  cout << steps << endl;
  return 0;
}
