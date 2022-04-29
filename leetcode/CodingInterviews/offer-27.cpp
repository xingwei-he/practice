/**************************************
* He Xingwei, All Rights Reserved.
* Filename:Offer-00027.cpp
* Date:2022-04-22 18:36:24
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
    	if (nullptr == root) {
    		return nullptr;
    	}
    	swap(root->left, root->right);
    	mirrorTree(root->left);
    	mirrorTree(root->right);
    	return root;
    }
};