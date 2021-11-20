class Solution {
public:
    void flatten(TreeNode* root) {
		if (root == NULL)
			return ;
		
		flatten(root->left);
		flatten(root->right);
		
		TreeNode *left = root->left;
		TreeNode *right = root->right;
			
		root->left = NULL;
		root->right = left;
		
		TreeNode *p = root;
	
		while(p->right != NULL) {
			p = p->right;
		}
	
		p->right = right;
	}
};
