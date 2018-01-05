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

/* 方法一 借助一个 vector 保存 preOrder，再遍历这个 vector 重构单链表 */
class Solution {
public:
  /*
   * @param root: a TreeNode, the root of the binary tree
   * @return: 
   */
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
};

int main() {
  return 0;
}
