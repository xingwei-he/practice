/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:151_Best_Time_to_Buy_and_Sell_Stock_III.cc
 * Author:
 * Mail:
 * Created Time:星期四  1/11 18:56:33 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 *
 * Notice
 *   You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 *
 * Example
 * Given an example [4,4,6,1,1,4,2,5], return 6.
 */

class Solution {
public:
  /*
   * @param prices: Given an integer array
   * @return: Maximum profit
   */
  int maxProfit(vector<int> &prices) {
    if (prices.size() <= 1) {
      return 0;
    }
    int n = prices.size();
    vector<int> left_max_profit(n, 0);
    vector<int> right_max_profit(n, 0);
    int left_min = prices[0];
    int right_max = prices[n - 1];
    for (int i = 1; i < n; i++) {
      if (left_min > prices[i]) {
	left_min = prices[i];
      }
      left_max_profit[i] = (prices[i] - left_min) > left_max_profit[i - 1] ? (prices[i] - left_min) : left_max_profit[i - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
      if (right_max < prices[i]) {
	right_max = prices[i];
      }
      right_max_profit[i] = (right_max - prices[i] > right_max_profit[i + 1]) ? (right_max - prices[i]) : right_max_profit[i  + 1];
    }
    int max_profit = 0;
    for (int i = 0; i < n; i++) {
      if (max_profit < (left_max_profit[i] + right_max_profit[i])) {
	max_profit = left_max_profit[i] + right_max_profit[i];
      }
    }
    return max_profit;
  }
};

int main() {
  int arr[] = {4,4,6,1,1,4,2,5};
  vector<int> prices(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  int max_profit = sl.maxProfit(prices);
  cout << "max_profit:" << max_profit << endl;
  return 0;
}

