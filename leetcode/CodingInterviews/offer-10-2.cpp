/**************************************
* He Xingwei, All Rights Reserved.
* Filename:offer-10-2.cpp
* Date:2022-04-27 13:58:04
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
	static constexpr int MOD = 1000000007;
    int numWays(int n) {
    	if (0 == n || 1 == n) {
    		return 1;
    	}
    	int x1 = 1, x2 = 1; // 初始化状态f(0)和f(1)
		int res = 0;
    	for (int i = 2; i <= n; i++) {
    		res = (x1 + x2) % MOD;
    		x1 = x2;
    		x2 = res;
    	}
    	return res;
    }
};

int main() {
	Solution s;
	int res = s.numWays(2);
	cout << res << endl;
	return 0;
}