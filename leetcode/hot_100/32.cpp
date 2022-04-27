/**************************************
* He Xingwei, All Rights Reserved.
* Filename:32.cpp
* Date:2022-04-24 19:31:29
* Description:
**************************************/

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) {
            return 0;
        }
        int max_len = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    max_len = max(max_len, i - stk.top());
                }
            }
        }
        return max_len;
    }
};

int main() {
	string str("()(()");
	Solution s;
	int len = s.longestValidParentheses(str);
	cout << len << endl;
	return 0;
}
