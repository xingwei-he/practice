/**************************************
* He Xingwei, All Rights Reserved.
* Filename:79.cpp
* Date:2022-04-19 19:53:15
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
	/*
	 * search 函数递归查找word
	 * i, j 表示在board中的起始位置
	 * start 表示word的起始位置
	 * path 表示访问过board的位置
	 * found 为查找结果
	 */
	void search(int i, int j,
			vector<vector<char>>& board,
			string word,
			int pos,
			vector<vector<bool>>& path,
			bool& found) {
		int m = board.size();
		int n = board[0].size();
		// 越界
		if (i < 0 || i >= m || j < 0 || j >= n) {
			return;
		}
		// 边界条件
		if (path[i][j] || found || board[i][j] != word[pos]) {
			return;
		}
		if (pos == word.size() - 1) {
			found = true;
			return;
		}
		path[i][j] = true; // 修改当前节点状态，注意后面要回溯
		// 四个方向探测
		search(i - 1, j, board, word, pos + 1, path, found);
		search(i + 1, j, board, word, pos + 1, path, found);
		search(i, j - 1, board, word, pos + 1, path, found);
		search(i, j + 1, board, word, pos + 1, path, found);
		path[i][j] = false;
	}

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty()) {
        	return false;
        }
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> path(m, vector<bool>(n, false));
        bool found = false;
        for (int i = 0; i < m; i++) {
        	for (int j = 0; j < n; j++) {
        		search(i, j, board, word, 0, path, found);
        	}
        }
        return found;
    }
};