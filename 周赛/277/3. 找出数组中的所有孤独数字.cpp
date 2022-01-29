class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
    	if (nums.size() == 1)
    		return nums; 
    	
    	sort(nums.begin(), nums.end());
    	vector<int> res;
		int sz = nums.size();
		for (int i = 1; i <= sz-2; ++i) {
			if (nums[i] == nums[i+1] || nums[i] == nums[i-1])
				continue;
			
			if (nums[i-1] != nums[i]-1 && nums[i+1] != nums[i]+1)
				res.push_back(nums[i]);
		} 
		
		if (nums[0]+1 != nums[1] && nums[0] != nums[1])
			res.push_back(nums[0]);
		
		if (nums[sz-1]-1 != nums[sz-2] && nums[sz-1] != nums[sz-2])
			res.push_back(nums[sz-1]);
		
		return res;
    }
};
