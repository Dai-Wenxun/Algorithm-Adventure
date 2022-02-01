class Solution {
public:
    bool isMatch(string s, string p) {
		int ssz = s.size();
		int psz = p.size();
		
		vector<vector<bool>> dp(ssz+1, vector<bool>(psz+1, false));
		dp[0][0] = true;
		
		for (int i = 1; i <= psz; ++i)
			dp[0][i] = p[i-1] != '*' ? false : dp[0][i-2];
		
		for (int i = 1; i <= ssz; ++i) {
			for (int j = 1; j <= psz; ++j) {
				if (p[j-1] == '*') {					
					if (dp[i][j-2] || (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.')))
						dp[i][j] = true;
					else
						dp[i][j] = false; 
				} else {
					if (p[j-1] == '.' || p[j-1] == s[i-1])
						dp[i][j] = dp[i-1][j-1];
					else
						dp[i][j] = false;
				}
			} 
		}
		return dp[ssz][psz];
    }
};
