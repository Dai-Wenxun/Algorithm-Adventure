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

