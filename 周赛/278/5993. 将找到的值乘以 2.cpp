class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
		int sz = nums.size();
		vector<int> mp(10001);
		for (auto i: nums)
			mp[i] += 1;
		
		while (1) {
			if (mp[original] != 0)
				original *= 2;
			else 
				break;
		}
		return original;
    }
};
