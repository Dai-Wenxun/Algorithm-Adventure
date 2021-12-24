#include <bits/stdc++.h> 
using namespace std;

class UF {
public:
	vector<int> fa;
	vector<int> size;
	int count;
	UF(int n) {
		fa.resize(n);
		size.resize(n);
		count = n;
		for (int i = 0; i < n; ++i) {
			fa[i] = i;
			size[i] = 1;
		}
	}
	
	int find(int p) {
		while (fa[p] != p) {
			fa[p] = fa[fa[p]];
			p = fa[p];
		}
		return p;
	}
	
	void unite(int p, int q) {
		int rootP = find(p);
		int rootQ = find(q);
		
		if (rootQ == rootP) return ;
		
		if (size[rootQ] > size[rootP]){
			fa[rootP] = rootQ;
		}  else {
			fa[rootQ] = rootP;
		}
		--count;
	}
	
	bool isconnect(int p, int q) {
		return find(p) == find(q);
	}	
}; 
