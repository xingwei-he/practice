/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:34_N-Queens_II.cc
 * Author:
 * Mail:
 * Created Time:星期二  1/ 9 19:14:43 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Follow up for N-Queens problem.
 * Now, instead outputting board configurations, return the total number of distinct solutions.
 *
 * Example
 * For n=4, there are 2 distinct solutions.
 */

class Solution {
public:
  /*
   * @param n: The number of queens.
   * @return: The total number of distinct solutions.
   */
  bool isValidPosition(vector<string>& board, int row, int col) {
    int n = board.size();
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < n; j++) {
	if (board[i][j] == 'Q') {
	  if (i == row || j == col || abs(i - row) == abs(j - col)) {
	    return false;
	  }
	}
      }
    }
    return true;
  }

  void placeQueen(vector<string>& board, int& counter, int row, int col) {
    int n = board.size();
    if (row == n || col == n) {
      return;
    }
    if (true == isValidPosition(board, row, col)) {
      board[row][col] = 'Q';
      if (row == n - 1) {
	counter++;
	board[row][col] = '.';
	return;
      } else {
	placeQueen(board, counter, row + 1, 0);
	board[row][col] = '.';
	placeQueen(board, counter, row, col + 1);
      }
    } else {
      if (col == n - 1) {
	return;
      } else {
	placeQueen(board, counter, row, col + 1);
      }
    }
  }

  int totalNQueens(int n) {
    if (n < 0) {
      return 0;
    }
    int counter = 0;
    int row = 0;
    int col = 0;
    string one_row(n, '.');
    vector<string> board(n, one_row);
    placeQueen(board, counter, row, col);
    return counter;
  }
};

int main() {
  int n = 1;
  Solution sl;
  int counter = sl.totalNQueens(n);
  cout << "counter:" << counter << endl;
  return 0;
}
