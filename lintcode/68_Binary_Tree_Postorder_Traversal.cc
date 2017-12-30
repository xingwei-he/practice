/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:68_Binary_Tree_Postorder_Traversal.cc
 * Author:
 * Mail:
 * Created Time:2017年12月30日 星期六 17时24分06秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a binary tree, return the postorder traversal of its nodes' values.
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
 * return [3,2,1].
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
   * @return: Postorder in ArrayList which contains node values.
   */
  vector<int> postorderTraversal(TreeNode * root) {
    vector<int> res;
    if (nullptr == root) {
      return res;
    }
    stack<TreeNode*> st;
    TreeNode* pre = nullptr;
    TreeNode* cur = root;
    st.push(cur);
    while (!st.empty()) {
      cur = st.top();
      if ((nullptr == cur->left && nullptr == cur->right) || 
	  (nullptr != pre && (pre == cur->left || pre == cur->right))) {
	res.push_back(cur->val);
	pre = cur;
	st.pop();
      } else {
	if (nullptr != cur->right) {
	  st.push(cur->right);
	}
	if (nullptr != cur->left) {
	  st.push(cur->left);
	}
      }
    }
    return res;
  }
};

int main() {
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);
  Solution sl;
  vector<int> res = sl.postorderTraversal(root);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << "  ";
  }
  cout << endl;
  return 0;
}


