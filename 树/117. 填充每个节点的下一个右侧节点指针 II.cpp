class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
			return NULL;
		Node *cur = root;

		while (cur != NULL) {
			Node *dummy = new Node(-1);
			Node *pre = dummy;
			
			while (cur != NULL) {
				if (cur->left != NULL) {
					pre->next = cur->left;
					pre = pre->next;
				}

				if (cur->right != NULL) {
					pre->next = cur->right;
					pre = pre->next;
				}
				cur = cur->next;
			} 
			
			cur = dummy->next;
		}
		return root;
    }
};
