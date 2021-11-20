class Solution {
public:
	vector<vector<int>> memo;
    int numTrees(int n) {
    	memo = vector<vector<int>>(n, vector<int>(n));
    	
		return count(0, n-1);
    }
    
    int count(int lo, int hi) {
    	if (lo > hi)
    		return 1;
    	
    	if (memo[lo][hi] != 0)
			return memo[lo][hi]; 
    	
    	int res = 0;
    	for (int i = lo; i <= hi; ++i) {
    		int left = count(lo, i-1);
    		int right = count(i+1, hi);
    		res += left * right;
		}
		
		memo[lo][hi] = res;
		
		return res;
	}
};
