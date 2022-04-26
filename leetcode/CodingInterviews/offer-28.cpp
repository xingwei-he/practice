#include <iostream>

using namespace std;

class Solution {
public:
	bool isMirror(TreeNode *root1, TreeNode *root2) {
		if (nullptr == root1 && nullptr == root2) {
			return true;
		}
		if (nullptr == root1 || nullptr == root2) {
			return false;
		}
		if (root1->val == root2->val) {
			return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
		}
		return false;
	}

    bool isSymmetric(TreeNode* root) {
		if (nullptr == root) {
			return true;
		}
		return isMirror(root->left, root->right);
    }
};