class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        vector<int> dp(1 << (2 * numSlots), INT_MIN);
        int sz = nums.size();
		dp[0] = 0;
        rep(i, 1, (1 << (2 * numSlots)) - 1) {
        	int c = __builtin_popcount(i) - 1;
        	if (c >= sz) continue;
        	rep(j, 0, 2 * numSlots - 1) {
        		if (i & (1 << j)) {
        			dp[i] = max(dp[i], dp[i ^ (1 << j)] + (nums[c] & (j / 2 + 1)));
				}
			}
		}
		
		int mx = INT_MIN;
		rep(i, 0, (1 << (2 * numSlots)) - 1) {
			if (__builtin_popcount(i) == sz)
				mx = max(mx, dp[i]);
		}
        return mx;
    }
};
