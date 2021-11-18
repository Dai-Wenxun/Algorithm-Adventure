class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return helper(nums, 0, nums.size()-1);        
    }
    
    TreeNode *helper(vector<int>& nums, int left, int right) {
    	if (left > right)
    		return NULL;
		
		int max = -1;
    	int index;
    	for (int i = left; i <= right; ++i) {
    		if (nums[i] > max) {
    			max = nums[i];
				index = i;
			}
		}
    	
    	TreeNode *new_node = new TreeNode(max);
    	
    	new_node->left = helper(nums, left, index-1);
    	new_node->right = helper(nums, index+1, right);
    	
    	return new_node;
	}  
};
