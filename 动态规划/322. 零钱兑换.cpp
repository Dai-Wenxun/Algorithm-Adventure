class Solution {
public: 
	unordered_map<int, int> mp;
    int coinChange(vector<int>& coins, int amount) {
    	return dp(coins, amount);  
    }
    
    int dp(vector<int>& coins, int amount) {
    	if (amount == 0) return 0;
    	if (amount < 0) return -1;
    	
    	auto it = mp.find(amount);
		if (it != mp.end()) 
			return it->second;

		int res = INT_MAX;
    	for (auto m: coins) {
			int subProblem = dp(coins, amount-m);
			if (subProblem == -1) continue;

    		res = min(res, subProblem+1);
		}
		
		mp[amount] = res == INT_MAX ? -1 : res;
		return mp[amount];
	}
};
