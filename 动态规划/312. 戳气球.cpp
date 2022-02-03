class Solution {
public:
    int maxCoins(vector<int>& nums) {
		int n = nums.size();
		vector<int> points(n+2);
		points[0] = points[n+1] = 1;
		for (int i = 0; i < n; ++i)
			points[i+1] = nums[i];
		
		vector<vector<int>> dp(n+2, vector<int>(n+2));
		for (int i = n; i >= 0; --i) {
			for (int j = i+1; j <= n+1; ++j) {
				for (int k = i+1; k < j; ++k) {
					dp[i][j] = max(dp[i][j], dp[i][k]+dp[k][j]+points[i]*points[k]*points[j]);
				}
			}
		} 
		return dp[0][n+1];
    }	
};
