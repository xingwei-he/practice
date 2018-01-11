/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:149_Best_Time_to_Buy_and_Sell_Stock.cc
 * Author:
 * Mail:
 * Created Time:星期四  1/11 17:21:57 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 *
 * Example
 * Given array [3,2,3,1,2], return 1.
 */

class Solution {
public:
  /*
   * @param prices: Given an integer array
   * @return: Maximum profit
   */
  int maxProfit(vector<int> &prices) {
    if (prices.size() <= 1) {
      return 0;
    }
    int profit = 0;
    int price_buy = prices[0];
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] > price_buy) {
	int temp_profit = prices[i] - price_buy;
	if (profit < temp_profit) {
	  profit = temp_profit;
	}
      } else {
	price_buy = prices[i];
      }
    }
    return profit;
  }
};

int main() {
  int arr[] = {3,2,3,1,2};
  vector<int> prices(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  int max_profit = sl.maxProfit(prices);
  cout << "max_profit:" << max_profit << endl;
  return 0;
}
