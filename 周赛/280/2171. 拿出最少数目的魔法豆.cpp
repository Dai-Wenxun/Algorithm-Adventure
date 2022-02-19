class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
		
		ll sz = SZ(beans);
		ll sum = 0, mx = 0;
		rep(i, 0, sz-1) {
			sum += beans[i];
			ll cur = beans[i] * (sz - i);
			mx = max(mx, cur);
		} 
		
		return sum - mx;
    }
};
