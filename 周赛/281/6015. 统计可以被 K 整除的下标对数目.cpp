class Solution {
public:
    long long coutPairs(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
		vector<int> cnt(mx+1), s(mx+1);
		for (int num: nums) cnt[num]++;
		rep(i, 1, mx) for (int j = i; j <= mx; j += i) s[i] += cnt[j];
		ll res = 0;
		rep(i, 1, mx) {
			int x = k / gcd(i, k);
			if (x <= mx) res += cnt[i] * s[x];
		}
		rep(i, 1, mx) {
			if ((ll) i * i % k == 0)
				res -= cnt[i];
		}
		return res / 2;
    }
};
