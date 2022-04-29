/**************************************
* He Xingwei, All Rights Reserved.
* Filename:144.cpp
* Date:2022-04-22 11:56:12
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    // 递归
    void preorderTraversalRecursiveCore(TreeNode *root, vector<int> &seq) {
        if (nullptr != root) {
            seq.emplace_back(root->val);
            preorderTraversalRecursiveCore(root->left, seq);
            preorderTraversalRecursiveCore(root->right, seq);
        }
    }
    // 非递归
    void preorderTraversalCore(TreeNode *root, vector<int> &seq) {
        if (nullptr == root) {
            return;
        }
        stack<TreeNode *> node_stack;
        TreeNode *p = root;
        while (!node_stack.empty() || nullptr != p) {
            while (nullptr != p) {
                // visit
                seq.emplace_back(p->val);
                node_stack.push(p);
                p = p->left;
            }
            if (!node_stack.empty()) {
                p = node_stack.top();
                node_stack.pop();
                p = p->right;
            }
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder_seq;
        if (nullptr == root) {
            return preorder_seq;
        }
        //preorderTraversalRecursiveCore(root, preorder_seq);
        preorderTraversalCore(root, preorder_seq);
        return preorder_seq;
    }
};