/**************************************
* He Xingwei, All Rights Reserved.
* Filename:48.cpp
* Date:2022-04-30 19:23:57
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return;
        }
        int n = matrix.size();
        // 按 \ 方向折叠
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 按 | 方向折叠
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};