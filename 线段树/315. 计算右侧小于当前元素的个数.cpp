class Solution {
public:
	vector<int> sum;
    vector<int> countSmaller(vector<int>& nums) {
		set<int> s(nums.begin(), nums.end());
		
		int idx = 0;		
		unordered_map<int, int> mp;
		for (auto val: s)
			mp[val] = idx++;
		
		sum.resize(4*idx);
		
		int n = nums.size();
		vector<int> ans(n);

		update(0, 0, idx-1, mp[nums[n-1]]);
		ans[n-1] = 0;
		
		for (int i = n-2; i >= 0; --i) {
			ans[i] = query(0, 0, idx-1, 0, mp[nums[i]]-1);
			
			update(0, 0, idx-1, mp[nums[i]]);
		}
		
		for (int i = 0; i < ans.size(); ++i)
			cout << ans[i] << endl;
		
		return ans;
    }
    
    void update(int p, int lc, int rc, int idx) {
    	if (lc == rc) {
    		sum[p] ++;
    		return ;
		}
		
		int mid = (lc + rc) >> 1;
		
		if (idx <= mid)
			update(2*p+1, lc, mid, idx);
		if (idx >= mid+1)
			update(2*p+2, mid+1, rc, idx);
		
		sum[p] = sum[2*p+1] + sum[2*p+2];
	}

    int query(int p, int lc, int rc, int ls, int rs) {
		if (lc >= ls && rc <= rs) {
			return sum[p];
		}
		
		if (rs < lc || ls > rc) {
			return 0;
		}
		int mid = (lc + rc) >> 1;
		return query(2*p+1, lc, mid, ls, rs) + query(2*p+2, mid+1, rc, ls, rs);
	}
};
