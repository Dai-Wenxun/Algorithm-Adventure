class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int sz = nums.size();
		vector<int> dp(nums.begin(), nums.end());
		
		for (int i = 1; i < sz; ++i) 
			if (dp[i-1] + dp[i] > nums[i])
				dp[i] = dp[i-1] + dp[i];
	    	
    	return *max_element(dp.begin(), dp.end());
	}
};
