class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
		vector<int> ind(n+1);
		vector<int> outd(n+1);
    	
    	for (auto& e: trust) {
    		++ind[e[1]];
    		++outd[e[0]];
		}
		
		for (int i = 1; i <= n; ++i) {
			if (ind[i] == n-1 && outd[i] == 0)
				return i;
		}		    	
		return -1;
    }
};
