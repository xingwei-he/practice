/**************************************
* He Xingwei, All Rights Reserved.
* Filename:322.cpp
* Date:2022-05-04 23:13:00
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX - 1); // 记录凑成 i 的最小硬币个数
        if (0 == amount) {
            return 0;
        }
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};