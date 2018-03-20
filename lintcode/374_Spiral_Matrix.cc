/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:374_Spiral_Matrix.cc
 * Author:
 * Mail:
 * Created Time:星期二  3/20 18:32:21 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 *
 * Example
 *   Given the following matrix:
 *   [
 *     [ 1, 2, 3 ],
 *     [ 4, 5, 6 ],
 *     [ 7, 8, 9 ]
 *   ]
 *   You should return [1,2,3,6,9,8,7,4,5].
 **/

class Solution {
public:
  /**
   * @param matrix: a matrix of m x n elements
   * @return: an integer list
   */
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> res;
    if (matrix.size() <= 0) {
      return res;
    }
    // 分别记录四个边界
    int up = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
    int total = matrix.size() * matrix[0].size();
    int i = 0;
    while (up <= down && left <= right) {
      // 注意
      // 下列每个 for 循环要测试当前要遍历的行/列的合法性
      for (int j = left; j <= right && up <= down; j++) {
	res.push_back(matrix[up][j]);
      }
      up++;
      for (int i = up; i <= down && left <= right; i++) {
	res.push_back(matrix[i][right]);
      }
      right--;
      for (int j = right; j >= left && up <= down; j--) {
	res.push_back(matrix[down][j]);
      }
      down--;
      for (int i = down; i >= up && left <= right; i--) {
	res.push_back(matrix[i][left]);
      }
      left++;
    }
    return res;
  }
};

int main() {
  int r0[] = {1,2,3,4,5};
  int r1[] = {6,7,8,9,10};
  int r2[] = {11,12,13,14,15};
  vector<int> row0(r0, r0 + sizeof(r0)/sizeof(int));
  vector<int> row1(r1, r1 + sizeof(r1)/sizeof(int));
  vector<int> row2(r2, r2 + sizeof(r2)/sizeof(int));
  vector<vector<int> > matrix;
  matrix.push_back(row0);
  matrix.push_back(row1);
  matrix.push_back(row2);
  Solution sl;
  vector<int> res = sl.spiralOrder(matrix);
  debug1DVector<int>(res, 3);
  return 0;
}
