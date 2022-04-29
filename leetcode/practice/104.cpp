/**************************************
* He Xingwei, All Rights Reserved.
* Filename:104.cpp
* Date:2022-04-22 17:57:12
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
    	if (nullptr == root) {
    		return 0;
    	}
    	int left_depth = maxDepth(root->left);
    	int right_depth = maxDepth(root->right);
    	return left_depth > right_depth ? left_depth+1 : right_depth+1;
    }
};