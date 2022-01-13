class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		int max = 1;
		int sz = nums.size();
		vector<int> dp(sz, 1);
		
		dp[0] = 1;
		for (int i = 1; i < sz; ++i) {
			int cur = nums[i];
			for (int j = 0; j < i; ++j) {
				if (cur > nums[j]) {
					dp[i] = max(dp[i], dp[j]+1);
				}
			} 
		}
		
		return *max_element(dp.begin(), dp.end());
    }
};
