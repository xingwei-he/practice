/**************************************
* He Xingwei, All Rights Reserved.
* Filename:offer-07.cpp
* Date:2022-04-27 21:05:52
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0) {
            return 0;
        }
        int val = 0;
        while (x != 0) {
            int num = x % 10;
            if (val > 214748364 || (x == 214748364 && num > 7)) {
                return 0;
            } else if (val < -214748364 || (x == -214748364 && num < -8)) {
                return 0;
            } else {
                val = val * 10 + num;
                x = x / 10;
            }
        }
        return val;
    }
};