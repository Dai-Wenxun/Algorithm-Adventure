class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> v;
		if (root == NULL)
			return v;
		
		queue<TreeNode *> q;
		q.push(root);
		TreeNode *cur_node;
		while(!q.empty()) {
			int size = q.size();
			vector<int> nums;
			for (int i = 0; i < size; ++i) {
				cur_node = q.front();
				q.pop();
				if (cur_node->left != NULL)
					q.push(cur_node->left);
				if (cur_node->right != NULL)
					q.push(cur_node->right);
				
				nums.push_back(cur_node->val);
			}
			v.push_back(nums);
		}
		return v;
	}
};
