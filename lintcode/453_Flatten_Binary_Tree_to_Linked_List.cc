/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:453_Flatten_Binary_Tree_to_Linked_List.cc
 * Author:
 * Mail:
 * Created Time:星期五  1/ 5 10:58:02 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Flatten a binary tree to a fake "linked list" in pre-order traversal.
 * Here we use the right pointer in TreeNode as the next pointer in ListNode.
 *
 * Notice
 *   Don't forget to mark the left child of each node to null. Or you will get Time Limit Exceeded or Memory Limit Exceeded.
 *
 * Example
 *                          1
 *      	             \
 *      	   1          2
 *      	  / \          \
 *      	 2   5    =>    3
 *      	/ \   \          \
 *             3   4   6          4
 *      	                   \
 *      			    5
 *      			     \
 *      			      6
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
   * @param root: a TreeNode, the root of the binary tree
   * @return: 
   */
/* 方法一 借助一个 vector 保存 preOrder，再遍历这个 vector 重构单链表
  void flatten(TreeNode * root) {
    if (nullptr == root) {
      return;
    }
    vector<TreeNode*> node_vec;
    stack<TreeNode*> st;
    TreeNode* p = root;
    while (nullptr != p || !st.empty()) {
      while (nullptr != p) {
	node_vec.push_back(p);
	st.push(p);
	p = p->left;
      }
      if (!st.empty()) {
	p = st.top();
	st.pop();
	p = p->right;
      }
    }
    node_vec.push_back(nullptr);
    for (int i = 1; i < node_vec.size(); i++) {
      node_vec[i - 1]->left = nullptr;
      node_vec[i - 1]->right = node_vec[i];
    }
  }
  */

  /* 方法二 遍历同时进行操作 */
  void flatten(TreeNode* root) {
    TreeNode* cur = root;
    while (nullptr != cur){
      if (nullptr != cur->left){
	TreeNode* pre = cur->left;
	while (nullptr != pre->right){
	  pre = pre->right;
	}
	//将当前节点的右孩子连接到当前节点左孩子的的最右孩子  
	pre->right = cur->right;
	//当前节点的左孩子变为右孩子，左孩子置为NULL  
	cur->right = cur->left;
	cur->left = NULL;
      }
      cur = cur->right;
    }
  }
};

int main() {
  TreeNode* root = new TreeNode(1);
  Solution sl;
  sl.flatten(root);
  for (TreeNode* p = root; p != nullptr; p = p->right) {
    cout << p->val << "  ";
  }
  cout << endl;
  return 0;
}
