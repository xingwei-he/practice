/**************************************
* He Xingwei, All Rights Reserved.
* Filename:222.cpp
* Date:2022-04-22 17:46:01
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int countNodes(TreeNode* root) {
    	if (nullptr == root) {
    		return 0;
    	}
    	return 1 + countNodes(root->left) + countNodes(root->right);
    }
};