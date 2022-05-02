/**************************************
* He Xingwei, All Rights Reserved.
* Filename:105.cpp
* Date:2022-05-01 17:28:44
* Description:
**************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	if (preorder.empty() || inorder.empty()) {
    		return nullptr;
    	}
    	if (preorder.size() != inorder.size()) {
    		return nullptr;
    	}
    	TreeNode *root = new TreeNode(preorder[0]);
    	auto iter = find(inorder.begin(), inorder.end(), preorder[0]);
    	int pos = iter - inorder.begin();
    	// 分割 preorder
    	vector<int> preorder_left(preorder.begin() + 1, preorder.begin() + pos + 1);
    	vector<int> preorder_right(preorder.begin() + pos + 1, preorder.end());
    	// 分割 inorder
    	vector<int> inorder_left(inorder.begin(), inorder.begin() + pos);
    	vector<int> inorder_right(inorder.begin() + pos + 1, inorder.end());
        
    	root->left = buildTree(preorder_left, inorder_left);
    	root->right = buildTree(preorder_right, inorder_right);
    	return root;
    }
};

int main() {
    //vector<int> preorder{1,2,4,5,6,3,7};
    //vector<int> inorder{4,2,6,5,1,3,7};
    vector<int> preorder{3,9,20,15,7};
	vector<int> inorder{9,3,15,20,7};

	Solution s;
	TreeNode *root = s.buildTree(preorder, inorder);
    cout << root->val << endl;
    cout << root->left->val << "," << root->right->val << endl;
    cout << root->right->left->val << "," << root->right->right->val << endl;
	return 0;
}
