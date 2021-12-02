class Solution {
public:
	vector<vector<int>> res;
	vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		dfs(root, targetSum);
		return res;
    }
    
    void dfs(TreeNode *root, int targetSum) {
    	if (root == NULL)
    		return ;
    	
    	targetSum -= root->val;
    	path.push_back(root->val);
    	if (targetSum == 0 && root->left == NULL && root->right == NULL) {
    		res.push_back(path);
		}
		
		dfs(root->left, targetSum);
		dfs(root->right, targetSum);
		path.pop_back()
	}
};
