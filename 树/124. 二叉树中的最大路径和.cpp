class Solution {
public:
	int val = INT_MIN;
    int maxPathSum(TreeNode* root) {
		if (root == NULL)
			return 0;
		traverse(root);
		
		return val;
    }
    
    int traverse(TreeNode *root) {
    	if(root == NULL)
			return 0; 
    	
    	int left = max(0, traverse(root->left));
    	int right = max(0, traverse(root->right));
    	
    	int lmr = left + right + root->val;
    	
    	int res = root->val + max(left, right);
    	
    	val = max(max(val, res), lmr);
    	
    	return res;
	}
};
