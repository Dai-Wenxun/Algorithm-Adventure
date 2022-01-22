class Solution {
public:
    int change(int amount, vector<int>& coins) {
		int sz = coins.size();
		
		vector<vector<int>> dp(sz+1, vector<int>(amount+1, 0));
		
		for (int i = 0; i <= sz; ++i)
			dp[i][0] = 1;
				
		for (int i = 1; i <= sz; ++i) {
			for (int j = 1; j <= amount; ++j) {
				if (j - coins[i-1] < 0)
					dp[i][j] = dp[i-1][j];
				else
					dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
			}
		}
		return dp[sz][amount];
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
		int sz = coins.size();
		
		vector<int> dp(amount+1, 0);
		
		dp[0] = 1;		
		for (int i = 1; i <= sz; ++i) {
			for (int j = 1; j <= amount; ++j) {
				if (j - coins[i-1] >= 0)
					dp[j] = dp[j] + dp[j-coins[i-1]];
			}
		}
		return dp[amount];
    }
};


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int& coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};

