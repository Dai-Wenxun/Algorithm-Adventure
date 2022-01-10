class Solution {
public:
    int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		
		int leftDep = maxDepth(root->left);
		int rightDep = maxDepth(root->right); 
		
		return leftDep > rightDep ? 1 + leftDep : 1 + rightDep;
    }
};
