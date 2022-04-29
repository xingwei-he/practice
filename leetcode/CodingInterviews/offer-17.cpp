/**************************************
* He Xingwei, All Rights Reserved.
* Filename:offer-17.cpp
* Date:2022-04-27 20:53:01
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        if (0 == n) {
            return res;
        }
        int max_val = 9;
        for (int i = 1; i < n; i++) {
            max_val = max_val * 10 + 9;
        }
        res.reserve(max_val);
        for (int i = 1; i <= max_val; i++) {
            res.emplace_back(i);
        }
        return res;
    }
};