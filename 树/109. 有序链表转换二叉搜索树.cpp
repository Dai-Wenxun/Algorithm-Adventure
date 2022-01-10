class Solution {
public:
	ListNode *head;
    TreeNode* sortedListToBST(ListNode* head) {
		int len = 0;
		this->head = head;
		while(head != NULL) {
			len++;
			head = head->next;
		} 

		
		return traverse(0, len-1);
    }
    
    TreeNode *traverse(int l, int r) {
    	if (l > r)
    		return NULL;
    	
    	int mid = (l+r) >> 1;
    	TreeNode *root = new TreeNode();
    	root->left = traverse(l, mid-1);
    	root->val = head->val;
		head = head->next;
		root->right = traverse(mid+1, r);
		
		return root;	 
	} 
};
