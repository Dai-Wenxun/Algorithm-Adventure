class Solution {
public:
    bool PredictTheWinner(vector<int>& piles) {
        int sz = SZ(piles);
		vector<vector<int>> dp(sz, vector<int>(sz));
		rep(i, 0, sz-1) dp[i][i] = piles[i];
		per(i, sz-2, 0) 
			rep(j, i+1, sz-1) 
				dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1]);
		
		return dp[0][sz-1] >= 0;
    }
};
