/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:red_packet.cc
 * Author:
 * Mail:
 * Created Time:星期二  3/13 16:49:26 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

class Solution {
public:
  static const double MAX_AMOUNT = 200.0;// 红包最大金额
  static const int MAX_PEOPEL = 500;// 群里最大人数
  vector<double> getRedPackets(double amount, int k) {
    vector<double> res;
    if (amount > MAX_AMOUNT || k > MAX_PEOPEL) {
      return res;
    }
    long available_amount = amount * 100;// 用 long 便于操作
    srand((unsigned)time(NULL));// 设置种子
    for (int i = 1; i < k; i++) {// 注意此处，只需要做 k-1 次
      long one_packet_amount = rand() % (available_amount - (k - i)) + 1;// +1 的操作是保证红包最少得到1分钱
      available_amount -= one_packet_amount;
      res.push_back(one_packet_amount/100.0);
    }
    res.push_back(available_amount/100.0);
    return res;
  }
};

int main() {
  Solution sl;
  double amount = 0.05;
  int k = 5;
  vector<double> res = sl.getRedPackets(amount, k);
  debug1DVector<double>(res, 8);
  double sum = 0;
  for (int i = 0; i < res.size(); i++) {
    sum += res[i];
  }
  cout << "sum:" << sum << endl;
  return 0;
}
