/**************************************
* He Xingwei, All Rights Reserved.
* Filename:offer-14.cpp
* Date:2022-04-27 10:05:25
* Description:
**************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp;
        if (strs.empty()) {
            return lcp;
        }
        if (strs.size() == 1) {
            return strs[0];
        }
        int len = strs[0].size();
        bool is_prefix = true;
        for (int cur = 0; cur < len; cur++) {
            // cur指向当前的字符
            char c = strs[0][cur];
            for (int i = 1; i < strs.size(); i++) {
                // i表示第几个字符串
                if (c != strs[i][cur]) { // 到这就不是lcp了
                    is_prefix = false;
                    break;
                }
            }
            if (is_prefix) {
                lcp = strs[0].substr(0, cur + 1); // cur - 0 + 1
            }
        }
        return lcp;
    }
};

int main() {
    vector<string> strs{"flower","flower","flower","flower"};
    Solution s;
    string lcp = s.longestCommonPrefix(strs);
    cout << lcp << endl;
    return 0;
}