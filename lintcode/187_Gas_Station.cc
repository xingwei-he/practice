/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:187_Gas_Station.cc
 * Author:
 * Mail:
 * Created Time:星期三  3/21 11:12:29 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
 * Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 *
 * Notice
 *   The solution is guaranteed to be unique.
 *
 * Example
 *   Given 4 gas stations with gas[i]=[1,1,3,1], and the cost[i]=[2,2,1,1]. The starting gas station's index is 2.
 */

class Solution {
public:
  /**
   * @param gas: An array of integers
   * @param cost: An array of integers
   * @return: An integer
   */
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int len = gas.size();
    int gas_remain = 0;
    bool is_complete = false;
    int start = 0;
    while (start < len && !is_complete) {
      gas_remain = 0;
      for (int pos = start; pos < start + len; pos++) {
	if (gas[pos % len] + gas_remain >= cost[pos % len]) {// 从 pos 到 pos + 1 有足够燃料
	  gas_remain = gas[pos % len] + gas_remain - cost[pos % len];
	  if ((pos + 1) % len == start) {
	    // 注意，此时成功循环
	    is_complete = true;
	    break;
	  }
	  continue;
	} else {// 如果从 pos 到 pos + 1 燃料不足，则下次只需要从 pos + 1 开始循环即可
	  if (pos % len < start) {// 此时的 pos 位置已经循环到 start 前面，一旦不能成功，则必然失败
	    return -1;
	  } else {
	    start = pos % len + 1;
	    break;
	  }
	}
      }
    }
    if (is_complete) {
      return start;
    } else {
      return -1;
    }
  }
};

int main() {
  int gas_arr[] = {2,4};
  int cost_arr[] = {3,4};
  vector<int> gas(gas_arr, gas_arr + sizeof(gas_arr)/sizeof(int));
  vector<int> cost(cost_arr, cost_arr + sizeof(cost_arr)/sizeof(int));
  Solution sl;
  int res = sl.canCompleteCircuit(gas, cost);
  cout << res << endl;
  return 0;
}
