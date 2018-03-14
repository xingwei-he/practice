/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:stairs.cc
 * Author:
 * Mail:
 * Created Time:星期三  3/14 17:04:17 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * 有一楼梯共m级，刚开始时你在第一级，若每次只能跨上一级或者二级，要走上m级，共有多少走法？注：规定从一级到一级有0种走法。
 *
 * 给定一个正整数int n，请返回一个数，代表上楼的方式数。保证n小于等于100。为了防止溢出，请返回结果Mod 1000000007的值。
 *
 * 测试样例：3
 * 返回：2
 */

/**
  经典动态规划问题，斐波那契数列，f(n) = f(n-1) + f(n-2)
 */

class Solution {
public:
  int climbStairsRecursively(int n) {
    if (n <= 0) {
      return 0;
    } else if (1 == n) {
      return 1;
    } else if (2 == n) {
      return 2;
    } else {
      return climbStairsRecursively(n - 1) + climbStairsRecursively(n - 2);
    }
  }

  // 非递归算法
  int climbStairs(int n) {
    if (n <= 0) {
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
  int res = sl.climbStairs(n);
  cout << "res:" << res << endl;
  return 0;
}
