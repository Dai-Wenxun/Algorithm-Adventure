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

class Solution {
public:	
	int gcd(int a, int b) { // 欧几里得算法
	    return b == 0 ? a : gcd(b, a % b);
	}
    vector<string> simplifiedFractions(int n) {
		vector<string> res;
		for (int i = 2; i <= n; ++i) {
			for (int j = 1; j <= i-1; ++j) {
				if (gcd(i, j) == 1) res.pb(to_string(i) + '/' + to_string(i));
			}	
		}
		return res;
    }
};
