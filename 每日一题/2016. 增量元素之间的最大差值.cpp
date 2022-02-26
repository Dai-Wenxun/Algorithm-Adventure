class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mx = INT_MIN, mn = nums[0];
        int sz = SZ(nums);
		rep(i, 1, sz-1) {
			mx = max(mx, nums[i] - mn);
			mn = min(mn, nums[i]);
		}
		
		return mx <= 0 ? -1 : mx;
    }
};
