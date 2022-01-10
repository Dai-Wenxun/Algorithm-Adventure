class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
        	return NULL;
        if (root == p || root == q)
			return root;
        
        TreeNode *left = lowestCommonAncestor(root->left, p, q); 
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
		

		if (left != NULL && right != NULL)
			return root;
		if (left != NULL)
			return left;
		if (right != NULL)
			return right; 
		return NULL;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans = root;
        int q_val = q->val;
  		int p_val = p->val;
		        
        while (true) {
        	if (ans->val > q_val && ans->val > p_val)
        		ans = ans->left;
			else if (ans->val < q_val && ans->val < p_val)
				ans = ans->right;
			else 
				break;
		}
		
		return ans;
    }
};
