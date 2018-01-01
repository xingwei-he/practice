/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:93_Balanced_Binary_Tree.cc
 * Author:
 * Mail:
 * Created Time:2017年12月31日 星期日 14时01分30秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 * Example
 *
 * Given binary tree A = {3,9,20,#,#,15,7}, B = {3,#,20,15,7}
 * A)  3            B)    3 
 *    / \                  \
 *   9  20                 20
 *     /  \                / \
 *    15   7              15  7
 *
 * The binary tree A is a height-balanced binary tree, but B is not.
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
   * @param root: The root of binary tree.
   * @return: True if this Binary tree is Balanced, or false.
   */
  int getBinaryTreeDepth(TreeNode* root) {
    if (nullptr == root) {
      return 0;
    }
    int left_depth = 0;
    int right_depth = 0;
    if (nullptr == root->left && nullptr == root->right) {
      return 1;
    } else {
      left_depth = getBinaryTreeDepth(root->left);
      right_depth = getBinaryTreeDepth(root->right);
      return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
    }
  }

  bool isBalanced(TreeNode * root) {
    if (nullptr == root) {
      return true;
    }
    bool res = false;
    int left_depth = getBinaryTreeDepth(root->left);
    int right_depth = getBinaryTreeDepth(root->right);
    if (abs(left_depth - right_depth) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
      res = true;
    }
    return res;
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
  int depth = sl.getBinaryTreeDepth(root);
  bool res = sl.isBalanced(root);
  cout << "depth:" << depth << endl;
  cout << "isBalanced:" << boolalpha << res << endl;
  return 0;
}
