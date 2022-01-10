#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	
	TreeNode(): val(0), left(NULL), right(NULL) {}
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class BSTIterator {
public:
	vector<int> nums;
	int idx = -1;
    BSTIterator(TreeNode* root) {
		inorder(root);
    }
    
    void inorder(TreeNode *root) {
		if (root == NULL)
			return ;
		
		inorder(root->left);
		nums.push_back(root->val);
		inorder(root->right);
	}
    
    int next() {
		return nums[++idx];
    }
    
    bool hasNext() {
		if (idx+1 >= nums.size()) {
			return false;
		} 
		return true;
    }
};


TreeNode *build_tree(int l, int r) {
	if (l > r)
		return NULL;
	
	int mid = (l+r) >> 1;
	TreeNode *root = new TreeNode(mid);
	root->left = build_tree(l, mid-1);
	root->right = build_tree(mid+1, r);
	
	return root; 
}

void inorder(TreeNode *root) {
	if (root == NULL)
		return ;
	
	inorder(root->left);
	cout << root->val << endl;
	inorder(root->right);
}


int main() {
	int num;
	cin >> num;
	TreeNode *root = build_tree(0, num-1);
	auto it = BSTIterator(root);
	
	cout << it.hasNext() << endl;
	cout << it.next() << endl;
	cout << it.next() << endl;
	cout << it.next() << endl;
	cout << it.next() << endl;	
	cout << it.next() << endl;
	cout << it.next() << endl;
	cout << it.hasNext() << endl;				
}
