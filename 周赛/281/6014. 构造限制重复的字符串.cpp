class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> mp;
        vector<char> v;
		for (char c: s) {
        	if (mp.count(c) == 0)
        		v.pb(c);
			mp[c]++;
		}
		sort(v.begin(), v.end(), greater<char>());
//		printv(v);
		int sz = v.size();
		string res;
		rep(i, 0, sz-1) {
			char c = v[i];
			if (mp[c] == 0)
				continue;
			
			if (mp[c] > repeatLimit) {
				rep(j, 0, repeatLimit-1) res += c;
				mp[c] -= repeatLimit;
				
				int flag = 0;
				rep(j, i+1, sz-1) {
					if (mp[v[j]] != 0) {
						res += v[j];
						mp[v[j]]--;
						flag = 1;
						break;
					}
				}
				i--;
				if (!flag) return res;
			} else {
				rep(j, 0, mp[c]-1) res += c;
			}
		}
		return res;
    }
};
