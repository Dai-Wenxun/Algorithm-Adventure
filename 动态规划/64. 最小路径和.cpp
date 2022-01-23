typedef pair<int, int> pii;

class Solution {
public:
	int d[5] = {0, 1, 0, -1, 0};
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int sz = m * n;
        vector<int> dists(sz, INT_MAX);
		dists[0] = grid[0][0];
	
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		pq.emplace(grid[0][0], 0);
		
		while (!pq.empty()) {
			auto curP = pq.top(); pq.pop();
			int cur_dist = curP.first;
			int cur_id = curP.second;
			
			if (cur_id == sz - 1)
				return cur_dist;
			if (cur_dist > dists[cur_id])
    			continue;
    
			int cur_x = cur_id / n;
			int cur_y = cur_id % n; 
	
			for (int i = 0; i < 4; ++i) {
				int next_x = cur_x + d[i];
				int next_y = cur_y + d[i+1];
				int next_id = next_x * n + next_y;
				if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n)
					continue;
				int next_dist = dists[cur_id] + grid[next_x][next_y];
				if (dists[next_id] > next_dist) {
					dists[next_id] = next_dist;
					pq.emplace(next_dist, next_id);
				}	
			}
		}
		
        return -1;
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size(); 
		
		vector<vector<int>> dp(m, vector<int>(n));
		
		int sum = 0;
		
		for (int j = 0; j < n; ++j) {
			sum += grid[0][j];
			dp[0][j] = sum;
		}
		
		sum = 0;
		for (int i = 0; i < m; ++i) {
			sum += grid[i][0]; 
			dp[i][0] = sum;
		}
		
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
			}
		}
		
		return dp[m-1][n-1];
    }
};


