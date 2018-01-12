/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:393_Best_Time_to_Buy_and_Sell_Stock_IV.cc
 * Author:
 * Mail:
 * Created Time:星期五  1/12 10:31:46 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most k transactions.
 *
 * Notice
 *   You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 *
 * Example
 * Given prices = [4,4,6,1,1,4,2,5], and k = 2, return 6.
 */

class Solution {
public:
  /*
   * @param K: An integer
   * @param prices: An integer array
   * @return: Maximum profit
   */
  int maxProfit(int K, vector<int> &prices) {
    if (0 == K || prices.size() < 2) {
      return 0;
    }
    if (K > prices.size() / 2) {
      return maxProfitOfSolutionII(prices);
    }
    // hold[i][j]: 对于0~i天中最多进行j次交易并且第i天仍然持有股票的收益
    // unhold[i][j]: 对于0~i天中最多进行j次交易并且第i天不持有股票的收益
    // 第i天持有股票的收益为 之前买了股票但还没有卖出 或者 今天才选择买入股票 二者中较大值
    // hold[i][j] = max(unhold[i-1][j]-prices[j],hold[i][j-1]);
    // 第i天不持有股票的收益为 选择今天卖出 或者 今天不买入时 最大的收益
    // unhold[i][j] = max(hold[i][j-1]+prices[j],unhold[i][j-1]);
    vector<vector<int> > hold(K + 1, vector<int>(prices.size()));
    vector<vector<int> > unhold(K + 1, vector<int>(prices.size()));
    for (int i = 1; i <= K; i++) {
      hold[i][0] = -prices[0];
      unhold[i][0] = 0;
      for (int j = 1; j < prices.size(); j++) {
	hold[i][j] = (unhold[i - 1][j] - prices[j]) > hold[i][j - 1] ? (unhold[i - 1][j] - prices[j]) : hold[i][j - 1];
	unhold[i][j] = (hold[i][j - 1] + prices[j]) > unhold[i][j - 1] ? (hold[i][j - 1] + prices[j]) : unhold[i][j - 1];
      }
    }
    return unhold[K][prices.size() - 1];
  }

  int maxProfitOfSolutionII(vector<int>& prices) {
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
  // Given prices = [4,4,6,1,1,4,2,5], and k = 2, return 6
  int arr[] = {4,4,6,1,1,4,2,5};
  int k = 2;
  vector<int> prices(arr, arr + sizeof(arr)/sizeof(int));
  cout << "k:" << k << endl;
  cout << "given prices:" << endl;
  for (int i = 0; i < prices.size(); i++) {
    cout << setw(4) << prices[i];
  }
  cout << endl;
  Solution sl;
  int max_profit = sl.maxProfit(k, prices);
  cout << "max_profit:" << max_profit << endl;
  return 0;
}
