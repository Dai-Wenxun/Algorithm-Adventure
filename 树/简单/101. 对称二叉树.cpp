class Solution {
public:
    bool isSymmetric(TreeNode* root) {
		return traverse(root->left, root->right);
    }
    
    bool traverse(TreeNode *p, TreeNode *q) {
    	if (p != NULL && q != NULL) {
    		if (p->val == q->val) 
    			return traverse(p->left, q->right) && 
    					traverse(p->right, q->left);
    		return false;
		} else if (p == NULL && q == NULL) {
			return true;
		} else {
			return false; 
		} 
	} 
};
