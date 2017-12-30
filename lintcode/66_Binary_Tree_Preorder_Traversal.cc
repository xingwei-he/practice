/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:66_Binary_Tree_Preorder_Traversal.cc
 * Author:
 * Mail:
 * Created Time:2017年12月30日 星期六 16时32分36秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a binary tree, return the preorder traversal of its nodes' values.
 *
 * Example
 * Given:
 *
 *       1
 *      / \
 *     2   3
 *    / \
 *   4   5
 *
 * return [1,2,4,5,3].
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
   * @return: Preorder in ArrayList which contains node values.
   */
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if (nullptr == root) {
      return res;
    }
    TreeNode* p = root;
    stack<TreeNode*> st;
    while (!st.empty() || nullptr != p) {
      while (nullptr != p) {
	res.push_back(p->val);
	st.push(p);
	p = p->left;
      }
      if (!st.empty()) {
	p = st.top();
	st.pop();
	p = p->right;
      }
    }
    return res;
  }
};

int main() {
  return 0;
}
