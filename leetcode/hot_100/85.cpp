/**************************************
* He Xingwei, All Rights Reserved.
* Filename:85.cpp
* Date:2022-05-02 16:35:53
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    // 借助 84 的方法
    int largestRectangleArea(vector<int> &heights) {
        if (heights.empty()) {
            return 0;
        }
        vector<int> inc_stack; // 记录索引值，高度递增
        // 注意此处注释掉代码，因为要逐行进行计算，所以在调用出提前把边界加上
        //heights.insert(heights.begin(), 0);
        //heights.emplace_back(0);
        int max_area = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!inc_stack.empty() && heights[i] < heights[inc_stack.back()]) {
                int cur = inc_stack.back();
                inc_stack.pop_back();
                int left = inc_stack.back() + 1;
                int right = i - 1;
                max_area = max(max_area, (right - left + 1) * heights[cur]);
            }
            inc_stack.emplace_back(i);
        }
        return max_area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int max_area = 0;
        vector<int> heights(n + 2, 0); // +2 是在首位加了两个 0 作为边界
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    heights[j + 1] += 1;
                } else {
                    heights[j + 1] = 0;
                }
            }
            int area = largestRectangleArea(heights);
            max_area = max(max_area, area);
        }
        return max_area;
    }
};