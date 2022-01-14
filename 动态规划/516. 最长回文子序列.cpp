class Solution {
public:
    int longestPalindromeSubseq(string s) {
		int sz = s.size();
		
		vector<vector<int>> dp(sz, vector<int>(sz, 0));
		
		for (int i = 0; i < sz; ++i)
			dp[i][i] = 1;
		
		int maxlen = 1;
		for (int l = 2; l <= sz; ++l) {
			for (int i = 0; i <= sz-l; ++i) {
				int j = l + i - 1;
				
				if (s[i] == s[j]) {
					dp[i][j] = dp[i+1][j-1] + 2;
				} else {
					dp[i][j] = max(dp[i+1][j], dp[i][j-1]); 
				}
			}
		}
		
		return dp[0][sz-1];
    }
}; 
