class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
		int sz1 = text1.size();
		int sz2 = text2.size();
		
		vector<vector<int>> dp(sz1, vector<int>(sz2, 0));
		
		for (int i = 0; i < sz1; ++i)
			if (text1[i] == text2[0] || (i != 0 && dp[i-1][0] == 1))
				dp[i][0] = 1;
		for (int j = 0; j < sz2; ++j)
			if (text1[0] == text2[j] || (j != 0 && dp[0][j-1] == 1))    
				dp[0][j] = 1; 

    	for (int i = 1; i < sz1; ++i) {
    		for (int j = 1; j < sz2; ++j) {
    			if (text1[i] == text2[j]) {
    				dp[i][j] = dp[i-1][j-1] + 1;
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
    	return dp[sz1-1][sz2-1];
	}
};
