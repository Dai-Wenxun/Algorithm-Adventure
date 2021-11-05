class Solution {
public:
	int cnt;
	int val;
    int kthSmallest(TreeNode* root, int k) {
		traverse(root, k);
		 
		return val;
    }
    
    void traverse(TreeNode *root, int k) {
    	if (root == NULL)
    		return ;
    	
    	traverse(root->left, k);
    	
    	cnt++;
    	
    	if (cnt == k) {
    		val = root->val;
    		return ;
		}

    	traverse(root->right, k);
	}
};
