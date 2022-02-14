class Solution {
public:
    int maxNumberOfBalloons(string text) {
		vector<int> mp(26);
		for (auto& c: text) {
			mp[c-'a']++;
		}
		string tgt = "balloon"; 
		int res = 2e9;
		for (auto& c: tgt) {
			if (c == 'l' || c == 'o')
				res = min(res, mp[c-'a']/2); 
			else
				res = min(res, mp[c-'a']);
		}
		return res;
    }
};
