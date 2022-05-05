/**************************************
* He Xingwei, All Rights Reserved.
* Filename:437.cpp
* Date:2022-05-04 16:13:26
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (nullptr == root) {
        	return 0;
        }
       	int counter = 0;
       	rootSum(root, targetSum, counter);
       	counter += pathSum(root->left, targetSum);
       	counter += pathSum(root->right, targetSum);
       	return counter;
    }

    void rootSum(TreeNode *root, int64_t target, int &counter) {
    	if (nullptr == root) {
    		return;
    	}
    	if (target == root->val) {
    		counter++;
    	}
    	
    	rootSum(root->left, target - root->val, counter);
    	rootSum(root->right, target - root->val, counter);
    }
};
