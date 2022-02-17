class Solution {
public:
	int d[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}}; 
    int sz;
    vector<vector<vector<double>>> memo{30, vector<vector<double>>(30, vector<double>(101, -6666))};
	double knightProbability(int n, int k, int row, int column) {
		sz = n;
		return dfs(row, column, k);
    }
    
    double dfs(int r, int c, int k) {
		if (k == 0)
			return 1.0;
		
		if (memo[r][c][k] != -6666)
			return memo[r][c][k];
		
		double s = 0;
		rep(i, 0, 7) {
    		int x = r + d[i][0];
    		int y = c + d[i][1];
    		if (x >= sz || x < 0 || y >= sz || y < 0)
    			continue;
    		
    		if (memo[x][y][k] != -6666)
    			s += memo[x][y][k];
    		else
    			s += 0.125 * dfs(x, y, k-1);
    			
//    		cout << s << " " << x << " " << y << endl;
    		
		}
		memo[r][c][k] = s;
		return s;
	}
};
