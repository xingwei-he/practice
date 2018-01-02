/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:185_Matrix_Zigzag_Traversal.cc
 * Author:
 * Mail:
 * Created Time:星期二  1/ 2 15:36:05 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in ZigZag-order.
 *
 * Example
 * Given a matrix:
 * [
 *   [1, 2,  3,  4],
 *   [5, 6,  7,  8],
 *   [9,10, 11, 12]
 * ]
 * return [1, 2, 5, 9, 6, 3, 4, 7, 10, 11, 8, 12]
 */

class Solution {
public:
  /*
   * @param matrix: An array of integers
   * @return: An array of integers
   */
  vector<int> printZMatrix(vector<vector<int> > &matrix) {
    vector<int> z;
    if (matrix.size()==0) {
      return z;
    } else {
      if (matrix[0].size()==0) {
	return z;
      }
    }
    int x, y, dx, dy, count, m, n;
    x = y = 0;
    count = 1;
    dx = -1; dy = 1; 
    m = matrix.size();
    n = matrix[0].size();
    z.push_back(matrix[0][0]);
    while (count < m * n) {
      if (x + dx >= 0 && y + dy >= 0 && x + dx < m && y + dy < n) {
	x += dx;
	y += dy;
      } else {
	if (dx == -1 && dy == 1) {
	  if (y + 1 < n) {
	    ++y;
	  } else {
	    ++x;
	  }
	  dx = 1;
	  dy = -1;
	} else {
	  if (x + 1 < m) {
	    ++x;
	  } else {
	    ++y;
	  }
	  dx = -1;
	  dy = 1;
	}
      }
      z.push_back(matrix[x][y]);
      ++count;
    }
    return z;
  }
};

int main() {
  return 0;
}
