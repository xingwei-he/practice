#include <iostream>

using namespace std;

class Solution {
public:
    // 获取二叉树中节点最远距离
    // left_depth 和 right_depth 记录两棵子树深度
    int getMaxDistance(TreeNode *root, int &left_depth, int &right_depth) {
        if (nullptr == root) {
            left_depth = 0;
            right_depth = 0;
            return 0;
        }
        int maxLL, maxLR, maxRL, maxRR; // 记录子树的子树深度，如 maxLL 表示左子树的左子树深度
        int left_max_distance, right_max_distance;
        if (nullptr != root->left) {
            left_max_distance = getMaxDistance(root->left, maxLL, maxLR);
            left_depth = max(maxLL, maxLR) + 1;
        } else {
            left_max_distance = 0;
            left_depth = 0;
        }
        if (nullptr != root->right) {
            right_max_distance = getMaxDistance(root->right, maxRL, maxRR);
            right_depth = max(maxRL, maxRR) + 1;
        } else {
            right_max_distance = 0;
            right_depth = 0;
        }
        // 最大距离有三种，1跨根节点，2左子树的最大距离，3右子树的最大距离
        return max(max(left_max_distance, right_max_distance), left_depth + right_depth);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int left_depth = 0, right_depth = 0;
        return getMaxDistance(root, left_depth, right_depth);
    }
};