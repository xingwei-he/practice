/**************************************
* He Xingwei, All Rights Reserved.
* Filename:offer-10-1.cpp
* Date:2022-04-26 23:58:29
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    const int MOD = 1000000007;
    int fib(int n) {
        if (0 == n) return 0;
        if (1 == n) return 1;
        int fib_a = 0, fib_b = 0;
        int res = 1;
        for (int i = 2; i <= n; i++) {
            fib_a = fib_b;
            fib_b = res;
            res = (fib_a + fib_b) % MOD;
        }
        return res;
    }
};