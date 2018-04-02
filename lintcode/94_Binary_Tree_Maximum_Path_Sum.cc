/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:94_Binary_Tree_Maximum_Path_Sum.cc
 * Author:
 * Mail:
 * Created Time:2018年04月01日 星期日 18时34分44秒
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given a binary tree, find the maximum path sum.
 * The path may start and end at any node in the tree.
 *
 * Example
 *   Given the below binary tree:
 *     1
 *    / \
 *   2   3
 *   return 6.
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
  int maxPathSum(TreeNode *root) {
    int max_sum = INT_MIN;
    getMaxPathSum(root, max_sum);
    return max_sum;
  }
  
  int getMaxPathSum(TreeNode * root, int &cur_max) {
    if (nullptr == root) {
      return 0;
    }
    int left_max = 0, right_max = 0;
    left_max = getMaxPathSum(root->left, cur_max);
    right_max = getMaxPathSum(root->right, cur_max);
    int left_temp = 0 > left_max ? 0 : left_max;
    int right_temp = 0 > right_max ? 0 : right_max;
    int temp = left_temp + right_temp + root->val;
    cur_max = cur_max > temp ? cur_max : temp;
    return max(0, max(left_max, right_max)) + root->val;
  }
};

int main() {
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(-3);
  root->right->right = new TreeNode(4);
  root->right->right->right = new TreeNode(5);
  root->left = new TreeNode(6);
  root->left->left = new TreeNode(-7);
  Solution sl;
  int res = sl.maxPathSum(root);
  cout << res << endl;
  return 0;
}
