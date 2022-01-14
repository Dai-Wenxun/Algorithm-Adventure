class Solution {
public:
    int longestPalindrome(string s) {		
		int sz = s.size();
		vector<int> mp(sz, 0);
		
		for (int i = 0; i < sz; ++i) 
			mp[s[i]] += 1;
		
		bool ad = false;
		int res = 0;
		for (auto& p: mp) {
			if (p.second % 2) { 
				res = p.second - 1;
				ad = true;
			} else {
				res += p.second; 
			}
		}
		return ad ? res+1 : res;
    }
};
