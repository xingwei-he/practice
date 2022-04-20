/**************************************
* He Xingwei, All Rights Reserved.
* Filename:51.cpp
* Date:2022-04-19 15:54:17
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
	// 判断是否可以放置（逐行填充）
	bool isValidPosition(vector<string>& board, int row, int col) {
		int n = board.size();
		for (int i = 0; i < row; i++) { // 由于是逐行填充，所以大于row的行是不需要判断的
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

	// 递归放置
	void placeQueen(vector<string>& board, vector<vector<string>>& res, int row, int col) {
		int n = board.size();
		// 超出棋盘
		if (row == n || col == n) {
			return;
		}
		if (true == isValidPosition(board, row, col)) { // 当前位置OK
			board[row][col] = 'Q';
			if (row == n - 1) { // 填充到最后一行，该board为可行解
				res.emplace_back(board);
				board[row][col] = '.'; // 将刚放置的皇后还原，回溯
				return;
			} else {
				// 该行放置了皇后，继续判断
				placeQueen(board, res, row + 1, 0); // 下移
				board[row][col] = '.';
				placeQueen(board, res, row, col + 1); // 右移
			}
		} else { // 当前位置不可以放置皇后
			if (col == n - 1) {
				return;
			} else {
				placeQueen(board, res, row, col + 1); // 右移
			}
		}
	}

    vector<vector<string>> solveNQueens(int n) {
    	vector<vector<string>> res;
    	if (n < 0) {
    		return res;
    	}
    	int row = 0, col = 0;
    	vector<string> board(n, string(n, '.'));
    	placeQueen(board, res, row, col);
    	return res;
    }
};