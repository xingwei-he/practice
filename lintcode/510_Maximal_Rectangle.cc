/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:510_Maximal_Rectangle.cc
 * Author:
 * Mail:
 * Created Time:2018年03月18日 星期日 22时27分47秒
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given a 2D boolean matrix filled with False and True, find the largest rectangle containing all True and return its area.
 *
 * Example
 *   Given a matrix:
 *   [
 *     [1, 1, 0, 0, 1],
 *     [0, 1, 0, 0, 1],
 *     [0, 0, 1, 1, 1],
 *     [0, 0, 1, 1, 1],
 *     [0, 0, 0, 0, 1]
 *   ]
 *   return 6.
 **/

class Solution {
public:
  /**
   * @param matrix: a boolean 2D matrix
   * @return: an integer
   */
  // DP
  //int maximalRectangle(vector<vector<bool> > &matrix) {
  TODO
  int maximalRectangle(vector<vector<int> > &matrix) {
    int row_size = matrix.size();
    int col_size = matrix[0].size();
    vector<vector<int> > left_border_matrix(row_size, vector<int>(col_size, 0));
    vector<vector<int> > right_border_matrix(row_size, vector<int>(col_size, 0));
    vector<vector<int> > height_matrix(row_size, vector<int>(col_size, 0));
    for (int i = 0; i < row_size; i++) {
      for (int j = 0; j < col_size; j++) {
	if (true == matrix[i][j]) {
	  if (0 == j) {
	    left_border_matrix[i][j] = 1;
	  } else {
	    if (true == matrix[i][j - 1]) {
	      left_border_matrix[i][j] = left_border_matrix[i][j - 1];
	    } else {
	      left_border_matrix[i][j] = 1;
	    }
	  }
	}
      }
      for (int j = col_size - 1; j >= 0; j--) {
	if (true == matrix[i][j]) {
	  if (col_size - 1 == j) {
	    right_border_matrix[i][j] = col_size;
	  } else {
	    if (true == matrix[i][j + 1]) {
	      right_border_matrix[i][j] = right_border_matrix[i][j + 1];
	    } else {
	      right_border_matrix[i][j] = j + 1;
	    }
	  }
	}
      }
      for (int j = 0; j < col_size; j++) {
	if (true == matrix[i][j]) {
	  if (0 == j) {
	    height_matrix[i][j] = 1;
	  } else {
	    if (true == matrix[i - 1][j]) {
	      height_matrix[i][j] = height_matrix[i - 1][j] + 1;
	    } else {
	      height_matrix[i][j] = 1;
	    }
	  }
	}
      }
    }
    cout << "********" << endl;
    debug2DVector<int>(left_border_matrix, 2);
    cout << "********" << endl;
    debug2DVector<int>(right_border_matrix, 2);
    cout << "********" << endl;
    debug2DVector<int>(height_matrix, 2);

    return 0;
  }
};

int main() {
  int r0[] = {1,1,0,0,1};
  int r1[] = {0,1,0,0,1};
  int r2[] = {0,0,1,1,1};
  int r3[] = {0,0,1,1,1};
  int r4[] = {0,0,0,0,1};
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
  int res = sl.maximalRectangle(matrix);
  cout << "res:" << res << endl;
  return 0;
}
