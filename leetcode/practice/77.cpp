/**************************************
* He Xingwei, All Rights Reserved.
* Filename:77.cpp
* Date:2022-04-19 15:37:20
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
	/*
	 * 递归获取组合
	 * n: 取值范围，k: 个数，start: 起始数字，counter: 记录组合长度（与目标k比较）
	 * res: 结果，combination: 暂存当前结果
	 */
	void get_combination(int n, int k, int start, int counter,
			vector<vector<int>>& res, vector<int>& combination) {
		if (counter == k) {
			res.emplace_back(combination);
			return;
		}
		for (int i = start; i <= n; i++) {
			combination[counter] = i;
			counter++; // 依靠counter来实现回溯
			get_combination(n, k, i + 1, counter, res, combination);
			counter--;
		}
	}

    vector<vector<int>> combine(int n, int k) {
    	vector<vector<int>> res;
    	vector<int> combination(k, 0);
    	int counter = 0;
    	get_combination(n, k, 1, counter, res, combination);
    }
};