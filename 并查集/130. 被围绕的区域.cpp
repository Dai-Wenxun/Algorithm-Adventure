class Solution {
public:
	
	vector<int> fa;
	int max;
	
    void solve(vector<vector<char>>& board) {
		int r = board.size(), c = board[0].size();
		
		init(r*c+1);
		
		char direction[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
		int x, y;
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				
				if (i == 0 || j == 0 || i == r-1 || j == c-1) {
					unite(i * c + j, max);
				} else {
					if (board[i][j] == 'X')
						continue;
					for (int k = 0; k < 4; ++k) {
						x = i + direction[k][0];
						y = j + direction[k][1];
					
						if (board[x][y] == 'O')	
							unite(x * c + y, i * c + j);
					}
				}
			}
		}
	
		for (int i = 1; i < r; ++i) {
			for (int j = 1; j < c; ++j) {
				if (board[i][j] == 'O' && find(i * c + j)!= find(max)) 
					board[i][j] = 'X';		
			}
		}	
    }
    
    void init(int n) {
    	fa.resize(n);
		max = n-1;
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
    
    void unite(int p, int q) {
    	int rootP = find(p);
		int rootQ = find(q);

    	if (rootQ == rootP)
    		return ;	
    	
    	fa[rootP] = rootQ;
	}
    
};
