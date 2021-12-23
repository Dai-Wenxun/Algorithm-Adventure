class Solution {
public:
	vector<bool> path;
	vector<bool> vtd;
	bool hasC = false;
	vector<int> res;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vtd.resize(numCourses);
		path.resize(numCourses);
		
		auto g = bG(numCourses, prerequisites);
		
		for (int i = 0; i < numCourses; ++i) {
			traverse(g, i);
			if (hasC)
				return vector<int>();
		}
		
		reverse(res.begin(), res.end());
		return res;
		
    }
    
    void traverse(vector<vector<int>> &g, int cur) {
    	if (path[cur]) 
    		hasC = true;
    	
		if (vtd[cur] || hasC)
			return ;
		
		vtd[cur] = true;
		path[cur] = true;
		
		for (int i: g[cur]) {
			traverse(g, i);
		}		
		res.push_back(cur);
		path[cur] = false;
	}
    
    vector<vector<int>> bG(int n, vector<vector<int>>& prs) {
    	vector<vector<int>> g(n);
		
		for (auto e: prs) {
			int from = e[1];
			int to = e[0];
			g[from].push_back(to);
		}
		    	
		return g;
	} 
    
};

