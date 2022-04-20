/**************************************
* He Xingwei, All Rights Reserved.
* Filename:22.cpp
* Date:2022-04-20 10:53:46
* Description:
**************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	/*
	 * 递归获取括号对
	 */
	void get_parenthesis(int n, int& lc, int& rc, vector<string>& res, string& parenthesis) {
		if (lc == n && rc == n) {
			res.emplace_back(parenthesis);
            return;
		}
		// 拼接左括号
		if (lc < n) {
            lc++;
            parenthesis.push_back('(');
			get_parenthesis(n, lc, rc, res, parenthesis);
            // 回溯 lc 和 parenthesis
            lc--;
            parenthesis.pop_back();
		}
		// 拼接右括号
		if (rc < n && rc < lc) {
            rc++;
            parenthesis.push_back(')');
			get_parenthesis(n, lc, rc, res, parenthesis);
            // 回溯 rc 和 parenthesis
            rc--;
            parenthesis.pop_back();
		}
	}

    vector<string> generateParenthesis(int n) {
    	vector<string> res;
    	if (n <= 0) {
    		return res;
    	}
    	string parenthesis;
    	int lc = 0, rc = 0; // 括号计数器，left_counter & right_counter
    	get_parenthesis(n, lc, rc, res, parenthesis);
        return res;
    }
};

int main() {
    Solution s;
    auto v = s.generateParenthesis(3);
    for (auto i: v) {
        cout << i << endl;
    }
    return 0;
}
