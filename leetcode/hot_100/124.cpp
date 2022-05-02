/**************************************
* He Xingwei, All Rights Reserved.
* Filename:124.cpp
* Date:2022-05-02 18:34:05
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    // 获取子树的贡献
    // 返回值即为该树贡献值，同时更新 max_sum 最大路径和
    int getContribution(TreeNode *root, int &max_sum) {
        if (nullptr == root) {
            // 如果该节点为空，则贡献值为0，不更新 max_sum
            return 0;
        }
        if (nullptr == root->left && nullptr == root->right) {
            // 如果是叶子节点，则贡献值即为节点 val，max_sum 更新
            max_sum = max(max_sum, root->val);
            return root->val;
        }
        // 计算左右子树的最大路径和，取大于0的
        int left_contribution = getContribution(root->left, max_sum);
        left_contribution = max(left_contribution, 0);
        int right_contribution = getContribution(root->right, max_sum);
        right_contribution = max(right_contribution, 0);
    
        // 节点的最大路径和取决于该节点的值与左右子节点的最大贡献
        max_sum = max(max_sum, root->val + left_contribution + right_contribution);
        return root->val  + max(left_contribution, right_contribution);
    }

    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        getContribution(root, max_sum);
        return max_sum;
    }
};