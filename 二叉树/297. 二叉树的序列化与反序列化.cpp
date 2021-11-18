class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
		string res;
		helper0(res, root);
		
		return res; 
    }
	
	void helper0(string &res, TreeNode *root) {
		if (root == NULL) {
			res += "#,"; 
			return ;
		}
		
		res += to_string(root->val) + ",";
		helper0(res, root->left);
		helper0(res, root->right);
	}
	
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string res) {
    	list<string> str_list;
    	string str;
    	for (auto& ch: res) {
    		if (ch == ',') {
    			str_list.push_back(str);
    			str.clear();
			} else {
				str.push_back(ch);
			}
		}
    	
    	return helper1(str_list);
    }
    
    TreeNode *helper1(list<string> &str_list) {
    	if (str_list.front() == "#") {
    		str_list.pop_front();
    		return NULL;
		}
		
		auto root = new TreeNode(stoi(str_list.front()));	
		
		str_list.pop_front();
		
		root->left = helper1(str_list);
		root->right = helper1(str_list);
		
		return root;
	}
};


class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
		string res;
		queue<TreeNode *> q;
		q.push(root);
		TreeNode *cur_node;
		while(!q.empty()) {
			cur_node = q.front();
			q.pop();
			if (cur_node == NULL) {
				res += "#,";
				continue;
			} else {
				res += to_string(cur_node->val) + ",";
				q.push(cur_node->left);
				q.push(cur_node->right);
			}		
		}
		
		return res; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string res) {
    	list<string> str_list;
    	string str;
    	for (auto& ch: res) {
    		if (ch == ',') {
    			str_list.push_back(str);
    			str.clear();
			} else {
				str.push_back(ch);
			}
		}
    	return helper(str_list);
    }
    
    TreeNode *helper(list<string> &str_list) {
    	if (str_list.front() == "#")
    		return NULL;
		
		TreeNode* root = new TreeNode(stoi(str_list.front()));
		str_list.pop_front();
    	queue<TreeNode*> q;
    	q.push(root);
    	
    	TreeNode *cur_node; 
    	while(!q.empty()) {
    		cur_node = q.front();
    		q.pop();
    		
    		if (str_list.front() == "#") {
    			cur_node->left = NULL;
			} else {
				cur_node->left = new TreeNode(stoi(str_list.front()));
				q.push(cur_node->left);
			}
    		str_list.pop_front();
    		
    		if (str_list.front() == "#") {
    			cur_node->right = NULL;
			} else {
				cur_node->right = new TreeNode(stoi(str_list.front()));
				q.push(cur_node->right);
			}
			str_list.pop_front();
		}
        return root;
	}
};

