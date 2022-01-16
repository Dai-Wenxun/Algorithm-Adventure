struct comp {
	bool operator() (vector<int>& v1, vector<int>& v2){
		if (v1[0] != v2[0])
			return v1[0] < v2[0];
		else 
			return v1[1] > v2[1];
	}
};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& es) {
		sort(es.begin(), es.end(), comp());
		
		int sz = es.size();
		vector<int> dp(sz, 1);
		
		int res = 1;
		for (int i = 1; i < sz; ++i) {
			int cur = es[i][1];
			for (int j = 0; j < i; ++j) {
				if (cur > es[j][1]) {
					dp[i] = max(dp[j] + 1, dp[i]);
					res = max(dp[i], res);
				}
			}
		}
		
		return res;
    }
};
