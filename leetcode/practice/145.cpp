/**************************************
* He Xingwei, All Rights Reserved.
* Filename:145.cpp
* Date:2022-04-22 12:08:50
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    // 递归
	void postorderTraversalRecursiveCore(TreeNode *root, vector<int> &seq) {
		if (nullptr != root) {
			postorderTraversalRecursiveCore(root->left, seq);
			postorderTraversalRecursiveCore(root->right, seq);
            seq.emplace_back(root->val);
		}
	}
    // 非递归
    void postorderTraversalCore(TreeNode *root, vector<int> &seq) {
        if (nullptr == root) {
            return;
        }
        stack<TreeNode *> node_stack;
        TreeNode *p = root;
        TreeNode *pre = nullptr; // 指向刚才访问过的节点
        node_stack.push(root); // 初始状态，把根节点入栈
        while (!node_stack.empty()) {
            p = node_stack.top();
            // 当前节点是叶子节点或刚才访问过该节点的子节点
            // 如果有两个子节点或只有一个右子节点，则 pre 指向右子节点，如果只有左子节点，则 pre 指向左子节点
            if ((nullptr == p->left && nullptr == p->right) ||
                    (nullptr != pre && (pre == p->left || pre == p->right))) {
                seq.emplace_back(p->val);
                node_stack.pop();
                pre = p;
            } else {
                if (nullptr != p->right) { // 先把右子节点入栈，再把左子节点入栈，因为要先访问左子树
                    node_stack.push(p->right);
                }
                if (nullptr != p->left) {
                    node_stack.push(p->left);
                }
            }
        }
    }

    vector<int> postorderTraversal(TreeNode* root) {
    	vector<int> postorder_seq;
    	if (nullptr == root) {
    		return postorder_seq;
    	}
    	//postorderTraversalRecursiveCore(root, postorder_seq);
        postorderTraversalCore(root, postorder_seq);
    	return postorder_seq;
    }
};