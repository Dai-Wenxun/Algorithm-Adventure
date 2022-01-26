class Solution {
public:
    int findRotateSteps(string ring, string key) {
		vector<vector<int>> pos(26);	
		
		for (int i = 0 ; i < ring.size(); ++i)
			pos[ring[i] - 'a'].push_back(i);
		
		
		int m = key.size();
		int n = ring.size();
		
		vector<vector<int>> dp(m, vector<int>(n, 10000));
		
		
		for (int p: pos[key[0]-'a'])
			dp[0][p] = calc(ring.size(), 0, p) + 1;
			
		
		for (int i = 1; i < m; ++i) {
			for (int j: pos[key[i]-'a']) {
				for (int k: pos[key[i-1]-'a']) {
					dp[i][j] = min(dp[i-1][k] + calc(ring.size(), k, j) + 1, dp[i][j]);
				}
			}
		}
		
		return *min_element(dp.back().begin(), dp.back().end());
    }
    
    int calc(int size, int i, int j) {
		int len = abs(i - j);
		return min(len, size-len);
	}
};
