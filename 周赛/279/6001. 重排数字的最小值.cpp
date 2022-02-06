#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define ll long long

class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0) return 0;
        ll res = 0;
		vector<int> nums;
        int flag = num < 0 ? -1 : 1;
        while (num != 0) {
        	nums.pb(num%10);
        	num /= 10;
		}
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        if (flag == -1) {
        	for (int i = 0; i < sz; ++i) {
        		int cur = nums[i];
        		cout << cur << " " << endl;
        		if (cur == 0) continue;
        		res += nums[i] * (ll)pow(10, sz-1-i);
        		cout << res << " ";
			}
			cout << res;
		} else {
			int see = 0;
			for (int i = 0; i < sz; ++i) {
				int cur = nums[i];
				if (cur == 0) continue;
				if (see == 0) {
						res += nums[i] * (ll)pow(10, sz-1);
						see = 1;
					} else {
						res += nums[i] * (ll)pow(10, sz-1-i);
					}
			}
		}        
//        for (int i = 0; i < nums.size(); ++i)
//        	cout << nums[i] << " ";

    	return res;
    }
};
