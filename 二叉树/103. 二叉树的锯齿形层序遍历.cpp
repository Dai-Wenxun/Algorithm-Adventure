class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> v;
		if (root == NULL)
			return v;
		
		queue<TreeNode *> q;
		q.push(root);
		TreeNode *cur_node;
		bool leftflag = true;
		while(!q.empty()) {
			int size = q.size();
			deque<int> nums;

			for (int i = 0; i < size; ++i) {
				cur_node = q.front();
				q.pop();
				if (cur_node->left != NULL)
					q.push(cur_node->left);
				if (cur_node->right != NULL)
					q.push(cur_node->right);
				if (leftflag)
					nums.push_back(cur_node->val);
				else
					nums.push_front(cur_node->val);
			}
			leftflag = !leftflag;
			v.push_back(vector<int>(nums.begin(), nums.end()));
		}
		return v;
	}
};
