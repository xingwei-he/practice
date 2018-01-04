/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:389_Valid_Sudoku.cc
 * Author:
 * Mail:
 * Created Time:星期四  1/ 4 13:28:07 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Determine whether a Sudoku is valid.
 *
 * The Sudoku board could be partially filled, where empty cells are filled with the character
 *
 * Notice
 *   A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 */

class Solution {
public:
  /*
   * @param board: the board
   * @return: whether the Sudoku is valid
   */
  bool isValidSudoku(vector<vector<char> > &board) {
    if (board.size() != 9 || board[0].size() != 9) {
      return false;
    }
    for (int i = 0; i < 9; i++) {
      unordered_set<char> s;
      for(int j = 0; j < 9; j++) {
	if ('.' != board[i][j]) {
	  if (s.find(board[i][j]) == s.end()) {
	    s.insert(board[i][j]);
	  } else {
	    return false;
	  }
	}
      }
    }
    for (int j = 0; j < 9; j++) {
      unordered_set<char> s;
      for (int i = 0; i < 9; i++) {
	if ('.' != board[i][j]) {
	  if (s.find(board[i][j]) == s.end()) {
	    s.insert(board[i][j]);
	  } else {
	    return false;
	  }
	}
      }
    }
    for (int b = 0; b < 9; b++) {
      unordered_set<char> s;
      for (int i = 0; i < 9; i++) {
	for (int j = 0; j < 9; j++) {
	  int current_block = (i / 3) * 3 + j / 3;
	  if (b == current_block) {
	    if ('.' != board[i][j]) {
	      if (s.find(board[i][j]) == s.end()) {
	        s.insert(board[i][j]);
	      } else {
		return false;
	      }
	    }
	  }
	}
      }
    }
    return true;
  }
};

int main() {
  return 0;
}
