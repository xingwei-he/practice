/**************************************
* He Xingwei, All Rights Reserved.
* Filename:offer-55-2.cpp
* Date:2022-04-26 22:36:29
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int getDepth(TreeNode *root) {
        if (nullptr == root) {
            return 0;
        }
        if (nullptr == root->left && nullptr == root->right) {
            return 1;
        }
        int left_depth = getDepth(root->left);
        int right_depth = getDepth(root->right);
        return max(left_depth, right_depth) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (nullptr == root) {
            return true;
        }
        int left_depth = getDepth(root->left);
        int right_depth = getDepth(root->right);
        cout << left_depth << "\t" << right_depth << endl;
        if (abs(left_depth - right_depth) > 1) {
            return false;
        } else {
            return isBalanced(root->left) && isBalanced(root->right);
        }
    }
};