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


class Solution {
public:
    string longestPalindrome(string s) {
    	int sz = s.size();
    	
    	vector<vector<int>> dp(sz, vector<int>(sz, 0));
    	
    	int begin = 0, maxlen = 1;
    	for (int i = 0; i < sz; ++i)
    		dp[i][i] = 1;
    	
		for (int l = 2; l <= sz; ++l) {
			for (int i = 0 ; i <= sz-l; ++i) {	
				int j = l + i - 1;
				
				if (s[i] == s[j]) {
					if (dp[i+1][j-1] || j - i < 3)	
						dp[i][j] = 1;
						
					if (dp[i][j] && j - i + 1> maxlen) {
						begin = i;
						maxlen = j - i + 1;
					}
				} else
					dp[i][j] = 0;
			}
		}
		
		return s.substr(begin, maxlen);
    }
};

