#define pb push_back
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
		int sz = nums.size();
		int res_r = 0, res_l = 0;
		for (int i = 0; i < sz; ++i)
			if (nums[i] == 1)
				res_r++;
		
		int res = res_r;
		vector<int> cands{res};
		for (int i = 1; i <= sz; ++i) {
			if (nums[i-1] == 0)
				res_l += 1;
			else 
				res_r -= 1;
			
			int cur_res = res_r+res_l;
			cands.pb(cur_res);
			res = max(cur_res, res);
		}
		
		vector<int> rts; 
		for (int i = 0; i <= sz; ++i) {
			if (cands[i] == res)
				rts.pb(i);
		}
		return rts;
    }
};
