/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:bitree_processor.cc
 * Author:
 * Mail:
 * Created Time:2018年01月13日 星期六 16时53分30秒
 ***************************************************/
#include <iostream>

#include "bitree_processor.h"

using namespace std;

BiTreeProcessor::BiTreeProcessor() {}
BiTreeProcessor::~BiTreeProcessor() {}

void BiTreeProcessor::visit(const TreeNode* p) {
  cout << setw(4) << p->val;
}

// 1. 前/中/后序遍历二叉树

void BiTreeProcessor::preOrderRecursively(TreeNode* root) {
  if (nullptr != root) {
    visit(root);
    preOrderRecursively(root->left);
    preOrderRecursively(root->right);
  }
}

void BiTreeProcessor::inOrderRecursively(TreeNode* root) {
  if (nullptr != root) {
    inOrderRecursively(root->left);
    visit(root);
    inOrderRecursively(root->right);
  }
}

void BiTreeProcessor::postOrderRecursively(TreeNode* root) {
  if (nullptr != root) {
    postOrderRecursively(root->left);
    postOrderRecursively(root->right);
    visit(root);
  }
}

void BiTreeProcessor::preOrder(TreeNode* root) {
  if (nullptr == root) {
    return;
  }
  stack<TreeNode*> node_stack;
  TreeNode* p = root;
  while (!node_stack.empty() || nullptr != p) {
    while (nullptr != p) {
      visit(p);
      node_stack.push(p);
      p = p->left;
    }
    if (!node_stack.empty()) {
      p = node_stack.top();
      node_stack.pop();
      p = p->right;
    }
  }
}

void BiTreeProcessor::inOrder(TreeNode* root) {
  if (nullptr == root) {
    return;
  }
  stack<TreeNode*> node_stack;
  TreeNode* p = root;
  while (!node_stack.empty() || nullptr != p) {
    while (nullptr != p) {
      node_stack.push(p);
      p = p->left;
    }
    if (!node_stack.empty()) {
      p = node_stack.top();
      node_stack.pop();
      visit(p);
      p = p->right;
    }
  }
}

void BiTreeProcessor::postOrder(TreeNode* root) {
  if (nullptr == root) {
    return;
  }
  stack<TreeNode*> node_stack;
  TreeNode* pre = nullptr;// 指向刚才访问过的节点
  TreeNode* p = root;
  node_stack.push(p);
  while (!node_stack.empty()) {
    p = node_stack.top();
    // 当前节点是子节点或刚才访问过当前节点的子节点（如果有两个子节点或只有一个右子节点，则pre指向右子节点，如果只有左子节点，则pre指向左子节点）
    if ((nullptr == p->left && nullptr == p->right) ||
	(nullptr != pre && (pre == p->left || pre == p->right))) {
      visit(p);
      node_stack.pop();
      pre = p;
    } else {
      if (nullptr != p->right) {
	node_stack.push(p->right);
      }
      if (nullptr != p->left) {
	node_stack.push(p->left);
      }
    }
  }
}

// 2. 层次遍历二叉树

void BiTreeProcessor::levelOrder(TreeNode* root) {
  if (nullptr == root) {
    return;
  }
  queue<TreeNode*> node_queue;
  TreeNode* p = root;
  node_queue.push(p);
  while (!node_queue.empty()) {
    p = node_queue.front();
    visit(p);
    node_queue.pop();
    if (nullptr != p->left) {
      node_queue.push(p->left);
    }
    if (nullptr != p->right) {
      node_queue.push(p->right);
    }
  }
}

// 3. 获取二叉树节点个数

int  BiTreeProcessor::getNodeNum(TreeNode* root) {
  if (nullptr == root) {
    return 0;
  }
  return getNodeNum(root->left) + getNodeNum(root->right) + 1;
}

// 4. 获取第k层节点个数

int BiTreeProcessor::getKthNodeNum(TreeNode* root, const int& k) {
  if (nullptr == root || k < 1) {// 约定根节点在第1层
    return 0;
  }
  if (1 == k) {
    return 1;
  } else {
    return getKthNodeNum(root->left, k - 1) + getKthNodeNum(root->right, k - 1);
  }
}

// 5. 获取二叉树叶节点个数

int BiTreeProcessor::getLeafNodeNum(TreeNode* root) {
  if (nullptr == root) {
    return 0;
  }
  if (nullptr == root->left && nullptr == root->right) {
    return 1;
  } else {
    return getLeafNodeNum(root->left) + getLeafNodeNum(root->right);
  }
}

// 6. 获取二叉树深度

int BiTreeProcessor::getBiTreeDepth(TreeNode* root) {
  if (nullptr == root) {
    return 0;
  }
  if (nullptr == root->left && nullptr == root->right) {
    return 1;
  } else {
    int left_depth = getBiTreeDepth(root->left);
    int right_depth = getBiTreeDepth(root->right);
    return 1 + (left_depth > right_depth ? left_depth : right_depth);
  }
}

// 7. 判断二叉树结构是否相同

bool BiTreeProcessor::isSameStructure(TreeNode* r1, TreeNode* r2) {
  if (r1 == r2) {
    return true;
  } else if (nullptr == r1 || nullptr == r2) {
    return false;
  }

  // r1 和 r2 都不是空树
  if ((nullptr == r1->left && nullptr != r2->left) ||
      (nullptr != r1->left && nullptr == r2->left) ||
      (nullptr == r1->right && nullptr != r2->right) ||
      (nullptr != r1->right && nullptr == r2->right)) {
    return false;
  } else {
    return isSameStructure(r1->left, r2->left) && isSameStructure(r1->right, r2->right);
  }
}

// 8. 获取二叉树镜像

void BiTreeProcessor::getMirrorImage(TreeNode* root) {
  if (nullptr == root) {
    return;
  }
  TreeNode* temp = root->left;
  root->left = root->right;
  root->right = temp;
  getMirrorImage(root->left);
  getMirrorImage(root->right);
}

// 9. 获取二叉树两个节点的最低公共祖先
/*
bool BiTreeProcessor::nodeInBiTree(TreeNode* root, TreeNode* n) {
  if (nullptr == root || nullptr == n) {
    return false;
  }
  if (n == root) {
    return true;
  } else {
    bool has = false;
    if (nullptr != root->left) {
      has = nodeInBiTree(root->left, n);
    }
    if (!has && nullptr != root->right) {
      has = nodeInBiTree(root->right, n);
    }
    return has;
  }
}
*/
/*
bool BiTreeProcessor::getNodePath(TreeNode* root, TreeNode* pn, vector<TreeNode*>& path) {
  if (nullptr == root || nullptr == pn) {
    return false;
  }
  if (root == pn) {
    path.push_back(root);
    return true;
  }
  bool found = false;
  path.push_back(root);
  found = getNodePath(root->left, pn, path);
  if (!found) {
    found = getNodePath(root->right, pn, path);
  }
  if (!found) {
    path.pop_back();
  }
  return found;
}

TreeNode* BiTreeProcessor::getLowestCommonAncestorRecursively(
    TreeNode* root, TreeNode* n1, TreeNode* n2) {
  if (nodeInBiTree(n1, n2)) {
    return n1;
  } else if (nodeInBiTree(n2, n1)) {
    return n2;
  } else {
    bool one_in_left, another_in_right, one_in_right, another_in_left;
    one_in_left = nodeInBiTree(root->left, n1);
    another_in_right = nodeInBiTree(root->right, n2);
    one_in_right = nodeInBiTree(root->right, n1);
    another_in_left = nodeInBiTree(root->left, n2);
    if ((one_in_left && another_in_right) ||
	(one_in_right && another_in_left)) {
      return root;
    } else if (one_in_left && another_in_left) {
      return getLowestCommonAncestorRecursively(root->left, n1, n2);
    } else if (one_in_right && another_in_right) {
      return getLowestCommonAncestorRecursively(root->right, n1, n2);
    }
  }
  return nullptr;
}
*/
// 9. 获取二叉树中两节点的最低公共祖先

bool BiTreeProcessor::getNodePath(TreeNode* root, TreeNode* pn, vector<TreeNode*>& path) {
  if (nullptr == root) {
    return false;
  }
  if (pn == root) {
    path.push_back(pn);
    return true;
  }
  path.push_back(root);
  bool found = false;
  found = getNodePath(root->left, pn, path);
  if (!found) {
    found  = getNodePath(root->right, pn, path);
  }
  if (!found) {
    path.pop_back();
  }
  return found;
}

TreeNode* BiTreeProcessor::getLowestCommonAncestor(
    TreeNode* root, TreeNode* pn1, TreeNode* pn2) {
  if (nullptr == root || nullptr == pn1 || nullptr == pn2) {
    return 0;
  }
  vector<TreeNode*> path1;
  bool found1 = getNodePath(root, pn1, path1);
  vector<TreeNode*> path2;
  bool found2 = getNodePath(root, pn2, path2);
  if (!found1 || !found2) {
    return nullptr;
  }
  vector<TreeNode*>::iterator iter1 = path1.begin();
  vector<TreeNode*>::iterator iter2 = path2.begin();
  TreeNode* lca = nullptr;// last common ancestor
  while (iter1 != path1.end() && iter2 != path2.end()) {
    if ((*iter1)->val != (*iter2)->val) {
      break;
    }
    lca = *iter1;
    iter1++;
    iter2++;
  }
  return lca;
}

// 10. 获取二叉树中节点的最远距离

int BiTreeProcessor::getMaxDistance(
    TreeNode* root, int& left_depth, int& right_depth) {
  if (nullptr == root) {
    left_depth = 0;
    right_depth = 0;
    return 0;
  }
  int maxLL, maxLR, maxRL, maxRR;
  int left_max_distance, right_max_distance;
  if (nullptr != root->left) {
    left_max_distance = getMaxDistance(root->left, maxLL, maxLR);
    left_depth = max(maxLL, maxLR) + 1;
  } else {
    left_max_distance = 0;
    left_depth = 0;
  }
  if (nullptr != root->right) {
    right_max_distance = getMaxDistance(root->right, maxRL, maxRR);
    right_depth = max(maxRL, maxRR) + 1;
  } else {
    right_max_distance = 0;
    right_depth = 0;
  }
  return max(max(left_max_distance, right_max_distance), left_depth + right_depth);
}

// 11. 由前序遍历和中序遍历构建二叉树

TreeNode* BiTreeProcessor::rebuildBiTreeByPreorderAndInorder(string preorderStr, string inorderStr) {
  if (preorderStr.size() == 0 || inorderStr.size() == 0 || preorderStr.size() != inorderStr.size()) {
    return nullptr;
  }
  TreeNode* root = new TreeNode(preorderStr[0] - '0');
  int pos = inorderStr.find(preorderStr[0]);
  string left_preorder_str = preorderStr.substr(1, pos);
  string right_preorder_str = preorderStr.substr(pos + 1, preorderStr.size() - pos - 1);
  string left_inorder_str = inorderStr.substr(0, pos);
  string right_inorder_str = inorderStr.substr(pos + 1, inorderStr.size() - pos - 1);
  root->left = rebuildBiTreeByPreorderAndInorder(left_preorder_str, left_inorder_str);
  root->right = rebuildBiTreeByPreorderAndInorder(right_preorder_str, right_inorder_str);
  return root;
}
