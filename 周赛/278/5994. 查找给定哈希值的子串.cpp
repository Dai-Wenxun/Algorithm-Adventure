typedef long long ll;
class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int index = s.size() - k;
		ll p = 1, h = 0;
        for (int i = 0; i < k; ++i) {
        	h = (h + (s[index+i] - 'a' + 1) * p) % modulo;
			p = (p * power) % modulo;
		}
		int ans = -1;
		if (h == hashValue) ans = index; 
		for (int i = index-1; i >= 0; --i) {
			h = (h * power + modulo - (s[i+k]-'a'+1)*p % modulo + (s[i] - 'a' + 1)) % modulo;
			if (h == hashValue) ans = i;
		}
		return s.substr(ans, k);
    }
};
