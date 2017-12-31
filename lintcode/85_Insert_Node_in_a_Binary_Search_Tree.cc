/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:85_Insert_Node_in_a_Binary_Search_Tree.cc
 * Author:
 * Mail:
 * Created Time:2017年12月31日 星期日 13时28分41秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a binary search tree and a new tree node, insert the node into the tree. You should keep the tree still be a valid binary search tree.
 *
 * Notice
 * You can assume there is no duplicate values in this tree + node.

 * Example
 * Given binary search tree as follow, after Insert node 6, the tree should be:
 *
 *     2             2
 *    / \           / \
 *   1   4   -->   1   4
 *      /             / \
 *     3             3   6
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
   * @param root: The root of the binary search tree.
   * @param node: insert this node into the binary search tree
   * @return: The root of the new binary search tree.
   */
  TreeNode * insertNode(TreeNode * root, TreeNode * node) {
    if (nullptr == node) {
      return root;
    }
    if (nullptr == root) {
      return node;
    }
    TreeNode* cur = root;
    TreeNode* pre = nullptr;
    while (nullptr != cur) {
      pre = cur;
      if (node->val > cur->val) {
	cur = cur->right;
      } else if (node->val < cur->val) {
	cur = cur->left;
      } else {
	return root;
      }
    }
    if (nullptr == cur) {
      if (node->val > pre->val) {
	pre->right = node;
      } else if (node->val < pre->val){
	pre->left = node;
      }
    }
    return root;
  }
};

int main() {
  return 0;
}
