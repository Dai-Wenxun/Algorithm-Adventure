class Solution {
public:
	int m, n;
	int d[5] = {-1, 0, 1, 0, -1};
    int numEnclaves(vector<vector<int>>& grid) {
		m = grid.size();
		n = grid[0].size();
		
		rep(i, 0, m-1) dfs(i, 0, grid), dfs(i, n-1, grid);
		rep(j, 0, n-1) dfs(0, j, grid), dfs(m-1, j, grid);		
		
		int res = 0;
		rep(i, 0, m-1) rep(j, 0, n-1) if (grid[i][j] == 1) res++;
		return res;
    }
    
    
    void dfs(int i, int j, vector<vector<int>>& grid) {
    	if (grid[i][j] == 1) grid[i][j] = 0;
    	else return ;
    	
		rep(idx, 0, 3) {
    		int x = i + d[idx];
    		int y = j + d[idx+1];
    		if (x >= m || x < 0 || y >= n || y < 0)
    			continue;
    		
    		dfs(x, y, grid);
		}
	} 
};

