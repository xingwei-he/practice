/**************************************
* He Xingwei, All Rights Reserved.
* Filename:547.cpp
* Date:2022-04-21 13:42:59
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> &isConnected, int i, vector<bool> &visited) {
        visited[i] = true;
        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[i][j] == 1 && !visited[j]) {
                dfs(isConnected, j, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        if (n <= 1) {
            return n;
        }
        int counter = 0; // 记录结果数

        vector<bool> visited(n, false); // 辅助数组，标记是否已经访问。
                                        // 注意，如果已经访问过，说明该位置与之前的某个位置属于同一个圈子
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(isConnected, i, visited);
                counter++;
            }
        }
        return counter;
    }
};
