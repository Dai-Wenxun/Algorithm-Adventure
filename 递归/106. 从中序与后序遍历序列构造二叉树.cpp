class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return helper(postorder, inorder, postorder.size()-1, 0, inorder.size()-1);
    }
    
    TreeNode *helper(vector<int>& postorder, vector<int>& inorder, int post_index, int left, int right) {
    	if (left > right) 
    		return NULL;
    	
    	int cur_val = postorder[post_index];
    	int i;
    	for (i = left; i <= right; ++i) {
    		if (inorder[i] == cur_val) 	
				break;
		}
    	
    	TreeNode *new_node = new TreeNode(cur_val);
    	
    	new_node->left = helper(postorder, inorder, post_index-1-(right-i), left, i-1);
    	new_node->right = helper(postorder, inorder, post_index-1, i+1, right);
	
		return new_node;
	}
};
