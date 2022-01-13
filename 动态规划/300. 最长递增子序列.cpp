class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
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

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		int sz = nums.size();
		vector<int> tails(sz, 0);
		int res = 0;
		for (auto num: nums) {
			int i = 0;
			int j = res;
			while (i < j) {
				int m = (i + j) / 2;
				if (tails[m] < num)
					i = m + 1;
				else
					j = m;
			}
			
			tails[i] = num;
			if (j == res)
				res += 1;
		}
		return res;
    }
};
