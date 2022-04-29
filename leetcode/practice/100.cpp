/**************************************
* He Xingwei, All Rights Reserved.
* Filename:100.cpp
* Date:2022-04-22 18:17:11
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode* r1, TreeNode* r2) {
    	if (r1 == r2) { // 都是空树或指向同一棵树
    		return true;
    	}
        if (nullptr == r1 || nullptr == r2) { // 有且仅有一个空树
            return false;
        }
        if (r1->val == r2->val) {
    		return isSameTree(r1->left, r2->left) && isSameTree(r1->right, r2->right);
    	}
    	return false;
    }
};