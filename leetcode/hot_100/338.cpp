/**************************************
* He Xingwei, All Rights Reserved.
* Filename:338.cpp
* Date:2022-04-23 17:17:02
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ones(n + 1, 0);
        auto counter = [](int n) -> int {
                int res = 0;;
                while (n > 0) {
                    if (n & 1 == 1) {
                        res++;
                    }
                    n = n >> 1;
                }
                return res;
            };
        for (int i = 1; i <= n; i++) {
            ones[i] = counter(i);
        }
        return ones;
    }
};