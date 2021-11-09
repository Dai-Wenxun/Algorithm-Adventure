class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return *generate(1, n);
    }
    
    vector<TreeNode *> *generate(int lo, int hi) {
    	if (lo > hi)
    		return new vector<TreeNode*>{NULL};
    	
    	auto res = new vector<TreeNode *>(); 
    	
    	for (int i = lo; i <= hi; ++i) {
    		auto left = generate(lo, i-1);
    		auto right = generate(i+1, hi);
    		for (auto root_left: *left) {
    			for (auto root_right: *right) {
    				res->push_back(new TreeNode(i, root_left, root_right));
				}
			}    		
		}
		
		return res;
	}
};
