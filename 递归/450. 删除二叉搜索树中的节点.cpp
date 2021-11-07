class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {	
		if (root == NULL)
			return NULL;

		if (root->val > key)
			root->left =  deleteNode(root->left, key);
		else if (root->val < key)
			root->right = deleteNode(root->right, key);
		else {
			if (root->right == NULL)
				return root->left;
			if (root->left == NULL)
				return root->right;
				
			TreeNode *min = findMin(root->right); 
			root->val = min->val;
			root->right = deleteNode(root->right, min->val);
		}
		return root;
    }
    
    TreeNode *findMin(TreeNode *root) {
    	while (root->left != NULL)
			root = root->left;
		return root;
	}
};
