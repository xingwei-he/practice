/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:175_Invert_Binary_Tree.cc
 * Author:
 * Mail:
 * Created Time:星期二  1/ 2 14:56:26 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Invert a binary tree.
 *
 * Example
 *   1         1
 *  / \       / \
 * 2   3  => 3   2
 *    /       \
 *   4         4
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
   * @param root: a TreeNode, the root of the binary tree
   * @return: nothing
   */
  void invertBinaryTree(TreeNode * root) {
    if (nullptr == root) {
      return;
    }
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertBinaryTree(root->left);
    invertBinaryTree(root->right);
  }
};

int main() {
  return 0;
}
