class Solution {
public:
	int sum;
    TreeNode* bstToGst(TreeNode* root) {
    	sum = 0;
		traverse(root);
		return root;
    }

    void traverse(TreeNode *root) {
    	if (root == NULL)
    		return ;
    	
    	traverse(root->right);
    	
    	root->val += sum;
    	sum = root->val;
    	
    	traverse(root->left);
	}
};
