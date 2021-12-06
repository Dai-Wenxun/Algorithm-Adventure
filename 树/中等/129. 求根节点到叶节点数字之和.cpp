class Solution {
public:
	int sum = 0;
    int sumNumbers(TreeNode* root) {
		traverse(root, 0);
		return sum;
    }
    
    void traverse(TreeNode *root, int cur_sum) {
    	if (root == NULL)
    		return ;
    	
    	if (root->left == NULL && root->right == NULL) {
    		sum += cur_sum * 10 + root->val;
    		return ;
		}
    	
    	traverse(root->left, cur_sum * 10 + root->val);
    	traverse(root->right, cur_sum * 10 + root->val);
	}
};
