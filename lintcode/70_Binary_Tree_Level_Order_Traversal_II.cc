#include "practice/include/base.h"

using namespace std;

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
  /*
   * @param root: A tree
   * @return: buttom-up level order a list of lists of integer
   */
  vector<vector<int> > levelOrderBottom(TreeNode * root) {
    vector<vector<int> > res;
    if (nullptr == root) {
      return res;
    }

    TreeNode* ptr = root;
    queue<TreeNode*> node_queue;
    node_queue.push(ptr);
    stack<vector<int> > level_stack;
    while (!node_queue.empty()) {
      vector<int> temp_vec;
      int queue_size = node_queue.size();// 当前队列中的节点便是一层的节点
      for (int i = 0; i < queue_size; i++) {
	// 每次循环结束都完成一层的遍历
	ptr = node_queue.front();
	node_queue.pop();
	if (nullptr != ptr->left) {
	  node_queue.push(ptr->left);
	}
	if (nullptr != ptr->right) {
	  node_queue.push(ptr->right);
	}
	temp_vec.push_back(ptr->val);
      }
      level_stack.push(temp_vec);
    }

    while (!level_stack.empty()) {
      res.push_back(level_stack.top());
      level_stack.pop();
    }
    return res;
  }
};

int main() {

  return 0;
}
