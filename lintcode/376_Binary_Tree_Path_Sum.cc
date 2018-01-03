/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:376_Binary_Tree_Path_Sum.cc
 * Author:
 * Mail:
 * Created Time:星期三  1/ 3 17:56:09 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a binary tree, find all paths that sum of the nodes in the path equals to a given number target.
 * A valid path is from root node to any of the leaf nodes.
 *
 * Example
 * Given a binary tree, and target = 5:
 *
 *      1
 *     / \
 *    2   4
 *   / \
 *  2   3
 *
 * return
 *
 * [
 *   [1, 2, 2],
 *   [1, 4]
 * ]
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
   * @param target: An integer
   * @return: all valid paths
   */
  vector<vector<int> > binaryTreePathSum(TreeNode * root, int target) {
    vector<vector<int> > res;
    if (nullptr == root) {
      return res;
    }
    stack<TreeNode*> st;
    TreeNode* p = root;
    int sum = 0;
    vector<int> path;
    int counter = 0;
    while (!st.empty() || nullptr != p) {
      counter++;
      if (counter > 10) {
	break;
      }
      cout << "sum:" << sum << endl;
      while (nullptr != p) {
	sum += p->val;
	path.push_back(p->val);
	if (sum == target && nullptr == p->left && nullptr == p->right) {
	  res.push_back(path);
	  break;
	} else if (sum > target) {
	  break;
	} else {
	  st.push(p);
	  p = p->left;
	}
      }
      if (!st.empty()) {
	p = st.top();
	st.pop();
	p = p->right;
      }
    }
    return res;
  }
};

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(4);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(3);

  Solution sl;
  vector<vector<int> > res = sl.binaryTreePathSum(root, 5);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << "  ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}

