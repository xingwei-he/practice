/**************************************
* He Xingwei, All Rights Reserved.
* Filename:239.cpp
* Date:2022-05-03 23:40:01
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> q; // 优先队列，存放<值，索引>对
        for (int i = 0; i < k; i++) { // 前k个数值入队
            q.emplace(nums[i], i);
        }
        vector<int> res{q.top().first};
        for (int i = k; i < n; i++) {
            q.emplace(nums[i], i);
            while (q.top().second <= i - k) {
                q.pop();
            }
            res.emplace_back(q.top().first);
        }
        return res;
    }
};