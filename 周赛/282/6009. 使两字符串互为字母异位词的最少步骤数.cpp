class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> ss(26), tt(26);
		int s_size = SZ(s), t_size = SZ(t);
		rep(i, 0, s_size-1) ss[s[i] - 'a']++;
		rep(i, 0, t_size-1) tt[t[i] - 'a']++;
		
		int res = 0;
		rep(i, 0, 25) {
			res += abs(ss[i] - tt[i]);
		} 
		return res;
    }
};
