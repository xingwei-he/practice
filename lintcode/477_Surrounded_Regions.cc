/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:477_Surrounded_Regions.cc
 * Author:
 * Mail:
 * Created Time:星期五  3/16 12:48:49 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 * A region is captured by flipping all 'O''s into 'X''s in that surrounded region.
 *
 * Example
 *   X X X X
 *   X O O X
 *   X X O X
 *   X O X X
 * After capture all regions surrounded by 'X', the board should be:
 *   X X X X
 *   X X X X
 *   X X X X
 *   X O X X
 */

class Solution {
public:
  /*
   * @param board: board a 2D board containing 'X' and 'O'
   * @return: nothing
   */
  void DFS(vector<vector<char> >& board, int x, int y) {
    if (board.size() <= 0) {
      return;
    }
    int row_len = board.size();
    int col_len = board[0].size();
    if (board[x][y] == 'O') {
      board[x][y] = '*';
    }
    if (x - 1 >= 0 && board[x - 1][y] == 'O') {
      DFS(board, x - 1, y);
    }
    if (x + 1 < row_len && board[x + 1][y] == 'O') {
      DFS(board, x + 1, y);
    }
    if (y - 1 >= 0 && board[x][y - 1] == 'O') {
      DFS(board, x, y - 1);
    }
    if (y + 1 < col_len && board[x][y + 1] == 'O') {
      DFS(board, x, y + 1);
    }
  }

  void surroundedRegions(vector<vector<char> > &board) {
    if (board.size() <= 0) {
      return;
    }
    int row_len = board.size();
    int col_len = board[0].size();
    for (int i = 0; i < row_len; i++) {
      if (board[i][0] == 'O') {
	DFS(board, i, 0);
      }
      if (board[i][col_len - 1] == 'O') {
	DFS(board, i, col_len - 1);
      }
    }
    for (int j = 0; j < col_len; j++) {
      if (board[0][j] == 'O') {
	DFS(board, 0, j);
      }
      if (board[row_len - 1][j] == 'O') {
	DFS(board, row_len - 1, j);
      }
    }
    for (int i = 0; i < row_len; i++) {
      for (int j = 0; j < col_len; j++) {
	if (board[i][j] == '*') {
	  board[i][j] = 'O';
	} else if (board[i][j] == 'O') {
	  board[i][j] = 'X';
	}
      }
    }
  }
};

int main() {
  char r0[] = {'X', 'X', 'X', 'X'};
  char r1[] = {'X', 'O', 'O', 'X'};
  char r2[] = {'X', 'X', 'O', 'X'};
  char r3[] = {'X', 'O', 'X', 'X'};
  char r4[] = {'X', 'O', 'O', 'O'};
  vector<char> row0(r0, r0 + sizeof(r0)/sizeof(char));
  vector<char> row1(r1, r1 + sizeof(r1)/sizeof(char));
  vector<char> row2(r2, r2 + sizeof(r2)/sizeof(char));
  vector<char> row3(r3, r3 + sizeof(r3)/sizeof(char));
  vector<char> row4(r4, r4 + sizeof(r4)/sizeof(char));
  vector<vector<char> > board;
  board.push_back(row0);
  board.push_back(row1);
  board.push_back(row2);
  board.push_back(row3);
  board.push_back(row4);
  cout << "origin board --->" << endl;
  debug2DVector<char>(board, 2);
  Solution sl;
  sl.surroundedRegions(board);
  cout << "processed board --->" << endl;
  debug2DVector<char>(board, 2);
  return 0;
}
