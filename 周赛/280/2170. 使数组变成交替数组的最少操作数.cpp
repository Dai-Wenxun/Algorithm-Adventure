class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int sz = SZ(nums);        
        unordered_map<int, int> cnt0_map, cnt1_map;
        rep(i, 0, sz-1) if (i & 1) cnt1_map[nums[i]]++ ; else cnt0_map[nums[i]]++;
        
        auto getMaxCnt = [](unordered_map<int, int>& hash) {
        	vector<pii> arr;
			for (auto& p: hash) 
				arr.eb(p.fi, p.se);
			
			sort(arr.begin(), arr.end(), [](const pii& x, const pii& y) {return x.se > y.se;});
			
			arr.resize(2);
			return arr;
		};
        
		auto cnt0 = getMaxCnt(cnt0_map);
		auto cnt1 = getMaxCnt(cnt1_map);
		
		if (cnt0[0].fi == cnt1[0].fi) {
			return sz - max(cnt0[1].se + cnt1[0].se, cnt0[0].se + cnt1[1].se);
		} else {
			return sz - (cnt0[0].se + cnt1[0].se);
		}
    }
};
