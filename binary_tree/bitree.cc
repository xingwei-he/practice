/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:bitree.cc
 * Author:
 * Mail:
 * Created Time:2018年01月13日 星期六 16时19分32秒
 ***************************************************/
#include <iostream>

#include "bitree.h"

using namespace std;

/**
 *          1
 *        /   \
 *       2     3
 *        \   / \
 *         4 5   6
 *        /   \   \
 *	 7     8   9
 *	      / \
 *	     10  11
 */

BiTree::BiTree() {}
BiTree::~BiTree() {}

TreeNode* BiTree::getBiTree() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->left->right->left = new TreeNode(7);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);
  root->right->left->right = new TreeNode(8);
  root->right->left->right->left = new TreeNode(10);
  root->right->left->right->right = new TreeNode(11);
  root->right->right->right = new TreeNode(9);
  return root;
}
