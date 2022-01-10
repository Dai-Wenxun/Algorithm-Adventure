class UF {
public:
	vector<int> fa;
	vector<int> size;
	UF(int n) {
		fa.resize(n);
		size.resize(n, 1);
		for (int i = 0; i < n; ++i) 
			fa[i] = i;
	}
	
	bool isconnect(int p, int q) {
		return find(p) == find(q); 
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
		
		if (rootP == rootQ) return ;
		
		if (size[rootP] > size[rootQ]) {
			fa[rootQ] = rootP;
		} else {
			fa[rootP] = rootQ;
		}
	}
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
         UF uf = UF(26);
         for (auto& str: equations) {
         	if (str[1] == '=') {
         		uf.unite(str[0]-'a', str[3]-'a');
			 }
		 }
         for (auto& str: equations) {
         	if (str[1] == '!' && uf.isconnect(str[0]-'a', str[3]-'a')) {
         		return false;
			 }
		 }
		 return true;
    }
};
