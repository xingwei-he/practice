/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:469_Identical_Binary_Tree.cc
 * Author:
 * Mail:
 * Created Time:星期五  1/ 5 15:16:31 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Check if two binary trees are identical. Identical means the two binary trees have the same structure and every identical position has the same value.
 *
 * Example
 *     1             1
 *    / \           / \
 *   2   2   and   2   2
 *  /             /
 * 4             4
 * are identical.
 *
 *     1             1
 *    / \           / \
 *   2   3   and   2   3
 *  /               \
 * 4                 4
 * are not identical.
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
   * @param a: the root of binary tree a.
   * @param b: the root of binary tree b.
   * @return: true if they are identical, or false.
   */
  bool isSameTree(TreeNode* t1, TreeNode* t2) {
    if (t1 == t2) {
      return true;
    } else if (nullptr == t1 || nullptr == t2) {
      return false;
    }
    if (t1->val != t2->val) {
      return false;
    } else {
      return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
    }
  }

  bool isIdentical(TreeNode * a, TreeNode * b) {
    if (isSameTree(a, b)) {
      return true;
    }
    return false;
  }
};

int main() {
  return 0;
}
