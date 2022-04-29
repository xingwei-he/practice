/**************************************
* He Xingwei, All Rights Reserved.
* Filename:94.cpp
* Date:2022-04-22 11:45:53
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    // 递归
    void inorderTraversalRecursiveCore(TreeNode *root, vector<int> &seq) {
        if (nullptr != root) {
            inorderTraversalRecursiveCore(root->left, seq);
            seq.emplace_back(root->val);
            inorderTraversalRecursiveCore(root->right, seq);
        }
    }
    // 非递归
    void inorderTraversalCore(TreeNode *root, vector<int> &seq) {
        if (nullptr == root) {
            return;
        }
        stack<TreeNode *> node_stack;
        TreeNode *p = root;
        while (!node_stack.empty() || nullptr != p) {
            while (nullptr != p) {
                node_stack.push(p);
                p = p->left;
            }
            if (!node_stack.empty()) {
                p = node_stack.top();
                node_stack.pop();
                // visit
                seq.emplace_back(p->val);
                p = p->right;
            }
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder_seq;
        if (nullptr == root) {
            return inorder_seq;
        }
        //inorderTraversalRecursiveCore(root, inorder_seq);
        inorderTraversalCore(root, inorder_seq);
        return inorder_seq;
    }
};