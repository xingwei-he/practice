/**************************************
* He Xingwei, All Rights Reserved.
* Filename:39.cpp
* Date:2022-05-05 11:24:03
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    void dfs(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &cur_res, int i) {
        if (i == candidates.size()) {
            return;
        }
        if (target == 0) {
            res.emplace_back(cur_res);
            return;
        }
        dfs(candidates, target, res, cur_res, i + 1);
        if (target - candidates[i] >= 0) {
            cur_res.emplace_back(candidates[i]);
            dfs(candidates, target - candidates[i),res, cur_res, i);
            cur_res.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur_res;
        dfs(candidates, target, res, cur_res, 0);
        return res;
    }
};