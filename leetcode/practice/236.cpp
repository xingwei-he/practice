/**************************************
* He Xingwei, All Rights Reserved.
* Filename:236.cpp
* Date:2022-04-22 18:55:27
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
	bool inTree(TreeNode *root, TreeNode *p) {
		if (nullptr == root || nullptr == p) {
			return false;
		}
		if (root == p) {
			return true;
		}
		return inTree(root->left, p) || inTree(root->right, p);
	}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p1, TreeNode* p2) {
    	if (inTree(p1, p2)) {
    		return p1;
    	}
    	if (inTree(p2, p1)) {
    		return p2;
    	}
    	bool one_in_left, another_in_right, one_in_right, another_in_left;
    	one_in_left = inTree(root->left, p1);
    	another_in_right = inTree(root->right, p2);
    	one_in_right = inTree(root->right, p1);
    	another_in_left = inTree(root->left, p2);
    	if ((one_in_left && another_in_right) ||
    			(one_in_right && another_in_left)) {
    		return root;
    	} else if (one_in_left && another_in_left) {
    		return lowestCommonAncestor(root->left, p1, p2);
    	} else if (one_in_right && another_in_right) {
    		return lowestCommonAncestor(root->right, p1, p2);
    	} else {
    		return nullptr;
    	}
    }
};