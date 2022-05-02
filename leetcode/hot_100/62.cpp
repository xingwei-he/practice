/**************************************
* He Xingwei, All Rights Reserved.
* Filename:62.cpp
* Date:2022-05-02 22:01:36
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    /* 递归超时
    void findPath(int m, int n, int i, int j, int &counter) {
        if (i == m - 1 && j == n - 1) {
            counter++;
            return;
        }
        if (i < m - 1) { // 可以向下走
            findPath(m, n, i + 1, j, counter);
        }
        if (j < n - 1) {
            findPath(m, n, i, j + 1, counter);
        }
    }
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) {
            return 0;
        }
        int counter = 0;
        findPath(m, n, 0, 0, counter);
        return counter;
    }
    */
    // 动态规划
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 0;
        for (int i = 0; i < m; i++) { // 向下初始化
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++) { // 向右初始化
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution s;
    int m = 19;
    int n = 13;
    int res = s.uniquePaths(m, n);
    cout << res << endl;
    return 0;
}