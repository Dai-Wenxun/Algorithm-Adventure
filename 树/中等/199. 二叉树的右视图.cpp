class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		if (root == NULL)
			return res;
		
		queue<TreeNode *> q;
		q.push(root);
		TreeNode *cur;
		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				cur = q.front();
				q.pop();
				if (cur->left != NULL) 
					q.push(cur->left);
				if (cur->right != NULL)
					q.push(cur->right);
			}
			res.push_back(cur->val);
		} 
		return res; 
    }
};

class Solution {
public:
	vector<int> res; 
    vector<int> rightSideView(TreeNode* root) {
		dfs(root, 0);
		return res;
    }
    
    void dfs(TreeNode *root, int dep) {
    	if (root == NULL)
    		return ;
    	
    	if (dep == res.size())
    		res.push_back(root->val);
    		
    	dfs(root->right, dep+1);
    	dfs(root->left, dep+1);
	}
};
