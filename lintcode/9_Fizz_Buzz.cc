/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:9_Fizz_Buzz.cc
 * Author:
 * Mail:
 * Created Time:星期五 12/29 13:27:41 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given number n. Print number from 1 to n. But:
 * when number is divided by 3, print "fizz".
 * when number is divided by 5, print "buzz".
 * when number is divided by both 3 and 5, print "fizz buzz".
 *
 * Example
 * If n = 15, you should return:
 * [
 *   "1", "2", "fizz",
 *   "4", "buzz", "fizz",
 *   "7", "8", "fizz",
 *   "buzz", "11", "fizz",
 *   "13", "14", "fizz buzz"
 * ]
 **/

class Solution {
public:
  /*
   * @param n: An integer
   * @return: A list of strings.
   */
  string numberToString(const int& num) {
    string res;
    int n = num;
    while (0 != n) {
      int temp = n % 10;
      n /= 10;
      res.insert(0, 1, char(temp + '0'));
    }
    return res;
  }

  vector<string> fizzBuzz(int n) {
    vector<string> res;
    for (int i = 1; i <= n; i++) {
      if (i % 3 == 0 && i % 5 == 0) {
	res.push_back("fizz buzz");
      } else if (i % 3 == 0) {
	res.push_back("fizz");
      } else if (i % 5 == 0) {
	res.push_back("buzz");
      } else {
	res.push_back(numberToString(i));
      }
    }
    return res;
  }
};

int main() {
  int num = 25;
  Solution sl;
  cout << "num:" << num << endl;
  vector<string> res = sl.fizzBuzz(num);
  for (int i = 0; i < res.size(); i++) {
    cout << setw(8) << res.at(i);
    if ((i + 1) % 5 == 0) {
      cout << endl;
    }
  }
  return 0;
}

