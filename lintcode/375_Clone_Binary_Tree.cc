/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:375_Clone_Binary_Tree.cc
 * Author:
 * Mail:
 * Created Time:星期三  1/ 3 17:35:59 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * For the given binary tree, return a deep copy of it.
 *
 * Example
 * Given a binary tree:
 *
 *     1
 *    / \
 *   2   3
 *  / \
 * 4   5
 *
 * return the new binary tree with same structure and same value:
 *
 *     1
 *    / \
 *   2   3
 *  / \
 * 4   5
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
   * @param root: The root of binary tree
   * @return: root of new tree
   */
  TreeNode * cloneTree(TreeNode * root) {
    if (nullptr == root) {
      return root;
    }
    TreeNode* r = new TreeNode(root->val);
    if (nullptr != root->left) {
      r->left = cloneTree(root->left);
    }
    if (nullptr != root->right) {
      r->right = cloneTree(root->right);
    }
    return r;
  }
};

int main() {
  return 0;
}
