/**************************************
* He Xingwei, All Rights Reserved.
* Filename:226.cpp
* Date:2022-04-23 18:53:55
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (nullptr == root) {
            return root;
        }
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};