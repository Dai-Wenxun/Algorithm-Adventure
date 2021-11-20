class Solution {
public:
	TreeNode *front = NULL;
	TreeNode *back = NULL;
	TreeNode *pred = NULL;
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
    	
    	if (pred != NULL && pred->val > root->val) {
    		if (front == NULL)
    			front = pred;
			back = root;
		}    	
    	pred = root;

    	inorder(root->right);
	}
};

class Solution {
public:
    TreeNode *pred, *x, *y, *pre;
    void recoverTree(TreeNode* root) {
        while (root != NULL) {
            if (root->left != NULL) {
                pred = root->left;
                while(pred->right != NULL && pred->right != root) {
                    pred = pred->right;
                }

                if (pred->right == NULL) {
                    pred->right = root;
                    root = root->left;
                } else {
                    pred->right = NULL;
                    if (pre != NULL && pre->val > root->val) {
                        if (x == NULL)
                            x = pre;
                        y = root;
                    }
                    pre = root;
                    root = root->right;
                }
            } else {
                if (pre != NULL && pre->val > root->val) {
                    if (x == NULL)
                        x = pre;
                    y = root;
                }
                pre = root;
                root = root->right;
            }
        }
        swap(x->val, y->val);
    }
};

