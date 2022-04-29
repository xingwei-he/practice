/**************************************
* He Xingwei, All Rights Reserved.
* Filename:offer-05.cpp
* Date:2022-04-27 17:10:16
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int counter = 0;
        for (auto &c : s) {
            if (c == ' ') {
                counter++;
            }
        }
        int len = s.size();
        int new_len = s.size() + counter * 2;
        int pos = len - 1;
        for (int i = len - 1; i >= 0; i--) {
            if (' ' == s[i]) {
                s[pos--] = '0';
                s[pos--] = '2';
                s[pos--] = '%';
            } else {
                s[pos--] = s[i];
            }
        }
        return s;
    }
};