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
    int minimumCost(int N, vector<vector<int>>& connections) {
		UF uf = UF(N);
		sort(connections.begin(), connections.end(), Comp());
		
		int cost = 0;
		for (auto& e: connections) {
			if (uf.isconnect(e[0]-1, e[1]-1))
				continue;
			 uf.unite(e[0]-1, e[1]-1);
			 cost += e[2];
		}
		return uf.count == 1 ? cost : -1;
    }
};

