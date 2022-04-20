/**************************************
* He Xingwei, All Rights Reserved.
* Filename:17.cpp
* Date:2022-04-19 12:52:23
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
	void get_combinations(vector<string>& combinations,
			string combination,
			string digits, int pos,
			unordered_map<char, string>& phone) {
		if (pos == digits.size()) { // 越界，表示完成
			combinations.emplace_back(combination);
			return;
		}
		char c = digits[pos];
		const string& letters = phone[c];
		for (const char&  letter : letters) {
			combination.push_back(letter);
			get_combinations(combinations, combination, digits, pos + 1, phone);
			combination.pop_back();
		}
	}

    vector<string> letterCombinations(string digits) {
    	vector<string> combinations;
    	if (digits.empty()) {
    		return combinations;
    	}
    	unordered_map<char, string> phone{
    		{'2', "abc"}, {'3', "def"},
    		{'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
    		{'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    	};
    	string combination; // 暂存组合结果
    	get_combinations(combinations, combination, digits, 0, phone);
    	return combinations;
    }
};