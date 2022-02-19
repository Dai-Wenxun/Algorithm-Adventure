class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
		int sz = SZ(arr);
		vector<int> res;
		
		per(i, sz, 1) {
			int l = max_element(arr.begin(), arr.begin() + i) - arr.begin() + 1;
			reverse(arr.begin(), arr.begin() + l);
			reverse(arr.begin(), arr.begin() + i);
			
			res.pb(l);
			res.pb(i);
		}
		return res;
    }
};
