/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:bitree_processor.h
 * Author:
 * Mail:
 * Created Time:2018年01月13日 星期六 16时32分50秒
 ***************************************************/
#ifndef _BITREE_PROCESSOR_H
#define _BITREE_PROCESSOR_H

#include "practice/include/base.h"

class BiTreeProcessor {
public:
  BiTreeProcessor();
  virtual ~BiTreeProcessor();

  void visit(const TreeNode* p);

  // 1. 前/中/后序遍历二叉树
  void preOrderRecursively(TreeNode* root);
  void inOrderRecursively(TreeNode* root);
  void postOrderRecursively(TreeNode* root);

  void preOrder(TreeNode* root);
  void inOrder(TreeNode* root);
  void postOrder(TreeNode* root);

  // 2. 层次遍历二叉树
  void levelOrder(TreeNode* root);

  // 3. 获取二叉树节点个数
  int getNodeNum(TreeNode* root);

  // 4. 获取第k层节点个数
  int getKthNodeNum(TreeNode* root, const int& k);

  // 5. 获取二叉树叶节点个数
  int getLeafNodeNum(TreeNode* root);

  // 6. 获取二叉树深度
  int getBiTreeDepth(TreeNode* root);

  // 7. 判断两个二叉树结构是否相同
  bool isSameStructure(TreeNode* r1, TreeNode* r2);

  // 8. 获取二叉树镜像
  void getMirrorImage(TreeNode* root);

  // 9. 获取二叉树两个节点的最低公共祖先
  //bool nodeInBiTree(TreeNode* root, TreeNode* pn);
  //TreeNode* getLowestCommonAncestorRecursively(TreeNode* root, TreeNode* pn1, TreeNode* pn2);
  bool getNodePath(TreeNode* root, TreeNode* pn, std::vector<TreeNode*>& path);
  TreeNode* getLowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2);

  // 10. 获取二叉树中节点的最远距离
  int getMaxDistance(TreeNode* root, int& left_depth, int& right_depth);

  // 11. 由前序遍历和中序遍历构建二叉树
  TreeNode* rebuildBiTreeByPreorderAndInorder(std::string preorder, std::string inorder);

  // 12. 判断二叉树是不是完全二叉树
  bool isCompleteBiTree(TreeNode* root);

};

#endif

