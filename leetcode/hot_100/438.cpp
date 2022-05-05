/**************************************
* He Xingwei, All Rights Reserved.
* Filename:438.cpp
* Date:2022-05-05 22:28:12
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len1 = s.size(); // s
        int len2 = p.size(); // p
        if (len1 < len2) { // 如果s长度小于p，则不可能有p的异位词
            return vector<int>();
        }
        vector<int> res;
        vector<int> dict1(26, 0); // s
        vector<int> dict2(26, 0); // p
        for (int i = 0; i < len2; i++) {
            dict1[s[i] - 'a'] += 1;
            dict2[p[i] - 'a'] += 1;
        }
        if (dict1 == dict2) {
            res.emplace_back(0);
        }
        for (int i = len2; i < len1; i++) {
            dict1[s[i - len2] - 'a'] -= 1;
            dict1[s[i] - 'a'] += 1;
            if (dict1 == dict2) {
                res.emplace_back(i - len2 + 1);
            }
        }
        return res;
    }
};