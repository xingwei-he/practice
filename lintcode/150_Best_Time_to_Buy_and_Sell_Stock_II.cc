/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:150_Best_Time_to_Buy_and_Sell_Stock_II.cc
 * Author:
 * Mail:
 * Created Time:星期四  1/11 18:32:51 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 *
 * Example
 * Given an example [2,1,2,0,1], return 2
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
    int profit = 0;
    int i = 0;
    while (i < prices.size() - 1) {
      if (prices[i] < prices[i + 1]) {
	profit += (prices[i + 1] - prices[i]);
      }
      i++;
    }
    return profit;
  }
};

int main() {
  int arr[] = {2,1,2,0,1};
  vector<int> prices(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  int max_profit = sl.maxProfit(prices);
  cout << "max_profit:" << max_profit << endl;
  return 0;
}
