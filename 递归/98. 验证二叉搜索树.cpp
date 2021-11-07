class Solution {
public:
    bool isValidBST(TreeNode* root) {
		return traverse(root, NULL, NULL);
    }
    
    bool traverse(TreeNode *root, TreeNode *min, TreeNode *max) {
    	if (root == NULL)
    		return true;
    	
    	if (max != NULL && root->val >= max->val)
    		return false;
    		
    	if (min != NULL && root->val <= min->val)
    		return false;
    	
    	return traverse(root->left, min, root)
    			&& traverse(root->right, root, max);
	} 
};
