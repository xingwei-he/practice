/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:11_Search_Range_in_Binary_Search_Tree.cc
 * Author:
 * Mail:
 * Created Time:2018年01月07日 星期日 21时39分12秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given two values k1 and k2 (where k1 < k2) and a root pointer to a Binary Search Tree. Find all the keys of tree in range k1 to k2. i.e. print all x such that k1<=x<=k2 and x is a key of given BST. Return all the keys in ascending order.
 *
 * Example
 * If k1 = 10 and k2 = 22, then your function should return [12, 20, 22].
 *
 *     20
 *    /  \
 *   8   22
 *  / \
 * 4   12
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
   * @param root: param root: The root of the binary search tree
   * @param k1: An integer
   * @param k2: An integer
   * @return: return: Return all keys that k1<=key<=k2 in ascending order
   */
  void processor(TreeNode* r, int k1, int k2, vector<int>& vec) {
    if (nullptr == r || k1 > k2) {
      return;
    }
    if (nullptr != r->left && r->val >= k1) {
      processor(r->left, k1, k2, vec);
    }
    if (r->val >= k1 && r->val <= k2) {
      vec.push_back(r->val);
    }
    if (nullptr != r->right && r->val <= k2) {
      processor(r->right, k1, k2, vec);
    }
  }

  vector<int> searchRange(TreeNode * root, int k1, int k2) {
    vector<int> res;
    if (nullptr == root || k1 > k2) {
      return res;
    }
    processor(root, k1, k2, res);
    return res;
  }
};

int main() {
  TreeNode* root = new TreeNode(2);
  root->left = new TreeNode(1);
  Solution sl;
  vector<int> res = sl.searchRange(root, 0, 4);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << "  ";
  }
  cout << endl;
  return 0;
}
