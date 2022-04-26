/**************************************
* He Xingwei, All Rights Reserved.
* Filename:offer-54.cpp
* Date:2022-04-26 23:34:52
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int kthLargest(TreeNode* root, int k) { // 中序遍历，注意，先从右子树开始
        TreeNode *p = root;
        stack<TreeNode *> node_stack;
        while (!node_stack.empty() || nullptr != p) {
            while (nullptr != p) {
                node_stack.push(p);
                p = p->right;
            }
            if (!node_stack.empty()) {
                p = node_stack.top();
                k--; // visit
                if (0 == k) {
                    return p->val;
                }
                node_stack.pop();
                p = p->left;
            }
        }
        return -1;
    }
};