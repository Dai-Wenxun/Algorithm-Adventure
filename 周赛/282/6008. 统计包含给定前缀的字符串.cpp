class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        int sz = SZ(pref); 
		for(auto& str: words) if (str.substr(0, sz) == pref) cnt++;
		return cnt;
    }
};
