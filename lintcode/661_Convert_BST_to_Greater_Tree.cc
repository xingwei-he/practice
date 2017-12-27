/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:661_Convert_BST_to_Greater_Tree.cc
 * Author:
 * Mail:
 * Created Time:星期三 12/27 11:23:51 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.
 *
 * Example
 * Given a binary search Tree `{5,2,13}｀:
 *       5
 *     /   \
 *    2     13
 * Return the root of new tree
 *      18
 *     /   \
 *   20     13
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
   * @param root: the root of binary tree
   * @return: the new root
   */
  // 中根遍历 用于测试
  void inorderTraversal(TreeNode* root) {
    if (nullptr != root) {
      inorderTraversal(root->left);
      cout << "* " << root->val << endl;
      inorderTraversal(root->right);
    }
  }

  //
  void invertedInorderConvert(TreeNode* root, int& sum) {
    if (nullptr != root) {
      invertedInorderConvert(root->right, sum);
      root->val += sum;
      sum = root->val;
      invertedInorderConvert(root->left, sum);
    }
  }

  TreeNode * convertBST(TreeNode * root) {
    int sum = 0;
    invertedInorderConvert(root, sum);
    return root;
  }
};

int main() {
  TreeNode* root = new TreeNode(8);
  root->left = new TreeNode(5);
  root->right = new TreeNode(12);
  Solution sl;
  sl.inorderTraversal(root);
  cout << "********" << endl;
  sl.convertBST(root);
  cout << "********" << endl;
  sl.inorderTraversal(root);
  
  return 0;
}

