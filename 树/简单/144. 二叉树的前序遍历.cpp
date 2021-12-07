class Solution {
public:
	vector<int> nums;
    vector<int> preorderTraversal(TreeNode* root) {
		traverse(root);
		return nums;
    }

    void traverse(TreeNode *root) {
    	if (root == NULL)
    		return ;
    	
    	nums.push_back(root->val);
    	traverse(root->left);
    	traverse(root->right);
	} 
};
