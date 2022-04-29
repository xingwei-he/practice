/**************************************
* He Xingwei, All Rights Reserved.
* Filename:offer-12.cpp
* Date:2022-04-27 14:29:30
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>> &board, int i, int j, string &word, int k) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || k < 0 || k >= word.size()) {
            // 越界
            return false;
        }
        /*
        if (board[i][j] == '\0') {
            // 访问过
            return false;
        }
        */
        if (board[i][j] != word[k]) {
            // 字符不匹配
            return false;
        }
        if (k == word.size() - 1) {
            return true;
        }
        board[i][j] = '\0';
        bool res = dfs(board, i - 1, j, word, k + 1)
                || dfs(board, i + 1, j, word, k + 1)
                || dfs(board, i, j - 1, word, k + 1)
                || dfs(board, i, j + 1, word, k + 1);
        board[i][j] = word[k];
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0 || word.size() == 0) {
            return false;
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) { 
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};