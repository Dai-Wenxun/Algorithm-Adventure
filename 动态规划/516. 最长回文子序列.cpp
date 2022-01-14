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

class Solution {
public:
    int longestPalindromeSubseq(string s) {
		int sz = s.size();
		vector<vector<int>> dp(sz, vector<int>(sz, 0));
		
		for (int i = 0; i < sz; ++i)
			if (s[i] == s[sz-1] || (i > 0 && dp[i-1][0]))
				dp[i][0] = 1;
		
		for (int j = 0; j < sz; ++j)
			if (s[0] == s[sz-1-j] || (j > 0 && dp[0][j-1]))
				dp[0][j] = 1;
		
		for (int i = 1; i < sz; ++i) {
			for (int j = 1; j < sz; ++j) {
				if (s[i] == s[sz-j-1]) {
					dp[i][j] = dp[i-1][j-1] + 1;
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		return dp[sz-1][sz-1];
    }
}; 
