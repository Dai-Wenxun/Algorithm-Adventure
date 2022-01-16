class Solution {
public:
    int minDistance(string word1, string word2) {
		int sz1 = word1.size();
		int sz2 = word2.size();
		
		if (sz1 == 0) return sz2;
		if (sz2 == 0) return sz1;
		
		vector<int> dp(sz2, 0);
		
		for (int j = 0; j < sz2; ++j)
			if (word1[0] == word2[j] || (j > 0 && dp[j-1]))
				dp[j] = 1;		
		
		int left = dp[0]; 
		for (int i = 1; i < sz1; ++i) {
			int pre = dp[0];
			if (word1[i] == word2[0] || dp[0])
				dp[0] = 1;
			else
				dp[0] = 0;
			
			left = dp[0];
			
			for (int j = 1; j < sz2; ++j) {
				int tmp = dp[j];
				
				if (word1[i] == word2[j]) {
					dp[j]  = pre + 1;
				} else {
					dp[j] = max(dp[j], left);
				}
				left = dp[j];
				pre = tmp;	
			}
		}		
		return sz1 + sz2 - 2 * dp[sz2-1];
    }
};
