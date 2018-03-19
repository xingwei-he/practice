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
  int maximalRectangle(vector<vector<bool> > &matrix) {
    if (matrix.size() <= 0) {
      return 0;
    }
    int row_size = matrix.size();
    int col_size = matrix[0].size();
    int res = 0;
    vector<int> left_border(col_size, INT_MIN);
    vector<int> right_border(col_size, INT_MAX);
    vector<int> height(col_size, 0);
    for (int i = 0; i < row_size; i++) {
      int cur_left = 0;
      int cur_right = col_size;
      // left_border 左边界
      for (int j = 0; j < col_size; j++) {
	if (true == matrix[i][j]) {
	  left_border[j] = max(left_border[j], cur_left);
	} else {
	  left_border[j] = 0;
	  cur_left = j + 1;
	}
      }
      // right_border 右边界
      for (int j = col_size - 1; j >= 0; j--) {
	if (true == matrix[i][j]) {
	  right_border[j] = min(right_border[j], cur_right);
	} else {
	  right_border[j] = col_size;
	  cur_right = j;
	}
      }
      // height 高度
      // 如果当前元素 matrix[i][j] 是 1，则高度为 matrix[i - 1][j] + 1
      for (int j = 0; j < col_size; j++) {
	if (true == matrix[i][j]) {
	  height[j] += 1;
	} else {
	  height[j] = 0;
	}
      }
      // 计算结果
      for (int j = 0; j < col_size; j++) {
	res = max(res, (right_border[j] - left_border[j]) * height[j]);
      }
      cout << "l:";
      debug1DVector<int>(left_border, 2);
      cout << "r:";
      debug1DVector<int>(right_border, 2);
      cout << "h:";
      debug1DVector<int>(height, 2);
      cout << "* * * * * * * *" << endl;
    }
    return res;
  }
};

int main() {
  bool r0[] = {1,1,0,0,1};
  bool r1[] = {0,1,0,0,1};
  bool r2[] = {0,0,1,1,1};
  bool r3[] = {0,0,1,1,1};
  bool r4[] = {0,0,0,0,1};
  vector<bool> row0(r0, r0 + sizeof(r0)/sizeof(bool));
  vector<bool> row1(r1, r1 + sizeof(r1)/sizeof(bool));
  vector<bool> row2(r2, r2 + sizeof(r2)/sizeof(bool));
  vector<bool> row3(r3, r3 + sizeof(r3)/sizeof(bool));
  vector<bool> row4(r4, r4 + sizeof(r4)/sizeof(bool));
  vector<vector<bool> > matrix;
  matrix.push_back(row0);
  matrix.push_back(row1);
  matrix.push_back(row2);
  matrix.push_back(row3);
  matrix.push_back(row4);
  /* case 2
  bool r0[] = {1};
  vector<bool> row0(r0, r0 + sizeof(r0)/sizeof(bool));
  vector<vector<bool> > matrix;
  matrix.push_back(row0);
  */
 
  Solution sl;
  int res = sl.maximalRectangle(matrix);
  cout << "res:" << res << endl;
  return 0;
}
