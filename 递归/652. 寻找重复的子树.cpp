class Solution {
public:
	unordered_map<string, int> mp;
	vector<TreeNode *> nodes;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		helper(root);
		return nodes;
    }
    
    string helper(TreeNode *root) {
    	if (root == NULL)
    		return "#";
    		
    	string left = helper(root->left);
    	string right = helper(root->right);
    	
    	string res = left + "," + right + "," + to_string(root->val);
    	
    	auto it = mp.find(res);
		if (it == mp.end()) {
			mp[res] = 1;
		} else {
			if (it->second == 1) {
				nodes.push_back(root);
			}
            it->second += 1;
		}
		return res;
	} 
};
