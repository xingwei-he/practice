/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:381_Spiral_Matrix_II.cc
 * Author:
 * Mail:
 * Created Time:2018年03月20日 星期二 22时03分27秒
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given an integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.
 *
 * Example
 *   Given n = 3,
 *   You should return the following matrix:
 *   [
 *     [ 1, 2, 3 ],
 *     [ 8, 9, 4 ],
 *     [ 7, 6, 5 ]
 *   ]
 */

class Solution {
public:
  /**
   * @param n: An integer
   * @return: a square matrix
   */
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int> > matrix(n, vector<int>(n, 0));
    int up = 0, down = n - 1, left = 0, right = n - 1;
    int val = 1;
    while (up <= down && left <= right) {
      for (int j = left; j <= right && up <= down; j++) {
	matrix[up][j] = val++;
      }
      up++;
      for (int i = up; i <= down && left <= right; i++) {
	matrix[i][right] = val++;
      }
      right--;
      for (int j = right; j >= left && up <= down; j--) {
	matrix[down][j] = val++;
      }
      down--;
      for (int i = down; i >= up && left <= right; i--) {
	matrix[i][left] = val++;
      }
      left++;
    }
    return matrix;
  }
};

int main() {
  int n = 4;
  Solution sl;
  vector<vector<int> > m = sl.generateMatrix(n);
  debug2DVector<int>(m, 3);
  return 0;
}
