class Solution {
public:
	TreeNode *front = NULL;
	TreeNode *back = NULL;
	TreeNode *pred = new TreeNode(0x80000000);
	void recoverTree(TreeNode* root) {
		inorder(root);
		
		int tmp = front->val;
		front->val = back->val;
		back->val = tmp;
    }
    
    void inorder(TreeNode *root) {
    	if (root == NULL)
    		return ;
    		
    	inorder(root->left);
    	
    	if (pred->val > root->val) {
    		if (front == NULL)
    			front = pred;
			back = root;
		}    	
    	pred = root;

    	inorder(root->right);
	}
};
