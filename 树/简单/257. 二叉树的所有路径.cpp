class Solution {
public:
	vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
		dfs(root, "");
		return res;	
    }
    
    void dfs(TreeNode *root, string prefix) {
    	if (root == NULL)
    		return ;
    	
    	if (root->left == NULL && root->right == NULL) {
    		res.push_back(prefix + to_string(root->val));
    		return ;
		}
    	
    	dfs(root->left, prefix+to_string(root->val)+"->");
    	dfs(root->right, prefix+to_string(root->val)+"->");
	}
};
