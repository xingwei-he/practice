/**************************************
* He Xingwei, All Rights Reserved.
* Filename:84.cpp
* Date:2022-05-02 12:51:38
* Description:
**************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        }
        int max_area = 0;
        vector<int> inc_stack; // 递增栈
        // 设置左右两端的边界
        heights.insert(heights.begin(), 0);
        heights.emplace_back(0);
        for (int i = 0; i < heights.size(); i++) {
            while (!inc_stack.empty() && heights[inc_stack.back()] > heights[i]) {
                int cur = inc_stack.back();
                inc_stack.pop_back();
                int left = inc_stack.back() + 1;
                int right = i - 1;
                max_area = max(max_area, (right - left + 1) * (heights[cur]));
                cout << "max_area:" << max_area << endl;
            }
            inc_stack.emplace_back(i);
        }
        return max_area;
    }
};

int main() {
    vector<int> heights{2,1,5,6,2,3};
    Solution s;
    int area = s.largestRectangleArea(heights);
    cout << area << endl;
    return 0;
}