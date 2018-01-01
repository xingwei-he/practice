/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:114_Unique_Paths.cc
 * Author:
 * Mail:
 * Created Time:2018年01月01日 星期一 21时39分01秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * A robot is located at the top-left corner of a m x n grid.
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid.
 * How many possible unique paths are there?
 *
 * Notice
 *   m and n will be at most 100.
 *
 * Example
 * Given m = 3 and n = 3, return 6.
 * Given m = 4 and n = 5, return 35.
 */

class Solution {
public:
  /*
   * @param m: positive integer (1 <= m <= 100)
   * @param n: positive integer (1 <= n <= 100)
   * @return: An integer
   */
  int uniquePaths(int m, int n) {
    if (0 == m || 0 == n) {
      return 0;
    }
    vector<vector<int> > record(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
	if (0 == i || 0 == j) {
	  record[i][j] = 1;
	} else {
	  record[i][j] = record[i - 1][j] + record[i][j - 1];
	}
      }
    }
    return record[m - 1][n - 1];
  }
};

int main() {
  return 0;
}

