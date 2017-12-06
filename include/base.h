/***************************************************
 Xingwei_He All Rights Reserved.
 * File Name:base.h
 * Author:
 * Mail:
 * Created Time:星期一 12/ 4 11:08:01 2017
 ***************************************************/
#ifndef _BASE_H
#define _BASE_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// Definition of TreeNode:
class TreeNode {
public:
  int val;
  TreeNode *left, *right;
  TreeNode(int val) {
    this->val = val;
    this->left = this->right = NULL;
  }
};



#endif

