class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if (root == NULL)
    		return NULL;
    		
    	if (root == p || root == q)
    		return root;
    	
        auto left =  lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
    
		if (left != NULL && right != NULL)
			return root;
					
		if (left == NULL && right == NULL)
			return NULL;
			
		return left == NULL ? right: left;
	}
};
