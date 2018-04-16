/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:155_Minimum_Depth_of_Binary_Tree.cc
 * Author:
 * Mail:
 * Created Time:星期四 12/28 16:46:48 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 *
 * Example
 * Given a binary tree as follow:
 *     1
 *    / \
 *   2   3
 *      / \
 *     4   5
 * The minimum depth is 2.
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
   * @return: An integer
   */
  int minDepth(TreeNode * root) {
    if (nullptr == root) {
      return 0;
    }
    int min_left = 0;
    int min_right = 0;
    if (nullptr == root->left && nullptr == root->right) {
      return 1;
    } else if (nullptr != root->left && nullptr != root->right) {
      min_left = minDepth(root->left);
      min_right = minDepth(root->right);
      return min_left < min_right ? min_left + 1 : min_right + 1;
    } else if (nullptr != root->left && nullptr == root->right) {
      min_left = minDepth(root->left);
      return min_left + 1;
    } else {
      min_right = minDepth(root->right);
      return min_right + 1;
    }
  }
};

int main() {
  /*
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  */
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);
  Solution sl;
  int min_depth = sl.minDepth(root);
  cout << "min_depth:" << min_depth << endl;
  return 0;
}
