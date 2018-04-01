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
  int getMaxPathSum(TreeNode* root, int& current_path_sum) {
    if (nullptr == root) {
      return current_path_sum;
    }
    int left_max_path_sum = getMaxPathSum(root->left, current_path_sum + root->val);
    int right_max_path_sum = getMaxPathSum(root->right, current_path_sum + root->val);
  }

  int getMaxPathSum(TreeNode* root, int& left_max_sum, int& right_max_sum) {
    if (nullptr == root) {
      left_max_sum = INT_MIN;
      right_max_sum = INT_MIN;
      return 0;
    }
    int maxLL, maxLR, maxRL, maxRR;
    int maxL, maxR;
    if (nullptr != root->left) {
      maxL = getMaxPathSum(root->left, maxLL, maxLR);
      left_max_sum = max(maxLL, maxLR) + root->left->val;
    } else {
      maxL = INT_MIN;
      left_max_sum = INT_MIN;
    }
    if (nullptr != root->right) {
      maxR = getMaxPathSum(root->right, maxRL, maxRR);
      right_max_sum = max(maxRL, maxRR) + root->right->val;
    } else {
      maxR = INT_MIN;
      right_max_sum = INT_MIN;
    }
    return max(max(maxL, maxR), left_max_sum + right_max_sum + root->val);
  }

  int maxPathSum(TreeNode * root) {
    if (nullptr == root) {
      return 0;
    }
    int left_max_sum, right_max_sum;
    return getMaxPathSum(root, left_max_sum, right_max_sum);
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
  int res = sl.maxPathSum(root);
  cout << res << endl;
  return 0;
}
