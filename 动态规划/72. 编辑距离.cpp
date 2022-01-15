class Solution {
public:
	vector<vector<int>> mp;
    int minDistance(string word1, string word2) {
    	mp.resize(word1.size(), vector<int>(word2.size(), 0));
    	
		return dp(word1, word2, word1.size()-1, word2.size()-1);
    }
    
    int dp(string& word1, string& word2, int i, int j) {
    	
    	if (i == -1) return j+1;
    	if (j == -1) return i+1;
		
		if (mp[i][j] != 0)
			return mp[i][j];
	
		if (word1[i] == word2[j])
    		mp[i][j] = dp(word1, word2, i-1, j-1);
    	else 
    		mp[i][j] = min(min(dp(word1, word2, i-1, j) + 1, dp(word1, word2, i, j-1) + 1), dp(word1, word2, i-1, j-1) + 1);	
	
		return mp[i][j];
	}
};

class Solution {
public:
    int minDistance(string word1, string word2) {
		int sz1 = word1.size();
		int sz2 = word2.size();
		
		vector<vector<int>> dp(sz1+1, vector<int>(sz2+1, 0));

		for (int i = 0; i <= sz1; ++i)
			dp[i][0] = i;
		for (int j = 0; j <= sz2; ++j)
			dp[0][j] = j;
			
		for (int i = 1; i <= sz1; ++i) {
			for (int j = 1; j <= sz2; ++j) {
				if (word1[i-1] == word2[j-1]) {
					dp[i][j] = dp[i-1][j-1];
				} else {
					dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
				}
			}
		}
		return dp[sz1][sz2];
    }
};


class Solution {
public:
    int minDistance(string word1, string word2) {
		int sz1 = word1.size();
		int sz2 = word2.size();
		
		vector<int> dp(sz2+1, 0);

		for (int i = 0; i <= sz2; ++i)
			dp[i] = i;
			
		for (int i = 1; i <= sz1; ++i) {
			dp[0] = i;
			int pre = i-1;
			for (int j = 1; j <= sz2; ++j) {
				int tmp = dp[j];
				if (word1[i-1] == word2[j-1]) {
					dp[j] = pre;
				} else {
					dp[j] = min(min(dp[j], dp[j-1]), pre) + 1;
				}
				pre = tmp;
			}

		}
		return dp[sz2];
    }
};
