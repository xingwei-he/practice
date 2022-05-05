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
    void dfs(vector<int> &candidates, int target,
            vector<vector<int>> &res, vector<int> &cur_res,
            int i) {
        if (i == candidates.size()) { // 越界则返回，i 指向当前要操作的数据
            return;
        }
        if (target == 0) { // 达到目标值则当前结果ok
            res.emplace_back(cur_res);
            return;
        }
        // 对于当前第i个元素，选 or 不选？
        dfs(candidates, target, res, cur_res, i + 1); // 不选
        if (target - candidates[i] >= 0) { // 选
            cur_res.emplace_back(candidates[i]);
            dfs(candidates, target - candidates[i], res, cur_res, i); // 由于可以重复选，则索引值可以继续用 i
            cur_res.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur_res; // 当前结果，即此时的组合
        dfs(candidates, target, res, cur_res, 0);
        return res;
    }
};