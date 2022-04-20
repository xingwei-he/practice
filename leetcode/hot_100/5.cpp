/**************************************
* He Xingwei, All Rights Reserved.
* Filename:5.cpp
* Date:2022-04-18 19:54:00
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
    	if (s.empty()) {
    		return string();
    	}
    	int n = s.size();
    	vector<vector<bool>> dp(n, vector<bool>(n, false));
    	for (int i = 0; i < n; i++) {
    		dp[i][i] = true;
    	}

    	int max_len = 1;
        int left = 0, right = 0;
    	for (int i = n - 2; i >= 0; i--) {
    		for (int j = i + 1; j < n; j++) {
    			if (s[i] == s[j]) {
    				if (j == i + 1) {
    					dp[i][j] = true;
    					if (max_len < j - i + 1) {
                            max_len  = j - i + 1;
                            left = i;
                            right = j;
                        }
    				} else {
    					if (true == dp[i + 1][j - 1]) {
    						dp[i][j] = true;
                            if (max_len < j - i + 1) {
                                max_len = j - i + 1;
                                left = i;
                                right = j;
                            }
    					}
    				}
    			}
    		}
    	}
    	return s.substr(left, right - left + 1);
    }
};
