class Solution {
public:
    bool isBalanced(TreeNode* root) {
		return traverse(root) != -1;
    }
    
	int traverse(TreeNode *root) {
		if (root == NULL)
			return 0;
				
		int left = traverse(root->left);
		if (left == -1)
			return -1;
		
		int right = traverse(root->right);
		if (right == -1)
			return -1;
		
		if (abs(left - right) > 1) 
			return -1;
		
		return left > right ? left + 1: right + 1;
	}
};
