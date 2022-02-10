class Solution {
public:	
	unordered_map<float, bool> memo;
    vector<string> simplifiedFractions(int n) {
		vector<string> res;
		rep(i, 2, n) {
			rep(j, 1, i-1) {
				if (memo.count(j * 1.0 / i) != 0)
					continue;
				memo[j * 1.0 / i] = true;
				res.pb(to_string(j) + '/' + to_string(i));
			}
		}
		return res;
    }
};
