/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:245_Subtree.cc
 * Author:
 * Mail:
 * Created Time:2018年01月02日 星期二 22时39分07秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * You have two very large binary trees: T1, with millions of nodes, and T2, with hundreds of nodes. Create an algorithm to decide if T2 is a subtree of T1.
 *
 * Notice
 *   A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of n is identical to T2. That is, if you cut off the tree at node n, the two trees would be identical.
 *
 * Example
 * T2 is a subtree of T1 in the following case:
 *
 *        1                3
 *       / \              / 
 * T1 = 2   3      T2 =  4
 *         /
 *        4
 *
 * T2 isn't a subtree of T1 in the following case:
 *
 *        1               3
 *       / \               \
 * T1 = 2   3       T2 =    4
 *         /
 *        4
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
   * @param T1: The roots of binary tree T1.
   * @param T2: The roots of binary tree T2.
   * @return: True if T2 is a subtree of T1, or false.
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

  bool isSubtree(TreeNode * T1, TreeNode * T2) {
    if (nullptr == T2) {
      return true;
    } else if (nullptr == T1) {
      return false;
    }
    if (isSameTree(T1, T2)) {
      return true;
    } else {
      return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
    }
  }
};

int main() {
  TreeNode* t1 = new TreeNode(1);
  t1->left = new TreeNode(2);
  t1->right = new TreeNode(4);
  t1->left->right = new TreeNode(3);
  TreeNode* t2 = new TreeNode(2);
  t2->right = new TreeNode(3);

  Solution sl;
  bool is_same_tree = sl.isSameTree(t1, t2);
  cout << "isSameTree:" << boolalpha << is_same_tree << endl;
  bool is_sub_tree = sl.isSubtree(t1, t2);
  cout << "isSubtree:" << boolalpha << is_sub_tree << endl;
  return 0;
}
