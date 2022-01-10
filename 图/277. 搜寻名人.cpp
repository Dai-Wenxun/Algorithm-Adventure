bool knows(int a, int b);
class Solution {
public:
    int findCelebrity(int n) {
		vector<int> ind(n);
		vector<int> outd(n);
		
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (knows(i, j)) {
					++ind[j];
					++outd[i]; 
				}
			}
		}
		
		for (int i = 0; i < n; ++i) {
			if (ind[i] == n && outd[i] == 1)
				return i;
		}
    	return -1;
	}
};

class Solution {
public:
    int findCelebrity(int n) {
		int cand = 0;
		for (int other = 1; other < n; ++other){
			if (knows(cand, other) || !knows(other, cand))
				cand = ohter;	 
		}
		for (int i = 0; i < n; ++i) {
			if (cand == i)
				continue;
			if (knows(cand, i) || !knows(i, cand))
				return -1;
		}
		return res;
	}
    
};
