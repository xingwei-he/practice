/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:110_Minimum_Path_Sum.cc
 * Author:
 * Mail:
 * Created Time:2018年01月01日 星期一 16时51分08秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Notice
 *   You can only move either down or right at any point in time.
 */

class Solution {
public:
  /*
   * @param grid: a list of lists of integers
   * @return: An integer, minimizes the sum of all numbers along its path
   */
  int minPathSum(vector<vector<int> > &grid) {
    if (grid.size() == 0 || grid[0].size() == 0) {
      return -1;
    }
    vector<vector<int> > record(grid.size());
    for (int i = 0; i < grid.size(); i++) {
      record[i].resize(grid[i].size());
      for (int j = 0; j < grid[i].size(); j++) {
	if (0 == i && 0 == j) {
	  record[i][j] = grid[i][j];
	} else if (0 == i) {
	  record[i][j] = record[i][j - 1] + grid[i][j];
	} else if (0 == j) {
	  record[i][j] = record[i - 1][j] + grid[i][j];
	} else {
	  int min_sum = record[i - 1][j] < record[i][j - 1] ? record[i - 1][j] : record[i][j - 1];
	  record[i][j] = grid[i][j] + min_sum;
	}
      }
    }
    return record[grid.size() - 1][grid[grid.size() - 1].size() - 1];
  }
};

int main() {
  vector<vector<int> > grid(1, vector<int>(1, 0));
  Solution sl;
  int min_sum = sl.minPathSum(grid);
  cout << "min_sum:" << min_sum << endl;
  return 0;
}

