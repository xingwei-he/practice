#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    	vector<vector<int>> res;
    	if (nullptr == root) {
    		return res;
    	}
    	queue<TreeNode *> node_queue;
    	int counter = 0;
    	TreeNode *p = nullptr;
    	node_queue.push(root);
    	while (!node_queue.empty()) {
    		counter = node_queue.size();
    		vector<int> cur_level;
    		cur_level.reserve(counter);
    		for (int i = 0; i < counter; i++) {
    			p = node_queue.front();
    			node_queue.pop();
    			cur_level.emplace_back(p->val);
                if (nullptr != p->left) {
                    node_queue.push(p->left);
                }
                if (nullptr != p->right) {
                    node_queue.push(p->right);
                }
    		}
    		res.emplace_back(cur_level);
    	}
    	return res;
    }
};