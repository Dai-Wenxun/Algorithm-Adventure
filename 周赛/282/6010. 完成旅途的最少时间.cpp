class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        ll l = 0, r = (ll)time[0] * totalTrips; 
    
		while (l < r) {
			ll mid = l + (r - l) / 2;
			ll cnt = 0;
			for(int t: time) {
				if (mid < t) break;
				cnt += mid / t;
			}
			if (cnt >= totalTrips) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		return l;
	}
};
