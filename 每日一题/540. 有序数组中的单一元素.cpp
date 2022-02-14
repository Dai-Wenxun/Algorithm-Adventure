class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {	
		int l = 0, r = SZ(nums) - 1;
		
		while (l < r) {
			int mid = (l + r) >> 1;
			mid -= mid & 1;
			if (nums[mid] == nums[mid+1]) l = mid+2;
			else r = mid;
		}
		return nums[l];
    }
};


