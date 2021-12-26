class UF {
public:
	vector<int> fa;
	vector<int> size;
	int count;
	UF(int n) {
		count = n;
		fa.resize(n, 0);
		size.resize(n, 1);
		for (int i = 0; i < n; ++i)
			fa[i] = i;
	}
	
	int find(int p) {
		while (fa[p] != p) {
			fa[p] = fa[fa[p]];
			p = fa[p];
		}
		return p;
	}
	
	bool isconnect(int p, int q) {
		return find(p) == find(q);
	}
	
	void unite(int p, int q) {
		int rootP = find(p);
		int rootQ = find(q);
		
		if (rootP == rootQ)	return ;
		
		if (size[rootP] > size[rootQ]) {
			fa[rootQ] = rootP;
		} else {
			fa[rootP] = rootQ;
		}
	 	count--;
	}
}; 

class Solution1 {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
		UF uf = UF(n);
		for (auto& e: edges) {
			if (uf.isconnect(e.first, e.second))
				return false;
			uf.unite(e.first, e.second);
		}
		return uf.count == 1;
    }
};

class Solution1 {
public:
	vector<int> path;
	vectro<int> vtd;
	bool res = true;
    bool validTree(int n, vector<pair<int, int>>& edges) {
		vector<vector<int>> g(n, vector<int>());
		for (auto& e: edges) {
			g[e.first].push_back(e.second);
			g[e.second].push_back(e.first); 
		}
		
		for (int i = 0; i < n; ++i) {
			if (!vtd[i])
				dfs(g, i);
		}
    }
    
    void dfs(vector<vector<int>>& g, int cur) {
    	if (path[cur]) 
    		res = false;	
    	if (vtd[cur] || !res) return ;
    	
    	vtd[cur] = 1;
    	path[cur] = 1;
    	for (int v: g[cur]) {
    		dfs(g, v);
		}
		path[cur] = 0;
	}
};

