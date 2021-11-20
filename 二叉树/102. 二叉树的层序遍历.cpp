class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> v;
		if (root == NULL)
			return v;
		
		queue<pair<TreeNode *, int>> q;
		q.push(pair<TreeNode *, int>(root, 1));
		TreeNode *cur_node;
		int dep;
		while(!q.empty()) {
			cur_node = q.front().first;
			dep = q.front().second;
			q.pop();
			
			if (cur_node->left != NULL) {
				q.push(pair<TreeNode*, int>(cur_node->left, dep+1));
			}
			if (cur_node->right != NULL) {
				q.push(pair<TreeNode*, int>(cur_node->right, dep+1));
			}
			
			if (v.size() < dep)
				v.push_back(vector<int>());
			v[dep-1].push_back(cur_node->val);
		}
		return v;
	}
};
