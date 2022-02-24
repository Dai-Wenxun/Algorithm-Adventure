class Solution {
public:
	int m, n;
    vector<int> findBall(vector<vector<int>>& grid) {
		m = SZ(grid);
		n = SZ(grid[0]);
		vector<int> res(n);
		rep(i, 0, n-1) res[i] = dfs(0, i, grid);
		return res;
    }
    
    int dfs(int x, int y, vector<vector<int>>& g) {
    	if (x >= m) 
    		return y;
		if (g[x][y] == 1 && y <= n-2 && g[x][y+1] == 1) return dfs(x+1, y+1, g);
		else if (g[x][y] == -1 && y >= 1 && g[x][y-1] == -1) return dfs(x+1, y-1, g); 
		else return -1;
		
		return -1;	
	}
};
