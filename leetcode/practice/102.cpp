/**************************************
* He Xingwei, All Rights Reserved.
* Filename:102.cpp
* Date:2022-04-22 16:57:27
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    	vector<vector<int>> level_seq;
    	if (nullptr == root) {
    		return level_seq;
    	}
        queue<TreeNode *> node_queue;
        TreeNode *p = nullptr;
        node_queue.push(root);
        while (!node_queue.empty()) {
        	int cur_size = node_queue.size();
        	level_seq.emplace_back(vector<int>());
        	level_seq.back().reserve(cur_size);
        	for (int i = 0; i < cur_size; i++) {
        		p = node_queue.front();
        		node_queue.pop();
        		level_seq.back().emplace_back(p->val);
        		if (nullptr != p->left) {
        			node_queue.push(p->left);
        		}
        		if (nullptr != p->right) {
        			node_queue.push(p->right);
        		}
        	}
        }
        return level_seq;
    }
};