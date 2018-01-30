/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:main.cc
 * Author:
 * Mail:
 * Created Time:2018年01月13日 星期六 17时18分36秒
 ***************************************************/
#include <iostream>

using namespace std;

#include "bitree.h"
#include "bitree_processor.h"

int main() {
  BiTree bitree;
  TreeNode* root = bitree.getBiTree();

  BiTreeProcessor bitree_processor;

  cout << endl;
  cout << "          1" << endl;
  cout << "        /   \\" << endl;
  cout << "       2     3" << endl;
  cout << "        \\   / \\" << endl;
  cout << "         4 5   6" << endl;
  cout << "        /   \\   \\" << endl;
  cout << "       7     8   9" << endl;
  cout << "            / \\" << endl;
  cout << "           10  11" << endl;
  cout << endl;
  // 1. 前/中/后序遍历二叉树
  cout << "1. 前/中/后序遍历二叉树" << endl;
 
  cout << "前序遍历（递归）\t";
  bitree_processor.preOrderRecursively(root);
  cout << endl;
  cout << "前序遍历（非递归）\t";
  bitree_processor.preOrder(root);
  cout << endl;
 
  cout << "中序遍历（递归）\t";
  bitree_processor.inOrderRecursively(root);
  cout << endl;
  cout << "中序遍历（非递归）\t";
  bitree_processor.inOrder(root);
  cout << endl;
  
  cout << "后序遍历（递归）\t";
  bitree_processor.postOrderRecursively(root);
  cout << endl;
  cout << "后序遍历（非递归）\t";
  bitree_processor.postOrder(root);
  cout << endl;

  // 2. 层次遍历二叉树
  cout << "2. 层次遍历二叉树" << endl;
  bitree_processor.levelOrder(root);
  cout << endl;

  // 3. 获取二叉树节点个数
  cout << "3. 获取二叉树节点个数" << endl;
  int bitree_node_num = bitree_processor.getNodeNum(root);
  cout << "result:" << bitree_node_num << endl;

  // 4. 获取第k层节点个数
  cout << "4. 获取第k层节点个数" << endl;
  int k = 3;
  int bitree_kth_node_num = bitree_processor.getKthNodeNum(root, k);
  cout << "k:" << k << "\tresult:" << bitree_kth_node_num << endl;
  
  // 5. 获取二叉树叶节点个数
  cout << "5. 获取二叉树叶节点个数" << endl;
  int bitree_leaf_node_num = bitree_processor.getLeafNodeNum(root);
  cout << "result:" << bitree_leaf_node_num << endl;

  // 6. 获取二叉树深度
  cout << "6. 获取二叉树深度" << endl;
  int bitree_depth = bitree_processor.getBiTreeDepth(root);
  cout << "result:" << bitree_depth << endl;

  // 7. 判断二叉树结构是否相同
  cout << "7. 判断二叉树结构是否相同" << endl;
  BiTree bt_temp;
  TreeNode* root_temp = bt_temp.getBiTree();
  root_temp->left->left = new TreeNode(88);
  bool is_same_structure = bitree_processor.isSameStructure(root, root_temp);
  cout << "resultl:" << boolalpha << is_same_structure << endl;

  // 8. 获取二叉树镜像
  cout << "8. 获取二叉树镜像" << endl;
  root_temp = bt_temp.getBiTree();
  bitree_processor.getMirrorImage(root_temp);
  cout << "镜像的前序遍历\t";
  bitree_processor.preOrderRecursively(root_temp);
  cout << endl;
  cout << "镜像的中序遍历\t";
  bitree_processor.inOrderRecursively(root_temp);
  cout << endl;
  cout << "镜像的后序遍历\t";
  bitree_processor.postOrderRecursively(root_temp);
  cout << endl;

  // 9. 获取二叉树两个节点的最低公共祖先
  cout << "9. 获取二叉树两个节点的最低公共祖先" << endl;
  TreeNode* n1 = root->right->left->right;
  TreeNode* n2 = root->right->right;
  cout << "n1:" << n1->val << "\tn2:" << n2->val << endl;
  TreeNode* lca = bitree_processor.getLowestCommonAncestor(root, n1, n2);
  cout << "Lowest Common Ancestor's value is " << lca->val << endl;
  
  // 10. 获取二叉树中节点的最远距离
  cout << "10. 获取二叉树中节点的最远距离" << endl;
  int left_depth, right_depth;
  int max_distance = bitree_processor.getMaxDistance(root, left_depth, right_depth);
  cout << "max_distance:" << max_distance << "\tleft_depth:" << left_depth << "\tright_depth:" << right_depth << endl;

  // 11. 由前序遍历和中序遍历构建二叉树
  //cout << "11. 由前序遍历和中序遍历构建二叉树" <<  endl;
  string preorderStr = "12465378";
  string inorderStr = "46251387";
  cout << "preorder:" << preorderStr << endl;
  cout << "inrorder:" << inorderStr << endl;
  cout << "rebuilding..." << endl;
  TreeNode* r = bitree_processor.rebuildBiTreeByPreorderAndInorder(preorderStr, inorderStr);
  cout << "preorder:";
  bitree_processor.preOrder(r);
  cout << endl;
  cout << "inorder:";
  bitree_processor.inOrder(r);
  cout << endl;
  cout << "postorder:";
  bitree_processor.postOrder(r);
  cout << endl;
  
  return 0;
}
