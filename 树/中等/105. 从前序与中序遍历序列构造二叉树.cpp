class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return helper(preorder, inorder, 0, 0, inorder.size()-1);
    }
    
    TreeNode *helper(vector<int>& preorder, vector<int>& inorder, int pre_index, int left, int right) {
    	if (left > right) 
    		return NULL;
    	
    	int cur_val = preorder[pre_index];
    	int i;
    	for (i = left; i <= right; ++i) {
    		if (inorder[i] == cur_val) 	
				break;
		}
    	
    	TreeNode *new_node = new TreeNode(cur_val);
    	
    	new_node->left = helper(preorder, inorder, pre_index+1, left, i-1);
    	new_node->right = helper(preorder, inorder, pre_index+i-left+1, i+1, right);
	
		return new_node;
	}
};
