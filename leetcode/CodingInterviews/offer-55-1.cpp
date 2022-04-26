#include <iostream>

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
		if (nullptr == root) {
			return 0;
		}
		if (nullptr == root->left && nullptr == root->right) {
			return 1;
		}
		int left_depth = maxDepth(root->left);
		int right_depth = maxDepth(root->right);
		return max(left_depth, right_depth) + 1;
    }
};
