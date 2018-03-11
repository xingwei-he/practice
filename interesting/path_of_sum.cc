/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:path_of_sum.cc
 * Author:
 * Mail:
 * Created Time:2018年03月11日 星期日 18时34分32秒
 ***************************************************/
#include <iostream>
#include <vector>

#include "../include/base.h"

using namespace std;

class Solution {
public:
  vector<vector<int> > getPathOfSum(TreeNode* root, int sum) {
    vector<vector<int> > paths;
    if (nullptr == root) {
      return paths;
    }
    vector<int> one_path;
    findPath(root, sum, paths, one_path, 0);
    return paths;
  }

  // 定义根节点到叶节点才算一条 path
  void findPath(TreeNode* root, int sum, vector<vector<int> >& paths, vector<int>& one_path, int current_sum) {
    if (nullptr == root) {
      return;
    }
    one_path.push_back(root->val);// 把当前节点放入 one_path 进行测试
    current_sum += root->val;
    bool is_leaf = false;
    if (nullptr == root->left && nullptr == root->right) {
      is_leaf = true;
    }
    if (is_leaf && sum == current_sum) {// 如果该点是一个叶节点（能构成一条 path）并且和满足要求则该 one_path 是一个解
      paths.push_back(one_path);
    }
    if (nullptr != root->left) {
      findPath(root->left, sum, paths, one_path, current_sum);
    }
    if (nullptr != root->right) {
      findPath(root->right, sum, paths, one_path, current_sum);
    }
    one_path.pop_back();// 回退这个节点
  }
  
  // 只要求 path 从根节点出发即可（不一定非要叶节点做结尾）
  void findPathII(TreeNode* root, int sum, vector<vector<int> >& paths, vector<int>& one_path, int current_sum) {
    if (nullptr == root) {
      return;
    }
    one_path.push_back(root->val);
    current_sum += root->val;
    if (sum == current_sum) {
      paths.push_back(one_path);
    }
    if (nullptr != root->left) {
      findPathII(root->left, sum, paths, one_path, current_sum);
    }
    if (nullptr != root->right) {
      findPathII(root->right, sum, paths, one_path, current_sum);
    }
    one_path.pop_back();
  }
 
};

int main() {
  /**
   *       1
   *      / \
   *     2   3
   *    / \
   *   4   5
   */
  TreeNode* t = new TreeNode(1);
  t->left = new TreeNode(2);
  t->right = new TreeNode(3);
  t->left->left = new TreeNode(4);
  t->left->right = new TreeNode(5);
  t->right->right = new TreeNode(4);
  Solution sl;
  int sum = 4;
  vector<vector<int> > paths = sl.getPathOfSum(t, sum);
  cout << "paths size:" << paths.size() << endl;
  for (int i = 0; i < paths.size(); i++) {
    for (int j = 0; j < paths[i].size(); j++) {
      cout << paths[i][j] << "  ";
    }
    cout << endl;
  }
  return 0;
}
