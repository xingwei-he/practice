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
        int level = 0;
        int counter = 0;
        TreeNode *p = nullptr;
        node_queue.push(root);
        while (!node_queue.empty()) {
            counter = node_queue.size();
            level += 1;
            vector<int> cur_level;
            stack<TreeNode *> cur_stack;
            for (int i = 0; i < counter; i++) {
                p = node_queue.front();
                node_queue.pop();
                if (level % 2 == 0) {
                    cur_stack.push(p);
                } else {
                    cur_level.emplace_back(p->val);
                }
                if (nullptr != p->left) {
                    node_queue.push(p->left);
                }
                if (nullptr != p->right) {
                    node_queue.push(p->right);
                }
            }
            if (level % 2 == 0) {
                while (!cur_stack.empty()) {
                    cur_level.emplace_back(cur_stack.top()->val);
                    cur_stack.pop();
                }
            }
            res.emplace_back(cur_level);
        }
        return res;
    }
};