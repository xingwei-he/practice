/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:436_Maximal_Square.cc
 * Author:
 * Mail:
 * Created Time:星期五  3/16 16:03:33 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.
 *
 * Example
 *   For example, given the following matrix:
 *   1 0 1 0 0
 *   1 0 1 1 1
 *   1 1 1 1 1
 *   1 0 0 1 0
 *   Return 4.
 */

class Solution {
public:
  /**
   * @param matrix: a matrix of 0 and 1
   * @return: an integer
   */
  // DP
  // 用 matrix[i][j] 记录以 matrix[i][j] 为右下角的正方形的边长
  int maxSquare(vector<vector<int> > &matrix) {
    if (matrix.size() <= 0) {
      return 0;
    }
    int row_size = matrix.size();
    int col_size = matrix[0].size();
    int len = matrix[0][0];
    for (int i = 1; i < row_size; i++) {
      for (int j = 1; j < col_size; j++) {
	if (matrix[i][j] > 0 &&
	    matrix[i - 1][j] > 0 &&
	    matrix[i][j - 1] > 0 &&
	    matrix[i - 1][j - 1] > 0) {
	  matrix[i][j] = min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1])) + 1;
	}
	if (len < matrix[i][j]) {
	  len = matrix[i][j];
	}
      }
    }
    return len * len;
  }
};

int main() {
  /*
  int r0[] = {1, 0, 1, 0, 0};
  int r1[] = {1, 0, 1, 1, 1};
  int r2[] = {1, 1, 1, 1, 1};
  int r3[] = {1, 0, 0, 1, 0};
  vector<int> row0(r0, r0 + sizeof(r0)/sizeof(int));
  vector<int> row1(r1, r1 + sizeof(r1)/sizeof(int));
  vector<int> row2(r2, r2 + sizeof(r2)/sizeof(int));
  vector<int> row3(r3, r3 + sizeof(r3)/sizeof(int));
  vector<vector<int> > matrix;
  matrix.push_back(row0);
  matrix.push_back(row1);
  matrix.push_back(row2);
  matrix.push_back(row3);
  */
  int r0[] = {0};
  int r1[] = {1};
  int r2[] = {0};
  int r3[] = {1};
  vector<int> row0(r0, r0 + sizeof(r0)/sizeof(int));
  vector<int> row1(r1, r1 + sizeof(r1)/sizeof(int));
  vector<int> row2(r2, r2 + sizeof(r2)/sizeof(int));
  vector<int> row3(r3, r3 + sizeof(r3)/sizeof(int));
  vector<vector<int> > matrix;
  matrix.push_back(row0);
  matrix.push_back(row1);
  matrix.push_back(row2);
  matrix.push_back(row3);
  debug2DVector<int>(matrix, 3);
  Solution sl;
  int area = sl.maxSquare(matrix);
  debug2DVector<int>(matrix, 3);
  cout << area << endl;
  return 0;
}
