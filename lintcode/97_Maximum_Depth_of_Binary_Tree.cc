/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:97_Maximum_Depth_of_Binary_Tree.cc
 * Author:
 * Mail:
 * Created Time:2018年01月01日 星期一 14时28分28秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 *
 * Example
 *
 * Given a binary tree as follow:
 *
 *     1
 *    / \
 *   2   3
 *      / \
 *     4   5
 *
 * The maximum depth is 3.
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
  /**
   * @param root: The root of binary tree.
   * @return: An integer
   */
  int maxDepth(TreeNode *root) {
    if (nullptr == root) {
      return 0;
    }
    if (nullptr == root->left && nullptr == root->right) {
      return 1;
    }
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);
    return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
  }
};

int main() {
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);
  root->right->right = new TreeNode(4);
  root->right->right->right = new TreeNode(5);
  root->left = new TreeNode(6);
  root->left->left = new TreeNode(7);
  Solution sl;
  int max_depth = sl.maxDepth(root);
  cout << "max_depth:" << max_depth << endl;
  return 0;
}

