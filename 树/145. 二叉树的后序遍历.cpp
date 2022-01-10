class Solution {
public:
	vector<int> nums;
    vector<int> postorderTraversal(TreeNode* root) {
		traverse(root);
		return nums;
    }

    void traverse(TreeNode *root) {
    	if (root == NULL)
    		return ;
    
    	traverse(root->left);
    	traverse(root->right);
    	nums.push_back(root->val);
	} 
};
