class Solution {
public:
    string longestPalindrome(string s) {
    	int sz = s.size();
    	string res;
		for (int i = 0; i < s.size(); ++i) {
			auto s1 = Palindrome(s, i, i);
			auto s2 = Palindrome(s, i, i+1);
			
			res = res.size() > s1.size() ? res : s1;
			res = res.size() > s2.size() ? res : s2; 
		}
		return res;
    }
    
    string Palindrome(string& s, int l, int r) {
    	while (l >= 0 && r < s.size() && s[l] == s[r]) {
    		l--;
    		r++;
		}
		return s.substr(l+1, r-l-1);
	}
};


