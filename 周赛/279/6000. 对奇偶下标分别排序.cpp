#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define ll long long

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> evens, odds, res;
		
		int sz = nums.size();
		for (int i = 0; i < sz; ++i)
		 	if (i % 2 == 0) evens.pb(nums[i]);
    		else odds.pb(nums[i]);
    	
    	sort(evens.begin(), evens.end());
    	sort(odds.begin(), odds.end(), greater<int>());
    	
//    	for (int i = 0; i < evens.size(); ++i)
//    		cout << evens[i] << " ";
//    	
//        for (int i = 0; i < odds.size(); ++i)
//    		cout << odds[i] << " ";
    
    	for (int i = 0; i < sz; ++i)
    		if (i % 2 == 0) res.pb(evens[i/2]);
    		else res.pb(odds[i/2]);
    	
    	return res;
	}		
};
