/**************************************
* He Xingwei, All Rights Reserved.
* Filename:114.cpp
* Date:2022-05-02 23:20:24
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
	void preOrder(TreeNode *root, vector<TreeNode *> &seq) {
		if (nullptr != root) {
			seq.emplace_back(root);
			preOrder(root->left, seq);
			preOrder(root->right, seq);
		}
	}

    void flatten(TreeNode* root) {
    	vector<TreeNode *> seq;
    	preOrder(root, seq);
    	TreeNode *head = new TreeNode();
    	TreeNode *p = head;
    	for (int i = 0; i < seq.size(); i++) {
    		p->right = seq[i];
            p->left = nullptr;
    		p = p->right;
    	}
    	p = head->right;
    	delete head;
        root = p;
    }
};