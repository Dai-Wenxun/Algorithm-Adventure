class Solution {
public:
    bool canPartition(vector<int>& nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2 == 1)
			return false;
			
		sum = sum / 2;
		
		int sz = nums.size();
		vector<bool> dp(sum+1, false);
		
		dp[0] = true;
		for (int i = 1; i <= sz; ++i) {
			for (int j = sum; j >= 1; --j) {
				if (j - nums[i-1] >= 0)
					dp[j] = dp[j] | dp[j-nums[i-1]];
			}
		}
		return dp[sum]; 
    }
};
