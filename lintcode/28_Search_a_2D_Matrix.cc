/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:28_Search_a_2D_Matrix.cc
 * Author:
 * Mail:
 * Created Time:星期四 12/21 10:19:37 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 *   Integers in each row are sorted from left to right.
 *   The first integer of each row is greater than the last integer of the previous row.
 *
 * Example
 * Consider the following matrix:
 * [
 *   [1, 3, 5, 7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * Given target = 3, return true.
 */

class Solution {
public:
  /*
   * @param matrix: matrix, a list of lists of integers
   * @param target: An integer
   * @return: a boolean, indicate whether matrix contains target
   */
  // 二分查找
  int getData(const vector<vector<int> >& matrix, int pos) {
    //int m = matrix.size();
    int n = matrix[0].size();
    int row = pos / n;
    int col = pos % n;
    return matrix[row][col];
  }

  bool searchMatrix(vector<vector<int> > &matrix, int target) {
    if (matrix.size() == 0) {
      return false;
    }
    int m = matrix.size();
    int n = matrix[0].size();
    int left = 0;
    int right = m * n - 1;
    int mid = 0;
    while (left <= right) {
      mid = (left + right) / 2;
      if (getData(matrix, mid) < target) {
	left = mid + 1;
      } else if (getData(matrix, mid) > target) {
	right = mid - 1;
      } else {
	return true;
      }
    }
    return false;
  }
};

int main() {
  vector<vector<int> > matrix(2, vector<int>(3));
  int r1[] = {1,2,3};
  int r2[] = {4,5,6};
  matrix[0] = vector<int>(begin(r1), end(r1));
  matrix[1] = vector<int>(begin(r2), end(r2));
  int target = 5;
  Solution sl;
  bool find = sl.searchMatrix(matrix, target);
  cout << find << endl;
  return 0;
}
