class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
		int sz = SZ(nums1);
		vector<int> dp(1 << sz, INT_MAX);
		dp[0] = 0;
		rep(i, 1, (1 << sz) - 1) {
			int c = __builtin_popcount(i) - 1;
			rep(j, 0, sz-1) 
				if (i & (1 << j))
					dp[i] = min(dp[i], dp[i ^ (1 << j)] + (nums1[c] ^ nums2[j]));
		}
		return dp[(1 << sz) - 1];
    }
};
