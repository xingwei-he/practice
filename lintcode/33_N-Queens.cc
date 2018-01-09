/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:33_N-Queens.cc
 * Author:
 * Mail:
 * Created Time:星期二  1/ 9 10:27:28 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 *
 * Example
 * There exist two distinct solutions to the 4-queens puzzle:
 * [
 *   // Solution 1
 *   [".Q..",
 *    "...Q",
 *    "Q...",
 *    "..Q."
 *   ],
 *   // Solution 2
 *   ["..Q.",
 *    "Q...",
 *    "...Q",
 *    ".Q.."
 *   ]
 * ]
 */

class Solution {
public:
  /*
   * @param n: The number of queens
   * @return: All distinct solutions
   */
  // 判断是否可以放置皇后
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

  // 递归放置皇后
  void placeQueen(vector<string>& board, vector<vector<string> >& res, int row, int col) {
    int n = board.size();
    // 超过棋牌范围
    if (row == n || col == n) {
      return;
    }
    
    if (true == isValidPosition(board, row, col)) {
      board[row][col] = 'Q';
      if (row == n - 1) {// 如果皇后到达最后一行，则说明该解可行
	res.push_back(board);
	// 将刚放置的皇后还原，回溯
	board[row][col] = '.';
	return;
      } else {
	// 判断下一行是否可以放置皇后，如果不可以，则还原该位置，判断该行下一列是否可以放置皇后
	placeQueen(board, res, row + 1, 0);
	board[row][col] = '.';
	placeQueen(board, res, row, col + 1);
      }
    } else {// 当前位置不能放置皇后
      if (col == n - 1) {
	return;
      } else {
	placeQueen(board, res, row, col + 1);
      }
    }
  }

  vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > res;
    if (n < 0) {
      return res;
    }
    int row = 0;
    int col = 0;
    string one_row(n, '.');
    vector<string> board(n, one_row);
    placeQueen(board, res, row, col);
    return res;
  }
};

int main() {
  int n = 8;
  Solution sl;
  vector<vector<string> > res = sl.solveNQueens(n);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << endl;
    }
    cout << "**\t**\t**\t**" << endl;
  }
  return 0;
}
