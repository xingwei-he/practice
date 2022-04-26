#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
    	vector<int> res;
    	if (nullptr == root) {
    		return res;
    	}
    	queue<TreeNode *> node_queue;
    	TreeNode *p;
    	node_queue.push(root);
    	while (!node_queue.empty()) {
    		p = node_queue.front();
    		res.emplace_back(p->val);
    		node_queue.pop();
    		if (nullptr != p->left) {
    			node_queue.push(p->left);
    		}
    		if (nullptr != p->right) {
    			node_queue.push(p->right);
    		}
    	}
    	return res;
    }
};