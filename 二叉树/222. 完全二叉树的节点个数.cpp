class Solution {
public:
    int countNodes(TreeNode* root) {
    	if (root == NULL)
    		return 0;
    	
		TreeNode *l = root, *r = root;
		
		int hl = 0, hr = 0;
		while(l != NULL) {
			l = l->left;
			hl++;
		}
		
		while(r != NULL) {
			r = r->right;
			hr++;
		}
		
		if (hl == hr)
			return (int)(pow(2, hl) - 1);
		
		return 1 + countNodes(root->left) + countNodes(root->right); 
    }
};
