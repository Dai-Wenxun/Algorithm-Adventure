class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int sz = SZ(prices);
		int curMax =0;
		vector<int> res(sz);
		per(i, sz-1, 0) {
			curMax = max(curMax, prices[i]);
			res[i] = curMax == 0 ? 0 : curMax - prices[i];
		}
		
		return *max_element(res.begin(), res.end());
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int sz = SZ(prices);
		vector<vector<int>> dp(sz, vector<int>(2));
		
		dp[0][0] = 0;
		dp[0][1] = -prices[0];
		
		rep(i, 1, sz-1) {
			dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
			dp[i][1] = max(dp[i-1][1], -prices[i]);
		}
		
		return dp[sz-1][0];
    }
};
