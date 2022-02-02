class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(2, vector<int>(n + 1, INT_MAX));
        dp[0][0] = 0; dp[1][0] = 0;
        
        for (int j = 0; j <= n; ++j)
            dp[0][j] = j;
		
		for (int i = 1 ; i < k; ++i) {
			for (int j = 1; j <= n; ++j) {
				
				int lo = 1, hi = j;
				int res = INT_MAX;
				while (lo <= hi) {
					int mid = (lo + hi) / 2;
					int broken = dp[(i-1)&1][mid-1];
					int not_broken = dp[i&1][j-mid];
					
					if (broken > not_broken) {
						hi = mid - 1;
						res = min(res, broken+1);
					} else {
						lo = mid + 1;
						res = min(res, not_broken+1); 
					}
				}
				dp[i&1][j] = res;
        	}
		}

        return dp[(k-1)&1][n];
    }
};
