class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int sz = SZ(nums);
		
		if (sz == 1) return to_string(nums[0]);
		if (sz == 2) return to_string(nums[0]) + '/' + to_string(nums[1]);
		
		string res = to_string(nums[0]) + '/' + '(';
		rep(i, 1, sz-1) {
			res += to_string(nums[i]) + '/';
		}
		
		res.back() = ')';
		return res;
    }
};
