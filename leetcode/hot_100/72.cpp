/**************************************
* He Xingwei, All Rights Reserved.
* Filename:72.cpp
* Date:2022-05-01 10:22:28
* Description:
**************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
    	int len1 = word1.size();
    	int len2 = word2.size();
    	if (0 == len1) {
    		return len2;
    	}
    	if (0 == len2) {
    		return len1;
    	}
    	// 动态规划辅助数组
    	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    	// 初始化 dp
    	for (int i = 0; i <= len1; i++) {
    		dp[i][0] = i;
    	}
    	for (int j = 0; j <= len2; j++) {
    		dp[0][j] = j;
    	}
    	// 填充 dp
    	for (int i = 1; i <= len1; i++) {
    		for (int j = 1; j <= len2; j++) {
    			if (word1[i - 1] == word2[j - 1]) { // 注意，word中的坐标和dp中有漂移
    				dp[i][j] = min(1 + min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
    			} else {
    				dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
    			}
    		}
    	}
    	return dp[len1][len2];
    }
};

int main() {
	string word1 = "horse";
	string word2 = "ros";
	Solution s;
	int res = s.minDistance(word1, word2);
	cout << res << endl;
	return 0;
}
