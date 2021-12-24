class Solution {
public:
	vector<int> vtd;
	vector<int> color;
	bool res = true;
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
		vtd.resize(n, 0);
		color.resize(n, 0);
		vector<vector<int>> g(n);
		for (auto& e: dislikes) {
			g[e[0]-1].push_back(e[1]-1);
			g[e[1]-1].push_back(e[0]-1);
		}
		
		for (int i = 0; i < n; ++i) {
			if (!vtd[i]) 
				dfs(g, i);
		}
		return res;
    }
    
    void dfs(vector<vector<int>>& g, int cur) {
    	if (!res) return ;
    	vtd[cur] = 1;
    	
    	for (int v: g[cur]) {
    		if (!vtd[v]) {
    			color[v] = !color[cur];
    			dfs(g, v);
			} else {
				if (color[v] == color[cur]) {
					res = false;
					return ;
				}
			}
		}	
	} 
    
};
