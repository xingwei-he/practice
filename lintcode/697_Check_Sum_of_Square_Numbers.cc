/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:697_Check_Sum_of_Square_Numbers.cc
 * Author:
 * Mail:
 * Created Time:星期二 12/26 17:29:15 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a integer c, your task is to decide whether there're two integers a and b such that a^2 + b^2 = c.
 *
 * Example
 * Given n = 5
 * Return true // 1 * 1 + 2 * 2 = 5
 * Given n = -5
 * Return false
 */

class Solution {
public:
  /*
   * @param : the given number
   * @return: whether whether there're two integers
   */
  bool checkSumOfSquareNumbers(int num) {
    bool res = false;
    unordered_set<int> uset;
    if (num < 0) {
      return false;
    } else if (0 == num) {
      return true;
    }
    int num_sqrt = sqrt(num);
    for (int i = 0; i < num_sqrt; i++) {
      int square = i * i;
      uset.insert(square);
    }
    for (int i = 0; i <= num_sqrt; i++) {
      if (uset.find(num - (i * i)) != uset.end()) {
	return true;
      }
    }
    return res;
  }
};

int main() {
  int data1 = 5;
  int data2 = 100;
  int data3 = 11;
  Solution sl;
  cout << "data1:" << data1 << "\t" << boolalpha << sl.checkSumOfSquareNumbers(data1) << endl;
  cout << "data2:" << data2 << "\t" << boolalpha << sl.checkSumOfSquareNumbers(data2) << endl;
  cout << "data3:" << data3 << "\t" << boolalpha << sl.checkSumOfSquareNumbers(data3) << endl;
  
  return 0;
}

