/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:480_Binary_Tree_Paths.cc
 * Author:
 * Mail:
 * Created Time:星期五  1/ 5 15:27:21 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Example
 * Given the following binary tree:
 * 
 *       1
 *     /   \
 *    2     3
 *     \
 *      5
 * All root-to-leaf paths are:
 * 
 * [
 *   "1->2->5",
 *   "1->3"
 * ]
 * 
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
   * @param root: the root of the binary tree
   * @return: all root-to-leaf paths
   */
  void dfs(TreeNode* root, string out, vector<string>& res) {
    out += to_string(root->val);
    if (nullptr == root->left && nullptr == root->right) {
      res.push_back(out);
    } else {
      if (nullptr != root->left) {
	dfs(root->left, out + "->", res);
      }
      if (nullptr != root->right) {
	dfs(root->right, out + "->", res);
      }
    }
  }

  vector<string> binaryTreePaths(TreeNode * root) {
    vector<string> res;
    if (nullptr != root) {
      dfs(root, "", res);
    }
    return res;
  }
};

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(4);
  Solution sl;
  vector<string> vec = sl.binaryTreePaths(root);
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << endl;
  }
  return 0;
}
