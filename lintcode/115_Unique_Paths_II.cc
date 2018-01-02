/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:115_Unique_Paths_II.cc
 * Author:
 * Mail:
 * Created Time:2018年01月01日 星期一 22时24分45秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Follow up for "Unique Paths":
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 * Notice
 *   m and n will be at most 100.
 *
 * Example
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 *
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 *
 * The total number of unique paths is 2.
 *
 */

class Solution {
public:
  /*
   * @param obstacleGrid: A list of lists of integers
   * @return: An integer
   */
  int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    if (obstacleGrid.size() == 0) {
      return 0;
    }
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int> > record(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
	if (1 == obstacleGrid[i][j]) {
	  record[i][j] = 0;
	} else if (0 == i && 0 == j) {
	  record[i][j] = 1;
	} else if (0 == i) {
	  record[i][j] = record[i][j - 1];
	} else if (0 == j) {
	  record[i][j] = record[i - 1][j];
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
