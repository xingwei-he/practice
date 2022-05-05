/**************************************
* He Xingwei, All Rights Reserved.
* Filename:647.cpp
* Date:2022-05-03 21:37:38
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
    	if (s.empty()) {
    		return 0;
    	}
    	int n = s.size();
    	int counter = 0;
    	vector<vector<bool>> dp(n, vector<bool>(n, false));
    	for (int i = n - 1; i >= 0; i--) {
    		for (int j = i; j < n; j++) {
    			if (i == j) { // 单个字母即为回文字
    				dp[i][j] = true;
    			} else if (i == j - 1) { // 如果是连续两个字母且相同，则为回文字
    				if (s[i] == s[j]) {
    					dp[i][j] = true;
    				}
    			} else { // s[i] 与 s[j] 相同，则两端缩小
    				if (s[i] == s[j] && dp[i + 1][j - 1]) {
    					dp[i][j] = true;
    				}
    			}
    			if (dp[i][j]) {
    				counter++;
    			}
    		}
    	}
    	return counter;
    }
};