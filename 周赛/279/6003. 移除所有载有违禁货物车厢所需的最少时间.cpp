#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define SZ(x) ((int)x.size())

class Solution {
public:
    int minimumTime(string s) {
    	int sz = SZ(s);
		vector<int> suf(sz+1);
		per(i, sz-1, 0) suf[i] = s[i] == '0' ? suf[i+1] : min(suf[i+1]+2, sz-i); 
		int ans = suf[0], pre = 0;
		rep(i, 0, sz-1) {
			if (s[i] == '1') {
				pre = min(pre+2, i+1);
				ans = min(ans, pre+suf[i+1]);
			}
		}
		return ans;
    }
};
