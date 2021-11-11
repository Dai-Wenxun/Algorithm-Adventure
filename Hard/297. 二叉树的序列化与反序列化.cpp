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
