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


class Solution {
public:
    void solve(vector<vector<char>>& board) {
    	int m = board.size();
    	int n = board[0].size();
    	
		UF uf = UF(m * n + 1);
		
		int dummy = n * m;
		for (int i = 0; i < m; ++i) {
			if (board[i][0] == 'O')
				uf.unite(i * n, dummy);
			if (board[i][n-1] == 'O')
				uf.unite(i * n + n - 1, dummy);
		}
		
		for (int j = 0; j < n; ++j) {
			if (board[0][j] == 'O')
				uf.unite(j, dummy);
			if (board[m-1][j] == 'O')
				uf.unite((m-1) * n + j, dummy);
		}
		
		int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; 
		for (int i = 1; i < m-1; ++i) {
			for (int j = 1; j < n-1; ++j) {
				if (board[i][j] == 'O') {
					for (int k = 0; k < 4; ++k) {
						int x = i + d[k][0];
						int y = j + d[k][1];
						if (board[x][y] == 'O')
							uf.unite(x * n + y, i * n + j);
					}
				}
			}
		}
	
		for (int i = 1; i < m-1; ++i) {
			for (int j = 1; j < n-1; ++j) {
				if (board[i][j] == 'O' && !uf.isconnect(i * n + j, dummy)) 
					board[i][j] = 'X';
			}
		}
    }
};
