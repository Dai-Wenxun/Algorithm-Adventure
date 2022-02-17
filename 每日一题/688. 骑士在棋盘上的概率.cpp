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
    		
    		if (memo[x][y][k-1] != -6666)
    			s += memo[x][y][k-1] / 8;
    		else
    			s += 0.125 * dfs(x, y, k-1);
    			
//    		cout << s << " " << x << " " << y << endl;
    		
		}
		memo[r][c][k] = s;
		return s;
	}
};

class Solution {
public:
	int d[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}}; 
	double knightProbability(int n, int k, int row, int column) {
		vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k+1))};
		rep(i, 0, n-1) rep(j, 0, n-1) dp[i][j][0] = 1;
		
		rep(p, 1, k) rep(i, 0, n-1) rep(j, 0, n-1) rep(index, 0, 7) {
			int x = i + d[index][0];
    		int y = j + d[index][1];
    		if (x >= sz || x < 0 || y >= sz || y < 0)
    			continue;
    		
    		dp[i][j][p] += dp[x][y][p-1] / 8;
		}
		
		return dp[row][column][k];
    }
};
