class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
		return traverse(0, nums.size()-1, nums);
    }
    
    TreeNode *traverse(int l, int r, vector<int>& nums) {
    	if (l > r)
    		return NULL;
    	
    	int mid = (l+r)>>1;
    	TreeNode *root = new TreeNode(nums[mid]);
    	root->left = traverse(l, mid-1, nums);
    	root->right = traverse(mid+1, r, nums);
    	
    	return root;
	}
};
