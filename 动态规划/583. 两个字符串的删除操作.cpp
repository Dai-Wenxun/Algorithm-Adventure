class Solution {
public:
    int minDistance(string word1, string word2) {
		int sz1 = word1.size();
		int sz2 = word2.size();
		
		if (sz1 == 0) return sz2;
		if (sz2 == 0) return sz1;
		
		vector<vector<int>> dp(sz1, vector<int>(sz2, 0));
		
		for (int i = 0; i < sz1; ++i)
			if (word1[i] == word2[0] || (i > 0 && dp[i-1][0]))
				dp[i][0] = 1;
		for (int j = 0; j < sz2; ++j)
			if (word1[0] == word2[j] || (j > 0 && dp[0][j-1]))
				dp[0][j] = 1;		
		
		for (int i = 1; i < sz1; ++i) {
			for (int j = 1; j < sz2; ++j) {
				if (word1[i] == word2[j]) {
					dp[i][j]  = dp[i-1][j-1] + 1;
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}	
			}
		}		
		return sz1 + sz2 - 2 * dp[sz1-1][sz2-1];
    }
};
