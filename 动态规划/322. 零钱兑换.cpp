class Solution {
public:
	vector<int> dp;
    int coinChange(vector<int>& coins, int amount) {
		dp.resize(amount+1, amount + 1);
		int sz = dp.size(); 
		
		dp[0] = 0;
		for (int i = 1; i < sz; ++i) {
			for (auto coin: coins) {
				if (i - coin < 0)
					continue;
				dp[i] = min(dp[i-coin] + 1, dp[i]);	
			}
		}
		return dp[amount] == amount+1 ? -1 : dp[amount];
    }
    
//    unordered_map<int, int> mp;
//    int dp(vector<int>& coins, int amount) {
//    	if (amount < 0) return -1;
//    	if (amount == 0) return 0;
//    	
//    	if (mp[amount] != -2)
//    		return mp[amount];
//    	
//    	int res = INT_MAX;
//    	for (auto coin: coins) {
//    		int subp = dp(coins, amount-coin);
//    		if (subp == -1) continue;
//    		
//    		res = min(res, subp+1);
//		}
//		
//		mp[amount] = res == INT_MAX ? -1 : res;
//		
//		return mp[amount];
//	}
};
