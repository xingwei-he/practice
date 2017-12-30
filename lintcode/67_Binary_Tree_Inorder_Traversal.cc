/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:67_Binary_Tree_Inorder_Traversal.cc
 * Author:
 * Mail:
 * Created Time:2017年12月30日 星期六 17时07分25秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * Example
 * Given binary tree {1,#,2,3},
 *
 *       1
 *        \
 *         2
 *        /
 *       3
 *       	      
 * return [1,3,2].
 **/

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
   * @return: Inorder in ArrayList which contains node values.
   */
  vector<int> inorderTraversal(TreeNode * root) {
    vector<int> res;
    if (nullptr == root) {
      return res;
    }
    TreeNode* p = root;
    stack<TreeNode*> st;
    while (!st.empty() || nullptr != p) {
      while (nullptr != p) {
	st.push(p);
	p = p->left;
      }
      if (!st.empty()) {
	p = st.top();
	st.pop();
	res.push_back(p->val);
	p = p->right;
      }
    }
    return res;
  }
};

int main() {
  return 0;
}


