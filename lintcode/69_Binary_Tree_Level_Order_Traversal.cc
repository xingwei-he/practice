/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:69_Binary_Tree_Level_Order_Traversal.cc
 * Author:
 * Mail:
 * Created Time:2017年12月30日 星期六 20时13分10秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 *
 * Example
 * Given binary tree {3,9,20,#,#,15,7},
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *    	   
 * return its level order traversal as:
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
 */

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
   * @param root: A Tree
   * @return: Level order a list of lists of integer
   */
  vector<vector<int> > levelOrder(TreeNode * root) {
    vector<vector<int> > res;
    if (nullptr == root) {
      return res;
    }
    queue<TreeNode*> q;
    TreeNode* ptr = root;
    q.push(ptr);
    while (!q.empty()) {
      vector<int> cur_level;
      int counter = q.size();// 记录下当时队列的 size 即为本层的节点数
      for (int i = 0; i < counter; i++) {
	ptr = q.front();
	q.pop();
	cur_level.push_back(ptr->val);
	if (nullptr != ptr->left) {
	  q.push(ptr->left);
	}
	if (nullptr != ptr->right) {
	  q.push(ptr->right);
	}
      }
      res.push_back(cur_level);
    }
    return res;
  }
};



int main() {
  return 0;
}

