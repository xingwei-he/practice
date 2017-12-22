/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:38_Search_a_2D_Matrix_II.cc
 * Author:
 * Mail:
 * Created Time:星期五 12/22 10:50:23 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Write an efficient algorithm that searches for a value in an m x n matrix, return the occurrence of it.
 *
 * This matrix has the following properties:
 *   Integers in each row are sorted from left to right.
 *   Integers in each column are sorted from up to bottom.
 *   No duplicate integers in each row or column.
 *
 * Example
 * Consider the following matrix:
 * [
 *   [1, 3, 5, 7],
 *   [2, 4, 7, 8],
 *   [3, 5, 9, 10]
 * ]
 * Given target = 3, return 2.
 */

class Solution {
public:
  /*
   * @param matrix: A list of lists of integers
   * @param target: An integer you want to search in matrix
   * @return: An integer indicate the total occurrence of target in the given matrix
   */
  int searchMatrix(vector<vector<int> > &matrix, int target) {
    int m = matrix.size();
    if (0 == m) {
      return 0;
    }
    int n = matrix[0].size();
    int i = 0;
    int j = n - 1;
    int counter = 0;
    while (j >= 0 && i <= m - 1) {
      if (target == matrix[i][j]) {
	counter++;
	i++;
      } else if (target < matrix[i][j]) {
	j--;
      } else {
	i++;
      }
    }
    return counter;
  }
};

int main() {
  int arr[] = {3, 4};
  vector<vector<int> > matrix(1, vector<int>(begin(arr), end(arr)));
  Solution sl;
  int counter = sl.searchMatrix(matrix, 3);
  cout << counter << endl;
  return 0;
}
