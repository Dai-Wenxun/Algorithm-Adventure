class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
        	return NULL;	
		connectHelper(root->left, root->right);
		return root;
	}
	
	void connectHelper(Node *node1, Node *node2) {
		if (node1 == NULL) 
			return ;
		node1->next = node2;
		
		
		connectHelper(node1->left, node1->right);
		connectHelper(node1->right, node2->left);
		connectHelper(node2->left, node2->right);
	}	
};
