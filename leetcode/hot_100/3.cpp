/**************************************
* He Xingwei, All Rights Reserved.
* Filename:3.cpp
* Date:2022-04-18 10:52:15
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        unordered_set<char> char_set;
        int left = 0, right = 1; // 滑动窗口初始状态
        char_set.insert(s[0]);
        int len = 1;
        while (right < s.size()) {
            if (char_set.find(s[right]) == char_set.end()) {
                char_set.insert(s[right]);
                len = len > (right - left + 1) ? len : (right - left + 1);// 更新最长字串长度
                right++;
            } else {
                // 如果遇到right重复的字母，则需要滑动left满足来条件
                char_set.erase(s[left]);
                left++;
            }
        }
        return len;
    }
};
