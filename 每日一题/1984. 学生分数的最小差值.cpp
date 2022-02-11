class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int l = 0, r = k-1;
		int sz = nums.size();
		int res = INT_MAX;
		while (r <= sz-1) {
			res = min(res, nums[r] - nums[l]);
			l++, r++;
		}
		return res;
    }
};
