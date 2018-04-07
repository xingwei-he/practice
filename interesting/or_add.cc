/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:or_add.cc
 * Author:
 * Mail:
 * Created Time:2018年04月07日 星期六 11时56分53秒
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * 题目描述：
 *   给定 x，k，求满足 x + y = x | y 的第 K 小的正整数 y。 | 是二进制的或（or）运算。例如，3 | 5 = 7.
 *   比如当 x = 5， k = 1时，返回2，因为 5+1 = 6 不等于 5 | 1 = 5，而 5+2 = 7 等于 5 | 2 = 7
 *
 * 输入描述：
 ×   每组测试用例仅包含一组数据，每组数据为两个正整数 x ， k。满足 0 < x, k <= 2,000,000,000
 ×
 * 输出描述：
 *   输出一个数y
 */

class Solution {
public:
  int getY(int x, int k) {
    vector<int> xbits;
    while (x != 0) {
      xbits.push_back(x % 2);
      x /= 2;
    }
    vector<int> res_vec;
    int i = 0;
    while (k != 0) {
      if (i > xbits.size() || xbits[i] == 1) {
	res_vec.push_back(0);
      } else {
	res_vec.push_back(k % 2);
	k /= 2;
      }
      i++;
    }
    int res = 0;
    for (i = res_vec.size() - 1; i >= 0; i--) {
      res *= 2;
      res += res_vec[i];
    }
    return res;
  }
};

int main() {
  //int x = 20;// 10100
  //int k = 5;// 101
  int x = 5;
  int k = 1;
  Solution sl;
  int res = sl.getY(x, k);
  cout << res << endl;
  return 0;
}
