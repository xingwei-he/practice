/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:162_Set_Matrix_Zeroes.cc
 * Author:
 * Mail:
 * Created Time:星期二  3/20 17:24:17 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 *
 * Example
 *   Given a matrix
 *   [
 *     [1,2],
 *     [0,3]
 *   ],
 *   return
 *   [
 *     [0,2],
 *     [0,0]
 *   ]
 */

class Solution {
public:
  /**
   * @param matrix: A lsit of lists of integers
   * @return: nothing
   */
  void setZeroes(vector<vector<int> > &matrix) {
    if (matrix.size() <= 0) {
      return;
    }
    int row_size = matrix.size();
    int col_size = matrix[0].size();
    // 记录第 0 行和第 0 列是否为全零
    bool is_zero_row = false;
    bool is_zero_col = false;
    for (int j = 0; j < col_size; j++) {
      if (matrix[0][j] == 0) {
	is_zero_row = true;
      }
    }
    for (int i = 0; i < row_size; i++) {
      if (matrix[i][0] == 0) {
	is_zero_col = true;
      }
    }
    // 用第 0 行和第 0 列来记录该行列是否应该设为全 0
    for (int i = 1; i < row_size; i++) {
      for (int j = 1; j < col_size; j++) {
	if (matrix[i][j] == 0) {
	  matrix[0][j] = 0;
	  matrix[i][0] = 0;
	}
      }
    }
    // 赋值过程如下
    // 先将第 1~row_size-1 行以及第 1~col_size-1 列赋值
    // 然后根据之前的 is_zero_row 和 is_zero_col 来对第 0 行和第 0 列进行赋值
    for (int i = 1; i < row_size; i++) {
      if (matrix[i][0] == 0) {
	for (int j = 1; j < col_size; j++) {
	  matrix[i][j] = 0;
	}
      }
    }
    for (int j = 1; j < col_size; j++) {
      if (matrix[0][j] == 0) {
	for (int i = 1; i < row_size; i++) {
	  matrix[i][j] = 0;
	}
      }
    }
    if (is_zero_row) {
      for (int j = 0; j < col_size; j++) {
	matrix[0][j] = 0;
      }
    }
    if (is_zero_col) {
      for (int i = 0; i < row_size; i++) {
	matrix[i][0] = 0;
      }
    }
  }
};

int main() {
  int r0[] = {0,2,5,2,2};
  int r1[] = {2,2,5,8,9};
  int r2[] = {3,2,9,5,8};
  int r3[] = {8,6,9,8,9};
  int r4[] = {2147483647,5,1,6,1};
  vector<int> row0(r0, r0 + sizeof(r0)/sizeof(int));
  vector<int> row1(r1, r1 + sizeof(r1)/sizeof(int));
  vector<int> row2(r2, r2 + sizeof(r2)/sizeof(int));
  vector<int> row3(r3, r3 + sizeof(r3)/sizeof(int));
  vector<int> row4(r4, r4 + sizeof(r4)/sizeof(int));
  vector<vector<int> > matrix;
  matrix.push_back(row0);
  matrix.push_back(row1);
  matrix.push_back(row2);
  matrix.push_back(row3);
  matrix.push_back(row4);
  
  Solution sl;
  sl.setZeroes(matrix);
  return 0;
}
