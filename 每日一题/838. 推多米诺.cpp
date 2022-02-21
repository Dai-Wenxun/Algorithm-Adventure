class Solution {
public:
    string pushDominoes(string dms) {
		int prev, cur;
		int sz = dms.size();
		prev = 0;
		cur = 1;
		
		while (1) {
			while (cur < sz && dms[cur] == '.') cur++;
			if (cur == sz) {
				if (dms[prev] == 'R') rep(k, prev+1, sz-1) dms[k] = 'R';
				break;
			}
			
			if (dms[cur] == 'L') {
				if (dms[prev] == '.') {
					rep(k, prev, cur-1) dms[k] = 'L';
				} else if (dms[prev] == 'L') {
					rep(k, prev+1, cur-1) dms[k] = 'L';
				} else if (dms[prev] == 'R') {
					int mid = cur - prev;
					if (mid&1) mid = mid >> 1;
					else mid = (mid >> 1) - 1;
					rep(k, prev+1, prev+mid) dms[k] = 'R';
					per(k, cur-1, cur-mid) dms[k] = 'L';
				}
			} else {
				if (dms[prev] == 'R') {
					rep(k, prev+1, cur-1) dms[k] = 'R';
				}
			}
			
			prev = cur;
			cur++;
//			cout << dms << endl;
		}
		
		return dms; 
    }
};
