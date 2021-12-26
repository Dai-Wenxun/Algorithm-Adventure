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

class Comp {
public:
	bool operator() (vector<int>& x, vector<int>& y) {
		return x[2] < y[2];
	}
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
		int n = points.size();
		UF uf = UF(n);
		
		vector<vector<int>> g;
		for (int i = 0; i < points.size(); ++i) {
			for (int j = i + 1; j < points.size(); ++j) {
				int cost_x = abs(points[i][0] - points[j][0]);
				int cost_y = abs(points[i][1] - points[j][1]);
				g.push_back(vector<int>{i, j, cost_x+cost_y});
			}
		}
		sort(g.begin(), g.end(), [](vector<int>& x, vector<int>& y) -> bool {return x[2] < y[2];});
		
		int cost = 0;
		for (auto& e: g) {
			if (uf.isconnect(e[0], e[1]))
				continue;
			 uf.unite(e[0], e[1]);
			 cost += e[2];
		}
		return uf.count == 1 ? cost : -1;
    }
};

