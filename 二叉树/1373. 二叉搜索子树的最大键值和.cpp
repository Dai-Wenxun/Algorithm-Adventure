class Solution {
public:
	int max; 
    int maxSumBST(TreeNode* root) {
		max = 0;
		traverse(root);
		return max;
    }
    
    vector<int> *traverse(TreeNode* root) {
		if (root == NULL)
			return new vector<int>{1, (int)5e4, (int)-5e4, 0};
			
		auto left_res = traverse(root->left);
		auto right_res = traverse(root->right);
		
		auto res = new vector<int>(4);
		if ((*left_res)[0] == 1 && (*right_res)[0] == 1 &&
			root->val > (*left_res)[2] && root->val < (*right_res)[1]) {
			(*res)[0] = 1;
			if (root->left == NULL)
				(*res)[1] = root->val;
			else
				(*res)[1] = (*left_res)[1];
			
			if (root->right == NULL)
				(*res)[2] = root->val;
			else
				(*res)[2] = (*right_res)[2];
				
			(*res)[3] = root->val + (*left_res)[3] + (*right_res)[3];
			
			if ((*res)[3] > max)
				max = (*res)[3];
	
			return res;	
			
		} else {
			return res;
		}
	}
};
