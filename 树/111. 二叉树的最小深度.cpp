class Solution {
public:
	int min = 1e7;
    int minDepth(TreeNode* root) {
    	if (root == NULL)
    		return 0;
		dfs(root, 1);
		return min;
    }
    
    void dfs(TreeNode *root, int cur) {
    	if (root == NULL)
    		return ;
    	
    	if (root->left == NULL && root->right == NULL) {
    		if (min > cur)
    			min = cur;
			return ;
		}
    	
    	dfs(root->left, cur+1);
    	dfs(root->right, cur+1);
	}  
};
